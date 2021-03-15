/* EJERCICIO 8
Escriba una función que reciba como argumento un entero N, cree un vector de N
elementos de tipo double dinámicamente (utilizando la función malloc), y devuelva un
apuntador con la dirección de memoria del arreglo creado.
 */

#include "crear.h"

int main(int argc, char** argv) {
    int n;
    printf("N = ");
    scanf("%d", &n);
    double *vector = crear_vector(n);
    printf("\nEl puntero con dirección %p apunta a la posición %p que tiene almacenado el valor %.2f\n", &vector, vector, *vector);
    return (EXIT_SUCCESS);
}
