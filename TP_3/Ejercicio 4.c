/* EJERCICIO 4
Escriba un programa que lea una frase y evalúe en forma recursiva
si la misma corresponde a un palíndromo. Considere una
cadena máxima de 100 caracteres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcion(char palabras[100], int n) {
    int l = strlen(palabras);
    if (palabras[n] == palabras[l-n-1]){
        funcion(palabras, n+1);
        if (n == l - 1) {
            return 0;
        }
    }
    else {
        return 1;
    }
}

int main(int argc, char** argv) {
    char frase[100];
    printf("Ingrese la frase:\n");
    fflush(stdin);
    gets(frase);
    int x = 0;
    if (funcion(frase, x) == 1) {
        printf("\nNo es un palíndromo.\n");
    }
    else {
        printf("\n***Es un palíndromo***\n");
    }
    return (EXIT_SUCCESS);
}
