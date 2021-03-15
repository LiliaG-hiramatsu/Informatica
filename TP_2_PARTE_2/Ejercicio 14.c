/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 14.c
 * Author: lilia
 *
 * Created on 5 de septiembre de 2019, 00:01
 */

#include <stdio.h>
#include <stdlib.h>

void ecuacion1() {
    
    int i, j;
    float suma1 = 0;
    
    for (i = 0; i <= 100; i++) {
        for (j = 0; j <= 100; j++) {
            if ((i - j) != 0) {
                suma1 += (i + j) / (i - j);
            }
            else {
                suma1 += 0;
            }
        }
    }
    printf("El resultado de la primer ecuación es: %.2f\n", suma1);
}

void ecuacion2() {
    
    int i, j;
    float suma2 = 0;
    
    for (i = 0; i <= 100; i++) {
        for (j = 0; j <= 100; j++) {
            if ((i % 2 == 0) && (j % 2 == 0) && ((i + j) != 0)) {
                suma2 += (float)(i * j) / (float)(i + j);
            }
            else {
                suma2 += 0;
            }
        }
    }
    printf("El resultado de la segunda ecuación es: %.2f\n", suma2);
}

int main(int argc, char** argv) {

    printf("***RESULTADOS***\n");
    ecuacion1();
    ecuacion2();
    
    return (EXIT_SUCCESS);
}

