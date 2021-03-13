/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 7.c
 * Author: lilia
 *
 * Created on 27 de agosto de 2019, 09:48
 * 
 Elaborar un algoritmo en el cual se ingrese una letra y se detecte si se 
 trata de una vocal o cualquier otro tipo de caracter.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    char letra;
    printf("Ingrese una letra:\n");
    scanf("%c", &letra);
    if ((letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u')) {
        printf("La letra ingresada es una vocal.\n");
    }
    else {
        printf("La letra ingresada se trata de otro caracter.\n");
    }
    
    return (EXIT_SUCCESS);
}

