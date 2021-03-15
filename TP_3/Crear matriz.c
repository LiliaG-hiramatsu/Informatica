/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Matriz.h"

double **crear_matriz(int fila, int columna) {
    double **matriz;
    matriz = (double **)malloc(fila*sizeof(double *));
    int i;
    for (i = 0; i < fila; i++) {
        matriz[i] = (double *)malloc(columna*sizeof(double));
    }
    return matriz;
}

void cargar_matriz1(double **matrizA, int f, int c) { //La matriz A contiene elementos random de 1 a 50.
    srand(time(NULL));
    int i, j;
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            matrizA[i][j] = 1 + rand() % 50;
        }
    }
}

void cargar_matriz2(double **matrizB, int f, int c) { //La matriz B contiene elementos random de 1 a 30.
    srand(time(NULL));
    int i, j;
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            matrizB[i][j] = 1 + rand() % 30;
        }
    }
}

double **producto_matricial(double **matrizA, double **matrizB, int dim1, int dim2, int dim3) {
    int i, j, k, sum = 0;
    double **matrizC = crear_matriz(dim1, dim3);
    for (i = 0; i < dim1; i++) {
          for (j = 0; j < dim3; j++) {
                for (k = 0; k < dim2; k++) {
                    sum += matrizA[i][k] * matrizB[k][j];
                }
                matrizC[i][j] = sum;
                sum = 0;
          }
    }
    return matrizC;
}

void mostrar_matriz(double **matriz, int fila, int columna) {
    int i, j;
    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz(double **matriz, int fila) {
    int i;
    for (i = 0; i < fila; i++) {
        free(matriz[i]);
    }
    free(matriz);
}