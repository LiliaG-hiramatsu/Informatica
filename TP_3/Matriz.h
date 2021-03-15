/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.h
 * Author: lilia
 *
 * Created on 10 de octubre de 2019, 15:47
 */

#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double **crear_matriz(int fila, int columna);
void cargar_matriz1(double **matrizA, int f, int c);
void cargar_matriz2(double **matrizB, int f, int c);
double **producto_matricial(double **matrizA, double **matrizB, int dim1, int dim2, int dim3);
void mostrar_matriz(double **matriz, int fila, int columna);
void liberar_matriz(double **matriz, int fila);
#endif /* MATRIZ_H */

