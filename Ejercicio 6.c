/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 6.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 09:29
 * 
 Escribir un programa que pida 3 números por pantalla e identifique cual es el valor 
 central, si es posible. Ej. a es central si y solo si b > a > c.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    int a, b, c;
    printf("Escriba 3 números.\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (((a < b) && (a > c)) || ((a < c) && (a > b))) {
        printf("a = %d es el valor central.\n", a);
    }
    else if (((b < a) && (b > c)) || ((b < c) && (b > a))) {
        printf("b = %d es el valor central.\n", b);
    }
    else if (((c < b) && (c > a)) || ((c < a) && (c > b))) {
        printf("c = %d es el valor central.\n", c);
    }
    else {
        printf("Los tres valores son iguales.\n");
    }
    
    return (EXIT_SUCCESS);
}

