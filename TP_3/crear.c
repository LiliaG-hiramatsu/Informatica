#include "crear.h"

double *crear_vector(int N) {
    double *v;
    v = (double *)malloc(N*sizeof(double));
    return v;
}

void cargar_vector1(int N, double *v) {
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) {
        v[i] = 1 + rand() % 50;
    }
}

void cargar_vector2(int N, double *v) {
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) {
        v[i] = 50 + rand() % 100;
    }
}

void escalar_vector(int N, double s, double *v) {
    int i;
    for (i = 0; i < N; i++) {
        v[i] = v[i]*s;
    }
}

void mostrar_vector(int N, double *v) {
    int i;
    for (i = 0; i < N; i++) {
        printf("v[%d] = %.2f\n", i+1, v[i]);
    }
}

void borrar_vector(double *vector) {
        free(vector);
}


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
    m = realloc(m, dim1*(sizeof(double *)));
    for (i = 0; i < dim1; i++) {
        if (i > dim2) {
            m[i] = realloc(m[i], dim2*(sizeof(double)));
        }
        else {
            m[i] = (double *)malloc(dim2*(sizeof(double)));
        }
    }
    //Copio los elementos de la matriz temporal a la matriz transpuesta (que sería la original pero redimensionada)
    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            m[j][i] = matriz_temporal[j][i];
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

void mostrar_matriz(double **matriz, int fila, int columna) {
    int i, j;
    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void borrar_matriz(double **matriz, int fila) {
    int i;
    for (i = 0; i < fila; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
