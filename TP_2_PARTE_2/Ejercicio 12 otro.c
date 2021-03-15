/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lilia
 *
 * Created on 4 de septiembre de 2019, 00:45
 */

#include <stdio.h>
#include <stdlib.h>

void f_yesterday(int day, int month, int year) {
    
    int d_ayer, m_ayer, y_ayer;
    
    if (day == 1) {
        if (month != 1) {
            m_ayer = month - 1;
            y_ayer = year;
            if (month == 11 || month == 9 || month == 8 || month == 6 || month == 4 || month == 2) {
                d_ayer = 31;
            }
            else if (month == 5 || month == 7 || month == 10 || month == 12) {
                d_ayer = 30;
            }
            else if (month == 3) {
                if (year % 4 == 0) {
                    d_ayer = 29;
                }
                else {
                    d_ayer = 28;
                }
            }
        }
        else if (month == 1) {
            d_ayer = 31;
            m_ayer = 12;
            y_ayer = year - 1;
        }
    }
    else {
        d_ayer = day - 1;
        m_ayer = month;
        y_ayer = year;
    }
    printf("El día anterior es: %d/%d/%d\n", d_ayer, m_ayer, y_ayer);
}

void f_tomorrow(int day, int month, int year) {
    
    int d_maniana, m_maniana, y_maniana;
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day == 30) {
            d_maniana = 1;
            m_maniana = month + 1;
        }
        else if (day < 30) {
            d_maniana = day + 1;
            m_maniana = month;
        }
        y_maniana = year;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
        if (day == 31) {
            d_maniana = 1;
            m_maniana = month + 1;
        }
        else if (day < 31) {
            d_maniana = day + 1;
            m_maniana = month;
        }
        y_maniana = year;
    }
    else if (month == 12) {
        if (day == 31) {
            d_maniana = 1;
            m_maniana = 1;
            y_maniana = year + 1;
        }
        else if (day < 31) {
            d_maniana = day + 1;
            m_maniana = 12;
            y_maniana = year;
        }
    }
    else if (month == 2) {
        if (year % 4 == 0) {
            if (day == 29) {
                d_maniana = 1;
                m_maniana = 3;
            }
            else if (day < 29) {
                d_maniana = day + 1;
                m_maniana = 2;
            }
        }
        else {
            if (day == 28) {
                d_maniana = 1;
                m_maniana = 3;
            }
            else if (day < 28) {
                d_maniana = day + 1;
                m_maniana = 2;
            }
        }
        y_maniana = year;
    }
    printf("El día posterior es: %d/%d/%d\n", d_maniana, m_maniana, y_maniana);
}

void last_day(int day, int month, int year) {
    
    int ultimo_dia;
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        ultimo_dia = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        ultimo_dia = 30;
    }
    else if (month == 2) {
        if (year % 4 == 0) {
            ultimo_dia = 29;
        }
        else {
            ultimo_dia = 28;
        }
    }
    int resto = ultimo_dia - day;
    printf("El último día del mes es: %d/%d/%d\n", ultimo_dia, month, year);
    printf("Y para ello falta: %d día/s.\n", resto);
}

int error(int day, int month, int year) {
    
    int flat = 1;
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31 || day <= 0) {
            flat = 0;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day <= 0) {
            flat = 0;
        }
    }
    else if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29 || day <= 0) {
                flat = 0;
            }
        }
        else {
            if (day > 28 || day <= 0) {
                flat = 0;
            }
        }
    }
    else if (month > 12 || month <= 0 || year <= 0) {
        flat = 0;
    }
    return flat;
}

int main(int argc, char** argv) {
    
    int dia, mes, anio;
    printf("Ingrese una fecha del estilo DD/MM/AAAA:\n");
    scanf("%d/%d/%d", &dia, &mes, &anio);
    
    int bandera = error(dia, mes, anio);
    if (bandera == 0) {
        printf("Error al ingresar la fecha. Intente de nuevo.\n");
    }
    else {
        printf("La fecha ingresada es: %d/%d/%d\n", dia, mes, anio);
        f_yesterday(dia, mes, anio);
        f_tomorrow(dia, mes, anio);
        last_day(dia, mes, anio);
    }
    
    return (EXIT_SUCCESS);
}