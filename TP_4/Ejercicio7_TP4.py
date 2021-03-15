informatica = [
{
'apellido':'Aronofsky',
'entregoTPs?': True,
'notas': [6, 7, 6]
},
{
'apellido':'Nolan',
'entregoTPs?': True,
'notas': [7, 3, 6],
'recuperatorios': [6]
},
{
'apellido':'Bielinski',
'entregoTPs?': False,
'notas': [7, 8, 8]
},
{
'apellido':'Miyazaki',
'entregoTPs?': True,
'notas': [4, 4, 6],
'recuperatorios': [4, 7]
}
]

alumno1 = informatica[0]
alumno2 = informatica[1]
alumno3 = informatica[2]
alumno4 = informatica[3]

primer_alumno = alumno1['apellido']
segundo_alumno = alumno2['apellido']
tercer_alumno = alumno3['apellido']
cuarto_alumno = alumno4['apellido']

tps1 = alumno1['entregoTPs?']
tps2 = alumno2['entregoTPs?']
tps3 = alumno3['entregoTPs?']
tps4 = alumno4['entregoTPs?']

notas1 = alumno1['notas']
notas2 = alumno2['notas']
notas3 = alumno3['notas']
notas4 = alumno4['notas']

recu2 = alumno2['recuperatorios']
recu4 = alumno4['recuperatorios']

if (primer_alumno):
    print(primer_alumno)
    print("Condicion:")
    p1 = notas1[0]
    p2 = notas1[1]
    tc = notas1[2]
    nf = p1*0.30+p2*0.30+tc*0.40
    if (tps1 == True):
        if (p1 >= 6 and p2 >= 6):
            if (nf >= 7):
                print("Promociona")
            else:
                print("Regulariza")
        else:
            print("Recursa")
    else:
        print("Recursa")

if (segundo_alumno):
    print("\n")
    print(segundo_alumno)
    print("Condicion:")
    p1 = notas2[0]
    p2 = notas2[1]
    tc = notas2[2]
    nf = p1*0.30+p2*0.30+tc*0.40
    r2n = recu2[0]
    if (tps2 == True):
        if (p2 < 6):
            p2 = r2n
            if (r2n >= 6):
                nfr = p1*0.30+r2n*0.30+tc*0.40
                if (nfr >= 7):
                    print("Promociona")
                else:
                    print("Regulariza")
            else:
                print("Recursa")
    else:
            print("Recursa")

if (tercer_alumno):
    print("\n")
    print(tercer_alumno)
    print("Condicion:")
    p1 = notas3[0]
    p2 = notas3[1]
    tc = notas3[2]
    nf = p1*0.30+p2*0.30+tc*0.40
    if (tps3 == True):
        if (p1 >= 6 and p2 >= 6):
            if (nf >= 7):
                print("Promociona")
            else:
                print("Regulariza")
        else:
            print("Recursa")
    else:
        print("Recursa")

if (cuarto_alumno):
    print("\n")
    print(cuarto_alumno)
    print("Condicion:")
    p1 = notas4[0]
    p2 = notas4[1]
    tc = notas4[2]
    nf = p1*0.30+p2*0.30+tc*0.40
    r1 = recu4[0]
    r2m = recu4[1]
    if (tps4 == True):
        if (p1 < 6):
            p1 = r1
        if (p2 < 6):
            p2 = r2m
            if (r1 >= 6 and r2m >= 6):
                nfr = r1*0.30+r2m*0.30+tc*0.40
                if (nfr >= 7):
                    print("Promociona")
                else:
                    print("Regulariza")
            else:
                print("Recursa")
    else:
        print("Recursa")
