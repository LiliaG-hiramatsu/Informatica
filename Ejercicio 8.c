/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 8.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 11:18
 
 8. Escribir un programa que lea 2 números enteros por teclado y que calcule:
        a. el número que contiene sólo los bits que son 1 en ambos números
        b. el número que contiene los bits que son 1 en alguno de los números
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int a, b, c, d;
    printf("Ingrese los valores:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    
    c = a & b;
    d = a | b;
    
    printf("El número que contiene sólo los bits que son 1 en ambos números: %d\n", c);
    printf("El número que contiene los bits que son 1 en alguno de los números: %d\n", d);
    
    return (EXIT_SUCCESS);
}

