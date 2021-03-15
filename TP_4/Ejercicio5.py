#Funcion para convertir las letras en números
def convertir(letra):                       #Utilicé una lista para representar el tablero del juego, esta me permite almacenar
    lista = ['A', 'B', 'C', 'D']                  #tanto valores enteros (1, 2, 3 y 4) como caracteres (A, B, C y D). No podríamos hacer esto
    lista[0] = 1                                         #en un array si programamos en C
    lista[1] = 2
    lista[2] = 3
    lista[3] = 4
    if letra == lista[0]:
        letra = int(lista[0])
    elif letra == lista[1]:
        letra = int(lista[1])
    elif letra == lista[2]:
        letra = int(lista[2])
    elif letra == lista[3]:
        letra = int(lista[3])
    return letra

x1_l = input("x1: ")
x1 = convertir(x1_l)
y1 = input("y1: ")
nave1 = x1,y1                                     #Cada nave la almacené en una tupla
print("Nave 1:" , nave1)
x2_l = input("x2: ")
x2 = convertir(x2_l)
y2 = input("y2: ")
nave2 = x2,y2
print("Nave 2: ", nave2)
x3_l = input("x3: ")
x3 = convertir(x3_l)
y3 = input("y3: ")
nave3 = x3,y3
print("Nave 3: ", nave3)
nave = {'nave1': (x1,y1), 'nave2': (x2,y2), 'nave3': (x3,y3)}
print("Nave: ", nave)
np = 40                        #np = numero de protones
p_restante = np
a = True
b = True
if x1 == x2 == x3 and y1 != y2 != y3 or x1 != x2 != x3 and y1 == y2 == y3:
    print("Continuar")
    c = 1
else:
    print("La nave está oblicua. Vuelva a intentarlo.")
    c = 2
if c == 1:
    esc1 = int(input("Escudo 1: "))
    esc2 = int(input("Escudo 2: "))
    esc3 = int(input("Escudo 3: "))
    if 1 <= esc1 <= 9 and 1 <= esc2 <= 9 and 1 <= esc3 <= 9 and c == 1:
        print("Continuar")
    else:
        print("Error. Debe ser una cantidad entre 1 y 9. Vuelva a intentarlo.") #No aclara que pasa si se sale del rango (1-9)
        a = False
else:
    a = False
while a == True and b == True:
        x_l = input("x: ")
        x = convertir(x_l)
        y = input("y: ")
        ataque = x,y
        print("Coordenadas de ataque: ", ataque)
        carga = int(input("Dispara con: "))
        if carga < 1 or carga > 9:
            print("No puede disparar menos de 1 protón o más de 9 protones. Vuelva a intentarlo.")
            b = False
        else:
            if carga <= p_restante:
                if ataque != nave1 and ataque != nave2 and ataque != nave3:
                    print("Espacio!")
                else:
                    if ataque == nave1:
                        if carga > esc1:
                            print("Sin efecto.")
                        else:
                            print("Ataque efectivo.")
                            r1 = esc1 - carga
                            esc1 = r1
                            if esc1 == 0:
                                print("Escudo neutralizado.")
                            else:
                                print("Escudo no neutralizado.")
                    elif ataque == nave2:
                        if carga > esc2:
                            print("Sin efecto.")
                        else:
                            print("Ataque efectivo.")
                            r2 = esc2 - carga
                            esc2 = r2
                            if esc2 == 0:
                                print("Escudo neutralizado.")
                            else:
                                print("Escudo no neutralizado.")
                    elif ataque == nave3:
                        if carga > esc3:
                            print("Sin efecto.")
                        else:
                            print("Ataque efectivo.")
                            r3 = esc3 - carga
                            esc3 = r3
                            if esc3 == 0:
                                print("Escudo neutralizado.")
                            else:
                                print("Escudo no neutralizado.")
                p_restante -= carga
                print("En el reactor de protones queda: ", p_restante)
                escudo = esc1 + esc2 + esc3
                print("Cantidad de electrones que quedan: ", escudo)
                if escudo == 0 and p_restante != 0:
                    print("Ganó el atacante.")
                    b = False
                elif p_restante == 0:
                    print("Ganó el defensor.")
                    b = False
            else:
                print("No puede disparar con una carga mayor a la de protones restantes en el reactor.")
                b = False
