/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "crearmatriz.h"

double **crear_matriz(int dim1, int dim2) {
    double **matriz;
    matriz = (double **)malloc(dim1*sizeof(double *));
    int i;
    for (i = 0; i < dim1; i++) {
        matriz[i] = (double *)malloc(dim2*sizeof(double));
    }
    return matriz;
}

void cargar_matriz1(double **A, int dim1, int dim2) {
    srand(time(NULL));
    int i,j;
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            A[i][j] = 1 + rand() % 50;
        }
    }
}

void cargar_matriz2(double **B, int dim3, int dim2) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < dim3; i++) {
        for (j = 0; j < dim2; j++) {
            B[i][j] = 1 + rand() % 30;
        }
    }
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

void borrar_matriz(double **matriz, int fila) {
    int i;
    for (i = 0; i < fila; i++) {
        free(matriz[i]);
    }
    free(matriz);
}