#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef double (*vec_producto_interno_t) (const double*, const double*, size_t);

double** ortogonalizar(double** base, size_t columnas, size_t filas, vec_producto_interno_t producto);

double vec_norma(double* vector, size_t dim, vec_producto_interno_t producto);

double vec_producto_interno_canonico(const double* v1, const double* v2, size_t dim);

bool vec_son_ortogonales(const double* v1, const double* v2, size_t dim, vec_producto_interno_t producto);

double* vec_producto_escalar(const double escalar, const double* vector, size_t dim);

double* vec_sumar(const double* v1, const double* v2, size_t dim);

double* vec_proyeccion_ortogonal(double** base_ortogonal, const double* vector, size_t dim, vec_producto_interno_t producto);

void vec_imprimir(double* vector, size_t dim);

#endif // ALGEBRA_H
