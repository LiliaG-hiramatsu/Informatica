/* EJERCICIO 5
Modifique el ejercicio 12 del práctico anterior (el de las fechas) utilizando un struct que
represente una fecha completa. Realice al menos una función que reciba por parámetro
una fecha. Defina la estructura fecha como un tipo definido por el usuario (typedef)
*/

#include <stdio.h>
#include <stdlib.h>

struct FECHA {
    int dia;
    int mes;
    int anio;
};

typedef struct FECHA fecha_t;

int bisiesto(int m, int a) { //Si el año ingresado es bisiesto esta funcion me devuelve 1, sino 0.
    if (m == 2) {
        if (a % 4 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int f_mes(int m) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 1; //para los meses que tienen 31 dias me devuelve 1.
    }
    else if (m == 2) {
        return 2; //para el mes de febrero me devuelve 2.
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 3; //para los meses que tienen 30 dias me devuelve 3.
    }
}

int udm(int m, int a) { //Funcion que devuelve el ultimo dia del mes.
    if (f_mes(m) == 1) {
        return 31;
    }
    else if (f_mes(m) == 2) {
        if (bisiesto(m, a) == 1) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (f_mes(m) == 3) {
        return 30;
    }
}

void ayer (int d, int m, int a) {
    int d_ayer;
    int m_ayer;
    int a_ayer;
    if (d == 1) {
        if (f_mes(m) == 1) {
            if (m == 1) {
                d_ayer = 31;
                m_ayer = 12;
                a_ayer = a - 1;
            }
            else if (m == 3) {
                if (bisiesto(m, a) == 1) {
                    d_ayer = 29;
                    m_ayer = 2;
                    a_ayer = a;
                }
                else {
                    d_ayer = 28;
                    m_ayer = 2;
                    a_ayer = a;
                }
            }
            else if (m == 8) {
                d_ayer = 31;
                m_ayer = 7;
                a_ayer = a;
            }
        }
        else if (f_mes(m) == 2 || f_mes(m) == 3) {
            d_ayer = 31;
            m_ayer = m - 1;
            a_ayer = a;
        }
    }
    else {
        d_ayer = d - 1;
        m_ayer = m;
        a_ayer = a;
    }
    printf("\nEl día anterior es: %d/%d/%d\n", d_ayer, m_ayer, a_ayer);
}

void maniana(int d, int m, int a) {
    int d_maniana;
    int m_maniana;
    int a_maniana;
    if (d == udm(m, a)) {
        if (m == 12) {
            d_maniana = 1;
            m_maniana = 1;
            a_maniana = a + 1;
        }
        else {
            d_maniana = 1;
            m_maniana = m + 1;
            a_maniana = a;
        }
    }
    else {
        d_maniana = d + 1;
        m_maniana = m;
        a_maniana = a;
    }
    printf("\nEl día siguiente es: %d/%d/%d\n", d_maniana, m_maniana, a_maniana);
}

int main(int argc, char** argv) {
    fecha_t F;
    printf("Ingresar fecha del tipo DD/MM/AAAA: ");
    scanf("%d/%d/%d", &F.dia, &F.mes, &F.anio);
    if (F.dia > udm(F.mes, F.anio) || F.dia < 0 || F.mes > 12 || F.mes < 0 || F.anio < 0) {
        printf("\nError.\n");
    }
    else {
        printf("\nLa fecha que ingresó es: %d/%d/%d\n", F.dia, F.mes, F.anio);
        ayer(F.dia, F.mes, F.anio);
        maniana(F.dia, F.mes, F.anio);
        printf("\nEl último día del mes es: %d\n", udm(F.mes, F.anio));
        printf("\nY para ello faltan: %d\n", udm(F.mes, F.anio) - F.dia);
    }
    return (EXIT_SUCCESS);
}
