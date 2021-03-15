/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 13.c
 * Author: lilia
 *
 * Created on 4 de septiembre de 2019, 23:44
 * 
 13. Escribir un programa que permita ingresar por teclado un valor 
 inicial a, un valor final b, y un número c, y que cuente la cantidad de 
 números divisibles por c que hay en el rango [a,b].
 */

#include <stdio.h>
#include <stdlib.h>

int num_div(int valor1, int valor2, int valor3) {
    
    int contador = 0;
    for (int i = valor1; i <= valor2; i++) {
        if (i % valor3 == 0) {
            contador += 1;
        }
        else {
            contador += 0;
        }
    }
    return contador;
}

int main(int argc, char** argv) {
    
    int a, b, c;
    printf("a = "); scanf("%d", &a);
    printf("b = "); scanf("%d", &b);
    printf("c = "); scanf("%d", &c);
    
    int N = num_div(a, b, c);
    printf("La cantidad de números divisibles por c en el intervalo [a, b] es: N = %d\n", N);

    return (EXIT_SUCCESS);
}

