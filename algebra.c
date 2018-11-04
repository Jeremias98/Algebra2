#include "algebra.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Declaro una macro foreach
#define foreach(item, array) \
  for(int keep = 1, \
          count = 0,\
          size = sizeof (array) / sizeof *(array); \
      keep && count <= size; \
      keep = !keep, count++) \
    for(item = *(array + count); keep; keep = !keep)

void vec_imprimir(double* vector, size_t dim) {
    printf("( ");
	for (size_t i = 0; i < dim; i++) {
		printf("%0.3f ", vector[i]);
	}
	printf(")");
}

double vec_producto_interno_canonico(const double* v1, const double* v2, size_t dim) {

    if (dim == 0) return -1;

    double resultado = 0;

    for (size_t i = 0; i < dim; i++) {
        resultado = resultado + (v1[i] * v2[i]);
    }

    return resultado;
}

double* vec_producto_escalar(const double escalar, const double* vector, size_t dim) {

    double* resultado = malloc(dim * sizeof(double));

    for (size_t i = 0; i < dim; i++) {
        resultado[i] = escalar * vector[i];
    }

    return resultado;

}

double** ortogonalizar(double** base, size_t columnas, size_t filas, vec_producto_interno_t producto) {
    /*
    vec_producto_interno_t pi = !producto ? vec_producto_interno_canonico : producto;
    // Componentes de la base
    double* vk = malloc(columnas * sizeof(double));
    // Componentes de la base ortogonal
    double* ei = malloc(columnas * sizeof(double));
    double** base_og = malloc(columnas * sizeof(double*));

    ei = base[k];
    base_og[0] = ei;
    for (size_t k = 0; k < columnas; k++) {
        vk = base[k];
        for (size_t i = 0; i < filas; i++) {
            //double prod = pi(vk, )
        }
    }

    free(vk);
    */

    return NULL;
}

double* vec_proyeccion_ortogonal(double** base_ortogonal, const double* vector, size_t dim, vec_producto_interno_t producto) {

    vec_producto_interno_t pi = !producto ? vec_producto_interno_canonico : producto;
    double* proyeccion = NULL;
    double* proy_aux = malloc(dim * sizeof(double));
    for (size_t i = 0; i < dim; i++) {
        proy_aux[i] = 0;
    }
    double* vec_parcial = NULL;

    foreach(double* ei, base_ortogonal) {
        // Producto interno del vector a proyectar con el de la base
        double prd = pi(vector, ei, dim);
        // La norma al cuadrado es el producto interno del vector de la base por si mismo
        double norma_cuadrado = pi(ei, ei, dim);
        // Divido el producto por la norma y lo multiplico escalarmente con el vector de la base
        vec_parcial = vec_producto_escalar(prd/norma_cuadrado, ei, dim);
        
        // Guardo el puntero para liberar memoria
        double* puntero = proy_aux;

        // La proyección es la suma de estos resultados
        proyeccion = vec_sumar(proy_aux, vec_parcial, dim);
        proy_aux = proyeccion;

        free(puntero);
        free(vec_parcial);
    }

    return proyeccion;

}

double vec_norma(double* vector, size_t dim, vec_producto_interno_t producto) {

    if (dim == 0) return -1;

    vec_producto_interno_t pi = !producto ? vec_producto_interno_canonico : producto;

    return sqrt(pi(vector, vector, dim));

}

bool vec_son_ortogonales(const double* v1, const double* v2, size_t dim, vec_producto_interno_t producto) {

    if (dim == 0) return false;

    vec_producto_interno_t pi = !producto ? vec_producto_interno_canonico : producto;

    return (pi(v1, v2, dim) == 0);

}

double* vec_sumar(const double* v1, const double* v2, size_t dim) {

    double* resultado = malloc(dim * sizeof(double));

    for (size_t i = 0; i < dim; i++) {
        resultado[i] = v1[i] + v2[i];
    }

    return resultado;

}
