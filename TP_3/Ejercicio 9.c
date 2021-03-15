/* EJERCICIO 9
Escriba una función que reciba un vector de N elementos double (donde N puede ser
variable) y un escalar double ​s, ​ y escale ​el mismo arreglo utilizando el factor ​s ​(es decir, no
debe devolver un puntero ni crear otro arreglo)
*/

#include "Vector.h"

int main(int argc, char** argv) {
    int N;
    srand(time(NULL));
    N = 1 + rand() % 20;
    double *vector = crear_vector(N);
    double s;
    printf("s = "); scanf("%lf", &s);
    printf("\nN = %d\n", N);
    cargar_vector(N, vector);
    printf("\n*Vector*\n");
    mostrar_vector(N, vector);
    escalar_vector(N, s, vector);
    printf("\n*Vector escalado*\n");
    mostrar_vector(N, vector);
    return (EXIT_SUCCESS);
}
