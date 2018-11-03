#include "algebra.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

double vec_producto_canonico(const double* v1, const double* v2, size_t dim) {

    if (dim == 0) return -1;

    double resultado = 0;

    for (size_t i = 0; i < dim; i++) {
        resultado = resultado + (v1[i] * v2[i]);
    }

    return resultado;
}

double** ortogonalizar(double** base) {
    return NULL;
}

double vector_norma(double* vector, size_t dim, vec_producto_interno_t producto) {

    if (dim == 0) return -1;

    vec_producto_interno_t pi = !producto ? vec_producto_canonico : producto;

    return pi(vector, vector, dim);

}

bool vec_son_ortogonales(const double* v1, const double* v2, size_t dim, vec_producto_interno_t producto) {

    if (dim == 0) return false;

    vec_producto_interno_t pi = !producto ? vec_producto_canonico : producto;

    return (pi(v1, v2, dim) == 0);

}
