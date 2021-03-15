def caracter(letra):
    lista_caracter = ['a', 'á', 'b', 'c', 'd', 'e', 'é', 'f', 'g', 'h', 'i', 'í', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'ó', 'p', 'q', 'r', 's', 't', 'u', 'ú', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '-', '(', ')', '\n']
    for letra in lista_caracter:
        return letra

def count_letra(texto):
    contador = 0
    for c in texto:
        if caracter(c):
            contador += 1
    return contador

def count_oracion(texto):
    contador = 0
    fin = '.'
    for oracion in texto:
        if oracion == fin:
            contador += 1
    return contador

def count_palabra(texto):
    contador = 0
    esp = ' '
    salto = '\n'
    for espacio in texto:
        if espacio == esp or espacio == salto:
            contador += 1
    return contador

ruta = "/home/lilia/Lili/Facultad de Ingeniería UNCuyo/Informática/tp4_parteAyB/No se culpe a nadie.txt"
f = open(ruta, "r")
text = f.read()
f.close()
archivo = text.lower()
palabras = archivo.split()
contador1 = count_letra(archivo)
print("a) Cantidad de caracteres: ", contador1)
contador2 = count_oracion(archivo)
print("b) Cantidad de oraciones: ", contador2)
contador3 = count_palabra(archivo)
print("c) Cantidad de palabras: ", contador3)
contador4 = 0
for i in palabras:
    if len(i) > 6:
        contador4 += 1
print("d) Cantidad de palabras de más de 6 caracteres que hay en el texto: ", contador4)
