import RPi.GPIO as GPIO
import time
import pickle
import socket

# Librerias para la lectura de la temperatura
import os
import glob
import sys

os.system('modprobe w1-gpio')     #cargamos los drivers del dispositivo
os.system('modprobe w1-therm')

Carpeta_Sensor = glob.glob( '/sys/bus/w1/devices/' + '28*')[0]

pulsador=3
Amarillo=17
Verde=22
Rojo=27

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(pulsador, GPIO.IN) ## pulsador como entrada
GPIO.setup(Verde, GPIO.OUT) ## led verde como salida
GPIO.setup(Rojo, GPIO.OUT) ## led rojo como salida
GPIO.setup(Amarillo, GPIO.OUT) ## led amarillo como salida

GPIO.output(Verde, False)
GPIO.output(Amarillo, False)
GPIO.output(Rojo, False)

N=100
retardo=3.5
print("Tiempo de muestreo inicial: ",retardo,"segundos.")
Vt=[]
suma=0

fTemp= open('Valores_Temp_Historicos.txt','w+')
fTemp.close()

HEADERSIZE = 10
s = socket.socket()
s.bind(("192.168.43.126", 5000))
s.listen(1)
clientsocket, address = s.accept()

while True:
    fSensor = open(Carpeta_Sensor + '/w1_slave','r')
    linSensor = fSensor.readlines()
    fSensor.close()

    posTemp = linSensor[1].find('t=')
    # Si la posicion es valida
    if posTemp != -1:
        # Anadimos dos posiciones mas por "t="
        strTemp = linSensor[1][posTemp+2:]
        # Calculamos la temperatura real
        temperatura = float(strTemp) / 1000.0

    if len(Vt)==N:
        Vt.append(temperatura)
        suma=suma+Vt[len(Vt)-1]-Vt[0]
        Vt.remove(Vt[0])

    else:
        Vt.append(temperatura)
        suma=suma+Vt[len(Vt)-1]

    prom=suma/len(Vt)
    eventos=len(Vt)/N

    X=5  #porcentaje de variacion
    Vmax=prom*(1+X/100)
    Vmin=prom*(1-X/100)

    if eventos<0.05:
        tendencia="Datos insuficientes, aguarde por favor..."
        GPIO.output(Verde, True) ## Apago el led1
        GPIO.output(Amarillo, True) ## Apago el led2
        GPIO.output(Rojo, True) ## Apago el led3

    else:
        if temperatura>Vmax:
            GPIO.output(Verde, False) ## Apago el led1
            GPIO.output(Rojo, True) ## Enciendo el led2
            GPIO.output(Amarillo, False) ## Apago el led3
            tendencia="Tendencia Alta"

        if temperatura<Vmin:
            GPIO.output(Verde, True) ## Enciendo el led1
            GPIO.output(Rojo, False) ## Apago el led2
            GPIO.output(Amarillo, False) ## Apago el led3
            tendencia="Tendencia Baja"

        if temperatura<=Vmax and temperatura>=Vmin:
            GPIO.output(Verde, False) ## Apago el led1
            GPIO.output(Rojo, False) ## Apago el led2
            GPIO.output(Amarillo, True) ## Prendo el led3
            tendencia="Tendencia Estable"

    fecha=time.ctime(time.time())
    fechaenviar=time.ctime(time.time())
    temperaturaenviar =temperatura
    d = {"time":fechaenviar, "temp": temperaturaenviar}
    msg = pickle.dumps(d)
    msg = bytes(f"{len(msg):<{HEADERSIZE}}", 'utf-8')+msg
    clientsocket.send(msg)

    fTemp= open('Valores_Temp_Historicos.txt','r+')
    fTemp.readlines()
    fTemp.write(fecha)
    fTemp.write("  /  T(actual)=")
    fTemp.write("%.3f" %round(temperatura,3))
    fTemp.write("°C  |  ")
    fTemp.write("T(promedio)=")
    fTemp.write("%.3f" %round(prom,3))
    fTemp.write("°C  /  ")
    fTemp.write(tendencia)
    fTemp.write("\n")
    fTemp.close()

    print(fecha,"  /  T(actual)=","%.3f" %round(temperatura,3),"°C  |  T(promedio)=","%.3f" %round(prom,3),"°C  /  ",tendencia)

    if not GPIO.input(pulsador):
            tinicio=time.time()
            print("""
Actualizando tiempo de ciclo: (Suelte el pulsador para terminar)

    t menor 2,5seg. -> APAGAR EL SISTEMA.
    t entre 2,5 y 10seg. -> Nuevo tiempo de muestreo.
    t mayor 10seg. ->  tmax = 10seg.

            """)

            while not GPIO.input(pulsador):
                tfinal=time.time()
                retardo=tfinal-tinicio
                if retardo>10:
                    retardo=10

                if retardo<2.5 and GPIO.input(pulsador):
                    print("APAGANDO...")

                    GPIO.output(Verde, False)
                    GPIO.output(Amarillo, False)
                    GPIO.output(Rojo, False)

                    GPIO.output(Verde, True)
                    time.sleep(0.5)

                    GPIO.output(Verde, False)
                    GPIO.output(Rojo, True)
                    time.sleep(0.5)

                    GPIO.output(Amarillo, True)
                    GPIO.output(Rojo, False)
                    time.sleep(0.5)

                    GPIO.output(Verde, False)
                    GPIO.output(Amarillo, False)
                    GPIO.output(Rojo, False)

                    sys.exit()

            Vt=[]
            suma=0
            print("Nuevo tiempo de muestro: ","%.3f" %round(retardo,3),"segundos.")

    sleep=time.time()
    while time.time()-sleep<retardo:
        if not GPIO.input(pulsador):
            break
GPIO.cleanup()

s.close()
