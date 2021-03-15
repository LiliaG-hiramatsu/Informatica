/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio 13.c
 * Author: lilia
 *
 * Created on 12 de octubre de 2019, 15:55
 */

#include "crearmatriz.h"

int main(int argc, char** argv) {

    int M, N, P;
    printf("M = "); scanf("%d", &M);
    printf("N = "); scanf("%d", &N);
    printf("P = "); scanf("%d", &P);
    double **matrizC1, **matrizC2;
    matrizC1 = crear_matriz(M, N);
    cargar_matriz1(matrizC1, M, N);
    printf("\n**MATRIZ C1**\n");
    mostrar_matriz(matrizC1, M, N);
    matrizC2 = crear_matriz(P, N);
    cargar_matriz2(matrizC2, P, N);
    printf("\n**MATRIZ C2**\n");
    mostrar_matriz(matrizC2, P, N);
    matriz_transpuesta(matrizC2, P, N);
    printf("\n**MATRIZ TRANSPUESTA C2T**\n");
    mostrar_matriz(matrizC2, N, P);
    double **C = producto_matricial(matrizC1, matrizC2, M, N, P);
    printf("\n**PRODUCTO MATRICIAL C1xC2T**\n");
    mostrar_matriz(C, M, P);
    borrar_matriz(matrizC1, M);
    borrar_matriz(matrizC2, P);
    borrar_matriz(C, M);
    return (EXIT_SUCCESS);
}

