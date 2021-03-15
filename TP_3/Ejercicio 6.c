/* EJERCICIO 6
Escriba un programa que calcule el producto vectorial de 2 vectores en R​3 ​utilizando structs
pare representar los vectores
*/

#include <stdio.h>
#include <stdlib.h>

struct v1 {
    float x1;
    float y1;
    float z1;
};

struct v2 {
    float x2;
    float y2;
    float z2;
};

typedef struct v1 v1_t;
typedef struct v2 v2_t;

void prod_vect(v1_t w1, v2_t w2) {
    float rx = w1.y1*w2.z2 - w1.z1*w2.y2;
    float ry = -(w1.x1*w2.z2 - w1.z1*w2.x2);
    float rz = w1.x1*w2.y2 - w1.y1*w2.x2;
    printf("[%.2f %.2f %.2f]\n", rx, ry, rz);
}

int main(int argc, char** argv) {
    v1_t c1;
    v2_t c2;
    printf("Ingrese las componentes del vector 1: ");
    printf("\nx1 = "); scanf("%f", &c1.x1); printf("y1 = "); scanf("%f", &c1.y1); printf("z1 = "); scanf("%f", &c1.z1);
    printf("V1 = [%.2f %.2f %.2f]\n", c1.x1, c1.y1, c1.z1);
    printf("\nIngrese las componentes del vector 2: ");
    printf("\nx2 = "); scanf("%f", &c2.x2); printf("y2 = "); scanf("%f", &c2.y2); printf("z2 = "); scanf("%f", &c2.z2);
    printf("V2 = [%.2f %.2f %.2f]\n", c2.x2, c2.y2, c2.z2);
    printf("\nEl producto vectorial es: \n[%.2f %.2f %.2f] X [%.2f %.2f %.2f] = ", c1.x1, c1.y1, c1.z1, c2.x2, c2.y2, c2.z2);
    prod_vect(c1, c2);
    return (EXIT_SUCCESS);
}
