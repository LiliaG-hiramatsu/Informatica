/* EJERCICIO 10
Escriba un programa que, reutilizando las dos funciones anteriores.
a. lea por teclado un entero N
b. cree 2 vectores de N elementos double dinámicamente con valores aleatorios,
c. lea por teclado un factor de escala double
d. escale 2 de los vectores generados en (b) por el factor
e. muestre todos los resultados
f. Libere la memoria dinámica utilizada
*/

#include "Vector.h"

int main(int argc, char** argv) {
    int N;
    printf("N = "); scanf("%d", &N);
    double *vector1 = crear_vector1(N);
    cargar_vector1(N, vector1);
    printf("\n*VECTOR 1*\n");
    mostrar_vector(N, vector1);
    double *vector2 = crear_vector2(N);
    cargar_vector2(N, vector2);
    printf("\n*VECTOR 2*\n");
    mostrar_vector(N, vector2);
    double s;
    printf("\ns = "); scanf("%lf", &s);
    escalar_vector(N, s, vector1);
    printf("\n*VECTOR 1 ESCALADO*\n");
    mostrar_vector(N, vector1);
    escalar_vector(N, s, vector2);
    printf("\n*VECTOR 2 ESCALADO*\n");
    mostrar_vector(N, vector2);
    borrar_vector(vector1);
    borrar_vector(vector2);
    return (EXIT_SUCCESS);
}
