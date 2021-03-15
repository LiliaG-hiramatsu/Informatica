/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 15.c
 * Author: lilia
 *
 * Created on 8 de septiembre de 2019, 23:00
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int valor) {
    
    if (valor == 1 || valor == 0) {
        return 1;
    }
    else {
        return valor * factorial(valor - 1);
    }
}

int main(int argc, char** argv) {

    int num;
    printf("Ingrese un entero positivo:\n");
    scanf("%d", &num);
    printf("*Función factorial*\n");
    int r = factorial(num);
    printf("El resultado es: %d\n", r);
    
    return (EXIT_SUCCESS);
}

