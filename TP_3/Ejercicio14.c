/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lilia
 *
 * Created on 14 de abril de 2019, 18:33
 */
#include "funcion.h"
FILE *fp;
int main(int argc, char** argv) {
    char archivo[100];
    printf("Ingrese el nombre del archivo: ");
    fgets(archivo, 100, stdin);
    int N, opcion = 1;
    printf("N = ");
    scanf("%d", &N);
    printf("opcion = 1 (escribe), opcion = 2 (lee)\n");
    while (opcion == 1 || opcion == 2) {
        printf("Ingresar opcion: ");
        scanf("%d", &opcion);
        if (opcion == 1) {
            funcion_escribir(archivo, N);
        }
        else {
            if (opcion == 2) {
                funcion_leer(archivo, N);
            }
        } 
    }
    return (EXIT_SUCCESS);
}

