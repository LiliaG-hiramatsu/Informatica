/* EJERCICIO 3
Escriba un programa que lea una cadena con una operación matemática básica de dos
términos (suma, resta, multiplicación y división) y calcule el resultado. Por ej. el usuario
ingresa “2.4+3”, el resultado a devolver es “5.4”. Considere los datos de entrada números
flotantes. Considere una cadena máxima de 100 caracteres.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    char c1[100], c2[100], c3[100];
    printf("Ingresar operación:\n");
    fgets(c1, 100, stdin);
    int i, j, k, N = 0;
    float r1, r2, resultado;

    for(i = 0; i < 100; i++) {
        if (c1[i] == '+' || c1[i] == '-' || c1[i] == '/' || c1[i] == '*') {
            N = i;
        }
    }
    for(j = 0; j < N; j++) {
        c2[j] = c1[j];
    }
    for(k = 0; k < 100; k++) {
        c3[k] = c1[k+N+1];
    }

    r1 = atof(c2);
    r2 = atof(c3);
    printf("r1 = %.2f\n", r1);
    printf("r2 = %.2f\n", r2);

    if (c1[N] == '+') {
        resultado = r1 + r2;
        }
    else if (c1[N] == '-') {
        resultado = r1 - r2;
        }
    else if (c1[N] == '/') {
        resultado = r1 / r2;
    }
    else if (c1[N] == '*') {
        resultado = r1 * r2;
    }

    printf("El resultado de la operación es: %.2f\n", resultado);

    return (EXIT_SUCCESS);
}
