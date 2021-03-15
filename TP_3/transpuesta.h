/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transpuesta.h
 * Author: lilia
 *
 * Created on 11 de octubre de 2019, 11:44
 */

#ifndef TRANSPUESTA_H
#define TRANSPUESTA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **crear_matriz(int fila, int columna);
void cargar_matriz(double **m, int f, int c);
void mostrar_matriz(double **m, int fila, int columna);
void matriz_transpuesta(double **m, int dim1, int dim2);
void liberar_matriz(double **m, int fila);

#endif /* TRANSPUESTA_H */

