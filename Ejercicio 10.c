/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 10.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 11:49
 * 
 La compañía de celulares “Chismefon” posee un mecanismo de cobro de llamadas por el cual
 mientras más se habla, menos se paga. De esta forma los primeros cinco minutos cuestan
 $ 1.00 c/u, los siguientes tres, $ 0.80 c/u, los siguientes dos minutos, $ 0.70 c/u, y a partir 
 del décimo minuto, 0.50 c/u (los valores no incluyen IVA).  Realice un programa para determinar
 el costo total de una llamada expresada en segundos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    float costo;
    int t; //tiempo en segundos
    
    printf("Ingresar el tiempo en segundos de la duración de la llamada:\n");
    scanf("%d", &t);
    
    if (t == 300) {
        costo = 1 * t/60;
    }
    else if (t > 300 && t < 481) {
        costo = 5 + 0.80*((t/60) - 5);
    }
    else if (t > 480 && t < 601) {
        costo = 5 + 2.4 + 0.70*((t/60) - 8);
    }
    else if (t > 600) {
        costo = 5 + 2.4 + 1.4 + 0.50*((t/60) - 10);
    }
    printf("El costo total de la llamada es: $ %f\n", costo);
    
    return (EXIT_SUCCESS);
}

