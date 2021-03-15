/* EJERCICIO 1
Escriba un programa que:
a. Genere un vector de tamaño N con valores aleatorios enteros, utilizando la función
rand(). Use la función srand() para obtener una mejor aleatoriedad.
b. Recorra el vector y guarde el promedio de los valores en una variable
c. Encuentre el menor de los elementos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char** argv) {

    int N;
    printf("N = ");
    scanf("%d", &N);
    int vector[N];
    int suma = 0, menor = 0;
    float promedio;
    srand(time(NULL));
    int i;
    for(i = 0; i < N; i++) {
        vector[i] = 1 + rand() % (100 + 1) - 1;
        printf("vector[%d] = %d\n", i+1, vector[i]);
        suma = suma + vector[i];
        promedio = suma / N;
        if (vector[i] < vector[menor]) {
            menor = i;
        }
    }
    printf("Promedio = %.2f\n", promedio);
    printf("El menor elemento es: %d\n", vector[menor]);
    return (EXIT_SUCCESS);
}
