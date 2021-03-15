/* EJERCICIO 13
Escriba un programa que, utilizando las dos funciones anteriores:
a. Lea por teclado 3 valores M, N y P
b. Cree 2 matrices dinámicamente con valores aleatorios:
  i. La primer matriz (C​1 )de M x N
  ii. La segunda matriz (C​2 ) de P x N
​c. Calcule la transpuesta de la segunda matriz (C​2​), dando lugar a la matriz C​2T
d. Calcule el producto de C​1​ x C​2T
e. Muestre los resultados intermedios por pantalla
f. Libere la memoria dinámica utilizada
*/

#include "crear.h"

int main(int argc, char** argv) {

    int M, N, P;
    printf("M = "); scanf("%d", &M);
    printf("N = "); scanf("%d", &N);
    printf("P = "); scanf("%d", &P);
    double **matrizC1, **matrizC2;
    matrizC1 = crear_matriz(M, N);
    cargar_matriz1(matrizC1, M, N);
    printf("\n**MATRIZ C1**\n");
    mostrar_matriz(matrizC1, M, N);
    matrizC2 = crear_matriz(P, N);
    cargar_matriz2(matrizC2, P, N);
    printf("\n**MATRIZ C2**\n");
    mostrar_matriz(matrizC2, P, N);
    matriz_transpuesta(matrizC2, P, N);
    printf("\n**MATRIZ TRANSPUESTA C2T**\n");
    mostrar_matriz(matrizC2, N, P);
    double **C = producto_matricial(matrizC1, matrizC2, M, N, P);
    printf("\n**PRODUCTO MATRICIAL C1xC2T**\n");
    mostrar_matriz(C, M, P);
    borrar_matriz(matrizC1, M);
    borrar_matriz(matrizC2, P);
    borrar_matriz(C, M);

    return (EXIT_SUCCESS);
}
