/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 9.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 11:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    
    int a, b, c, d, e;
    printf("Ingresar los valores de las constantes:\n");
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    printf("c = ");
    scanf("%d",&c);
    printf("d = ");
    scanf("%d",&d);
    printf("e = ");
    scanf("%d",&e);
    
    float x, y;
    float denominador = c - ((d + 5 * e) / (a - b));
    
    if (denominador != 0) {
        x = (3 * a + b) / denominador;
        printf("El valor de x es: %f\n", x);
    }
    else {
        printf("Error matemático.\n");
    }
    y = 3 * pow(a,4) - 5 * pow(b,3) + 12 * c - 7;
    printf("El valor de y es: %f\n", y);

    return (EXIT_SUCCESS);
}

