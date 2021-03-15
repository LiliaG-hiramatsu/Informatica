/* EJERCICIO 7
Implemente un programa que: (a) declare una variable v de tipo int; (b) llame a una función
void duplicar(int *v) pasándole como parámetro la dirección de memoria de la variable v
(mediante &v); (c) la función debe multiplicar v por 2 y colocar el resultado en la misma
dirección de memoria, de manera que el programa main “vea” el cambio de valor; (d)
imprima por pantalla el valor de la variable v para verificar que el programa funciona
correctamente.
*/

#include <stdio.h>
#include <stdlib.h>

void duplicar(int *v) {
    *v *= 2;
}

int main(int argc, char** argv) {
    int v;
    printf("Ingrese el valor.\n");
    scanf("%d", &v);
    duplicar(&v);
    printf("v = %d\n", v);
    return (EXIT_SUCCESS);
}
