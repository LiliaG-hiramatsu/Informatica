/* EJERCICIO 11
Escriba una función que reciba como parámetros 2 matrices ​A y ​B de MxN y NxP
elementos tipo double, respectivamente, cree una nueva matriz ​C de MxP elementos
dinámicamente, y calcule (almacenando el resultado en ​C​) el producto matricial. La función
debe devover el apuntador a ​C (que fue creada en la misma función). Valide los tamaños
de las matrices para que se pueda realizar la operación.
*/

#include "crear.h"

int main(int argc, char** argv) {
    int M, N, P;
    double **A, **B, **C;
    printf("M = "); scanf("%d", &M);
    printf("N = "); scanf("%d", &N);
    printf("P = "); scanf("%d", &P);
    A = crear_matriz(M, N);
    cargar_matriz1(A, M, N);
    printf("\n*MATRIZ A*\n");
    mostrar_matriz(A, M, N);
    B = crear_matriz(N, P);
    cargar_matriz2(B, N, P);
    printf("\n*MATRIZ B*\n");
    mostrar_matriz(B, N, P);
    C = producto_matricial(A, B, M, N, P);
    printf("\nProducto matricial AxB\n");
    printf("*MATRIZ C*\n");
    mostrar_matriz(C, M, P);
    borrar_matriz(A, M);
    borrar_matriz(B, N);
    borrar_matriz(C, M);
    return (EXIT_SUCCESS);
}
