/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_random.h
 * Author: lilia
 *
 * Created on 15 de abril de 2019, 10:16
 */

#ifndef FUNCION_H
#define FUNCION_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *crear_arreglo(int N);
int *cargar_arreglo(int N);
void funcion_escribir(char *archivo, int N);
void funcion_leer(char *archivo, int N);
void borrar_arreglo(int *vector);
#endif /* FUNCION_H */