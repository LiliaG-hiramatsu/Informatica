/* EJERCICIO 2
Implementar una función que genere una matriz con todos los elementos en 0 excepto
aquellos para los que i+j sea par; para estos elementos generar un valor aleatorio entre 1 y
10000.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {

    int m, n;
    int i, j;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    int matriz[m][n];
    srand(time(NULL));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                matriz[i][j] = 1 + rand() % (10000 + 1) - 1;
            }
            else {
                matriz[i][j] = 0;
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}
