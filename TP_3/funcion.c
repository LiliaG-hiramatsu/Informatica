/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funcion.h"
int *crear_arreglo(int N) {
    int *vector = (int *)malloc(sizeof(int));
    return vector;
}
int *cargar_arreglo(int N) {
    srand(time(NULL));
    int i;
    int *arreglo = crear_arreglo(N);
    for (i = 0; i < N; i++) {
        arreglo[i] = 1 + rand() % ((30 + 1) - 1);
    }
    return arreglo;
}
void borrar_arreglo(int *vector) {
    free(vector);
}
FILE *fd;
void funcion_escribir(char *archivo, int N) {
    fd = fopen(archivo, "w+");
    int *v = cargar_arreglo(N);
    if (fd == NULL) {
        printf("Error al escribir el archivo.\n");
    }
    else {
        printf("Grabar vector en el archivo.\n");
        int i;
        for (i = 0; i < N; i++) {
            fprintf(fd, "%d\n", v[i]);
        }
    }
    fclose(fd);
    printf("Fichero cerrado.\n");
}
void funcion_leer(char *archivo, int N) {
    int i = 0,  valor, lista[100];
    char cadena[100];
    fd = fopen(archivo, "r");
    if (fd == NULL) {
        printf("Error al leer el fichero.\n");
    }
    else {
        printf("Leyendo el archivo.\n");
        printf("Grabando los valores leidos en el vector\n");
        while ( feof(fd) == 0 ) {
            if (fgets(cadena, 100, fd) > 0) {
                printf("recibe: %s", cadena);
                sscanf(cadena, "%d", &valor);
                printf("valor = %d\n", valor);
                lista[i] = valor;
                i++;
            }
        }
    }
    fclose(fd);
    printf("Fichero cerrado.\n");
    printf("Lista de valores copiados al vector:\n");
    int j;
    for (j = 0; j < i; j++) {
                printf("%d\n", lista[j]);
    }
}