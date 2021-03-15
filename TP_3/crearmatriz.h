/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   crearmatriz.h
 * Author: lilia
 *
 * Created on 12 de octubre de 2019, 14:03
 */

#ifndef CREARMATRIZ_H
#define CREARMATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **crear_matriz(int dim1, int dim2);
void cargar_matriz1(double **A, int dim1, int dim2);
void cargar_matriz2(double **B, int dim3, int dim2);
void mostrar_matriz(double **matriz, int fila, int columna);
void matriz_transpuesta(double **m, int dim1, int dim2);
double **producto_matricial(double **matrizA, double **matrizB, int dim1, int dim2, int dim3);
void borrar_matriz(double **matriz, int fila);

#endif /* CREARMATRIZ_H */

