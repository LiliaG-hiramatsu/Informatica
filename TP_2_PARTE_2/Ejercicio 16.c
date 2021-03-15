/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 16.c
 * Author: lilia
 *
 * Created on 8 de septiembre de 2019, 23:21
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int valor) {
    
    if (valor == 0 || valor == 1) {
        return 1;
    }
    else {
        return fibonacci(valor - 1) + fibonacci(valor - 2);
    }

}

int main(int argc, char** argv) {
    
    int n; //Hasta esta posición se calcula la serie.
    printf("Ingrese un entero positivo:\n");
    scanf("%d", &n);
    printf("La serie de Fibonacci es:\n");
    int i;
    
    printf("{ ");
    for (i = 0; i <= n; i++) {
        int r = fibonacci(i);
        printf("%d ", r);
    }
    printf("}\n");

    return (EXIT_SUCCESS);
}

