/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "transpuesta.h"

double **crear_matriz(int fila, int columna) {
    double **m;
    int i;
    m = (double **)malloc(fila*sizeof(double *));
    for (i = 0; i < fila; i++) {
        m[i] = (double *)malloc(columna*sizeof(double));
    }
    return m;
}

void cargar_matriz(double **m, int f, int c) { //La matriz A contiene elementos random de 1 a 50.
    srand(time(NULL));
    int i, j;
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            m[i][j] = 1 + rand() % 50;
        }
    }
}

void mostrar_matriz(double **m, int fila, int columna) {
    int i, j;
    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }
}

void matriz_transpuesta(double **m, int dim1, int dim2) {
    //Creo una matriz temporal
    double **matriz_temporal = crear_matriz(dim2, dim1);
    int i, j;
    //Calculo la transpuesta de la matriz y la copio temporalmente en la matriz temporal
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            matriz_temporal[j][i] = m[i][j];
        }
    }
    //Hay que redimensionar la matriz original
    m = realloc(m, dim2*(sizeof(double *)));
    for (i = 0; i < dim2; i++) {
        if (i < dim1) {
            m[i] = realloc(m[i], dim1*(sizeof(double)));
        }
        else {
            m[i] = (double *)malloc(dim1*(sizeof(double)));
        }
    }
    //Copio los elementos de la matriz temporal a la matriz transpuesta (que sería la original pero redimensionada)
    for (i = 0; i < dim2; i++) {
        for (j = 0; j < dim1; j++) {
            m[i][j] = matriz_temporal[i][j];
        }
    }
    //Borro la matriz temporal
    for (i = 0; i < dim1; i++) {
        free(matriz_temporal[i]);
    }
    free(matriz_temporal);
}

void liberar_matriz(double **m, int fila) {
    int i;
    for (i = 0; i < fila; i++) {
        free(m[i]);
    }
    free(m);
}