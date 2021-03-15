/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 17.c
 * Author: lilia
 *
 * Created on 10 de septiembre de 2019, 09:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcion(float coef1, float coef2, float coef3, float v_inicial, float v_final, float incremento) {
    
    for (float i = v_inicial; i <= v_final; i += incremento) {
        return coef1 * pow(i,2) + coef2 * i + coef3;
    }
    
}

int main(int argc, char** argv) {

    float a, b, c, x1, x2, delta;
    printf("a = "); scanf("%f", &a);
    printf("b = "); scanf("%f", &b);
    printf("c = "); scanf("%f", &c);
    printf("x1 = "); scanf("%f", &x1);
    printf("x2 = "); scanf("%f", &x2);
    printf("delta = "); scanf("%f", &delta);
    
    printf("\n**Resultados**\n");
    
    for (float i = x1; i <= x2; i += delta) {
        float r = funcion(a, b, c, i, x2, delta);
        printf("p(%.1f) = %.2f\n", i, r);
    }
    printf("\n");
    
    return (EXIT_SUCCESS);
}

