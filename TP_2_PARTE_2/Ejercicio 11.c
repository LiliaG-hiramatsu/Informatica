/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 11.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 12:09
 * 
 Escribir un programa que lea un valor entero desde el teclado, y
 que muestre su configuración de bits por pantalla utilizando los operadores << y >>.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    int num;
    printf("Ingresar un valor entero:\n");
    scanf("%d",&num);
    int band = 1;
    printf("El número en binario es:\n");
    for (int i = 32; i > 0; i--) {
        if (num&band << i - 1) {
            printf("1");
        }
        else {
            printf("0");
        }
    }

    return (EXIT_SUCCESS);
}

