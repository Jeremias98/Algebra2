#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef double (*vec_producto_interno_t) (const double*, const double*, size_t);

double** ortogonalizar(double** base);

double vector_norma(double* vector, size_t dim, vec_producto_interno_t producto);

double vec_producto_canonico(const double* v1, const double* v2, size_t dim);

bool vec_son_ortogonales(const double* v1, const double* v2, size_t dim, vec_producto_interno_t producto);

#endif // ALGEBRA_H
