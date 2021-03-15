/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 12.c
 * Author: lilia
 *
 * Created on 3 de septiembre de 2019, 11:29
 *
 */
/*
12. Escribir un programa que le pida al usuario una fecha del estilo DD/MM/AAAA y determine:
        a. El día anterior y posterior.
        b. El último día del mes y cuantos días faltan para el mismo.
 Considere la existencia de los años bisiestos.
 */

#include <stdio.h>
#include <stdlib.h>

int dia_anterior (int d, int m, int a) {
    
    int d_ant;
    
    if (d != 1) {
        d_ant = d - 1;
    }
    else if (d == 1) {
        if (m == 5 || m == 7 || m == 10 || m == 12) {
            d_ant = 30;
        }
        else if (m == 3) {
            if (a % 4 == 0) {
                d_ant = 29;
            }
            else {
                d_ant = 28;
            }
        }
        else if (m == 1 || m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11) {
            d_ant = 31;
        }
    }
    
    return d_ant;
}

int mes_anterior(int d, int m) {
    
    int m_ant;
    
    if (d == 1) {
        if (m == 1) {
            m_ant = 12;
        }
        else {
            m_ant = m - 1;
        }
    }
    else {
        m_ant = m;
    }

    return m_ant;
}

int anio_anterior (int d, int m, int a) {
    
    int a_ant;
    if (m == 1 && d == 1) {
        a_ant = a - 1;
    }
    else {
        a_ant = a;
    }
    
    return a_ant;
}

int dia_posterior (int d, int m, int a) {
    
    int d_post;
    
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d == 31) {
            d_post = 1;
        }
        else {
            d_post = d + 1;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d == 30) {
            d_post = 1;
        }
        else {
            d_post = d + 1;
        }
    }
    else if (m == 2) {
        if (a % 4 == 0) {
            if (d == 29) {
                d_post = 1;
            }
            else {
                d_post = d + 1;
            }
        }
        else {
            if (d == 28) {
                d_post = 1;
            }
            else {
                d_post = d + 1;
            }
        }
    }
    
    return d_post;
}

int mes_posterior(int d, int m, int a) {
    
    int m_post;
    
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
        if (d == 31) {
            m_post = m + 1;
        }
        else {
            m_post = m;
        }
    }
    else if (m == 12) {
        if (d == 31) {
            m_post = 1;
        }
        else {
            m_post = m;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d == 30) {
            m_post = m + 1;
        }
        else {
            m_post = m;
        }
    }
    else if (m == 2) {
        if (a % 4 == 0) {
            if (d == 29) {
                m_post = m + 1;
            }
            else {
                m_post = m;
            }
        }
        else {
            if (d == 28) {
                m_post = m + 1;
            }
            else {
                m_post = m;
            }
        }
    }
    
    return m_post;
}

int anio_posterior(int d, int m, int a) {
    
    int a_post;
    if (m == 12 && d == 31) {
        a_post = a +1;
    }
    else {
        a_post = a;
    }
    
    return a_post;
}

int ultimo_dia(int m, int a) {
    
    int d;
    
    if (m == 2) {
        if (a % 4 == 0) {
            d = 29;
        }
        else {
            d = 28;
        }
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        d = 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        d = 30;
    }
    
    return d;
}

int error(int d, int m, int a) {
    
    int band = 1;
    
    if (m > 12 || m < 1) {
        band = 0;
    }
    if (m == 2) {
        if (a % 4 == 0) {
            if (d > 29) {
                band = 0;
            }
        }
        else {
            if (d > 28) {
                band = 0;
            }
        }
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31 || d < 0) {
            band = 0;
        }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30 || d < 0) {
            band = 0;
        }
    }
    if (a < 0) {
        band = 0;
    }
    
    return band;
}

int main(int argc, char** argv) {
    
    int dia, mes, anio;
    printf("Ingrese una fecha del estilo DD/MM/AAAA: ");
    scanf("%d/%d/%d", &dia, &mes, &anio);
    printf("\n");
    
    int b = error(dia, mes, anio);
    
    if (b == 0) {
        printf("Error al ingresar la fecha. Intente de nuevo.\n");
    }
    else {
        int dia_ant = dia_anterior(dia, mes, anio);
        int mes_ant = mes_anterior(dia, mes);
        int anio_ant = anio_anterior(dia, mes, anio);
        int dia_post = dia_posterior(dia, mes, anio);
        int mes_post = mes_posterior(dia, mes, anio);
        int anio_post = anio_posterior(dia, mes, anio);
        int ult = ultimo_dia(mes, anio);
        int resto = ult - dia;
        printf("El día anterior es: %d/%d/%d\n", dia_ant, mes_ant, anio_ant);
        printf("El día posterior es: %d/%d/%d\n", dia_post, mes_post, anio_post);
        printf("El último día del mes es: %d/%d/%d\n", ult, mes, anio);
        printf("Y para ello faltan: %d días.\n", resto);
    }
    
    return (EXIT_SUCCESS);
}