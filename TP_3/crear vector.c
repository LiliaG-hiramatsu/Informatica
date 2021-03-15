/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Vector.h"

double *crear_vector(int N) {
    double *v;
    v = (double *)malloc(N*sizeof(double));
    return v;
}

void cargar_vector(int N, double *v) {
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) {
        v[i] = 1 + rand() % 50;
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