def puertas_y_ventanas(p, v):
    puerta = [0.75, 2.00]
    ventana = [1.20, 1.50]
    superficie = p*(puerta[0]*puerta[1]) + v*(ventana[0]*ventana[1])
    return superficie

H = int(input("Ingresar cantidad de habitaciones de la casa: "))
ancho = float(input("Ancho (en metros) = "))
largo = float(input("Largo (en metros) = "))
alto = float(input("alto (en metros) = "))
p = int(input("Ingresar la cantidad de puertas de la casa: "))
v = int(input("Ingresar la cantidad de ventanas de la casa: "))
mano = int(input("Ingresar la cantidad de manos: "))

sup = 2*ancho*alto + 2*largo*alto
total = H*(sup - puertas_y_ventanas(p, v)) #metros cuadrados que hay que pintar
## 14 metros cuadrados por litro de pintura
pintura = round(mano*total/14, 2) #Cantidad de pintura necesaria en litros

n1 = 0
n2 = 0
n3 = 0
n4 = 0
if pintura <= 1:
    n1 = 1
    c = 50
    print("Se necesitan ", n1," latas de 1 litro y el costo es: $", c)
if 1 < pintura < 4:
    n1 = round(pintura)
    c = round(n1*50, 2)
    print("Se necesitan ", n1," latas de 1 litro y el costo es: $", c)
if 4 <= pintura < 10:
    n2 = round(pintura/4)
    c = round(n2*170, 2)
    print("Se necesitan ", n2," latas de 4 litros y el costo es: $", c)
if 10 <= pintura < 20:
    n3 = round(pintura/10)
    c = round(n3*400, 2)
    print("Se necesitan ", n3," latas de 10 litros y el costo es: $", c)
if pintura >= 20:
    n4 = round(pintura/20)
    c = round(n4*700, 2)
    print("Se necesitan ", n4," latas de 20 litros y el costo es: $", c)
