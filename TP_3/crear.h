#ifndef CREAR
#define CREAR

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double *crear_vector(int N);
void cargar_vector1(int N, double *v);
void cargar_vector2(int N, double *v);
void escalar_vector(int N, double s, double *v);
void mostrar_vector(int N, double *v);
void borrar_vector(double *vector);
double **crear_matriz(int fila, int columna);
void cargar_matriz1(double **matrizA, int f, int c);
void cargar_matriz2(double **matrizB, int f, int c);
void matriz_transpuesta(double **m, int dim1, int dim2);
double **producto_matricial(double **matrizA, double **matrizB, int dim1, int dim2, int dim3);
void mostrar_matriz(double **matriz, int fila, int columna);
void borrar_matriz(double **matriz, int fila);

#endif
