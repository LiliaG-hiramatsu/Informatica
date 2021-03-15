tabla_de_posiciones = {}
tabla_de_posiciones['Liga'] = input("Ingresar el nombre de la liga: ")
n = int(input("Ingrese la cantidad de equipos inscriptos: "))
i = 0
total = 0
while (i < n):
    i += 1
    equipo = input(f"Ingrese el nombre del equipo {i}: ")
    tabla_de_posiciones[i] = {}
    tabla_de_posiciones[i]['Nombre'] = equipo
    tabla_de_posiciones[i]['Jugados'] = 0
    tabla_de_posiciones[i]['Goles A'] = 0
    tabla_de_posiciones[i]['Goles B'] = 0
    tabla_de_posiciones[i]['Gana'] = 0
    tabla_de_posiciones[i]['Empata'] = 0
    tabla_de_posiciones[i]['Pierde'] = 0
    tabla_de_posiciones[i]['Puntos'] = 0

p = i
for i in range(1, p):
    for j in range(i+1, p+1):
        s = input("Se suspende el partido? ")
        if (s == 'si'):
            continue
        total += 1
        print(tabla_de_posiciones[i]['Nombre'], "vs", tabla_de_posiciones[j]['Nombre'])
        tabla_de_posiciones[i]['Jugados'] += 1
        tabla_de_posiciones[j]['Jugados'] += 1
        A = int(input(f"Cuántos goles realizó {tabla_de_posiciones[i]['Nombre']}? "))
        tabla_de_posiciones[i]['Goles A'] += A
        B = int(input(f"Cuántos goles realizó {tabla_de_posiciones[j]['Nombre']}? "))
        tabla_de_posiciones[j]['Goles A'] += B
        tabla_de_posiciones[i]['Goles B'] += B
        tabla_de_posiciones[j]['Goles B'] += A
        if (A < B):
            tabla_de_posiciones[j]['Gana'] += 1
            tabla_de_posiciones[i]['Pierde'] += 1
            tabla_de_posiciones[j]['Puntos'] += 3
        elif (A > B):
            tabla_de_posiciones[i]['Gana'] += 1
            tabla_de_posiciones[j]['Pierde'] += 1
            tabla_de_posiciones[i]['Puntos'] += 3
        else:
            tabla_de_posiciones[j]['Empata'] += 1
            tabla_de_posiciones[i]['Empata'] += 1
            tabla_de_posiciones[i]['Puntos'] += 1
            tabla_de_posiciones[j]['Puntos'] += 1

print("Nombre de la liga: ", tabla_de_posiciones['Liga'])
for i in range(1, p+1):
    print(tabla_de_posiciones[i]['Nombre'],"   Jugados: ",tabla_de_posiciones[i]['Jugados'],"  Ganados: ", tabla_de_posiciones[i]['Jugados'],"  Empatados: ",tabla_de_posiciones[i]['Empata'],"  Perdidos: ",tabla_de_posiciones[i]['Pierde'],"  Puntos: ",tabla_de_posiciones[i]['Puntos'])

print("cantidad de partidos jugados: ", total)
