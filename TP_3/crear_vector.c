#include "crear.h"
double *crear_vector(int N) {
    double *v;
    v = (double *)malloc(N*sizeof(double));
    return v;
}
