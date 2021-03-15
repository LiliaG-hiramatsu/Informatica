/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   crear.h
 * Author: lilia
 *
 * Created on 10 de octubre de 2019, 14:14
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double *crear_vector(int N);
void cargar_vector(int N, double *v);
void escalar_vector(int N, double s, double *v);
void mostrar_vector(int N, double *v);
#endif

