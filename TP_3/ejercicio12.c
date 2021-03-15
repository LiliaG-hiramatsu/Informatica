/* EJERCICIO 12
Escriba una función que reciba como parámetro una matriz de M x N elementos, y calcule
la transpuesta de la matriz. El resultado debe ser almacenado en la misma matriz (es decir
que no se debe reservar memoria para el resultado ni devolver ningún apuntador)
*/

#include "crear.h"

int main(int argc, char** argv) {

    int M, N;
    printf("M = "); scanf("%d", &M);
    printf("N = "); scanf("%d", &N);
    double **matriz;
    matriz = crear_matriz(M, N);
    cargar_matriz1(matriz, M, N);
    printf("\n**Matriz**\n");
    mostrar_matriz(matriz, M, N);
    matriz_transpuesta(matriz, M, N);
    printf("\n**Matriz transpuesta**\n");
    mostrar_matriz(matriz, N, M);
    borrar_matriz(matriz, M);

    return (EXIT_SUCCESS);
}
