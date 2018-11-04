#include "algebra.h"
#include <stdlib.h>
#include <stdio.h>

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count <= size; \
        keep = !keep, count++) \
      for(item = *(array + count); keep; keep = !keep)

int procesar_entrada(char* archivo) {

	FILE* entrada = !archivo ? stdin : fopen(archivo, "r");

    if (archivo) fclose(entrada);

    double vector_1[3] = {1,2,2};
    double vector_2[3] = {-2,2,-1};

    printf("%f\n", vec_norma(vector_1, 3, NULL));
    printf("%f\n", vec_producto_interno_canonico(vector_1, vector_2, 3));
    printf("Son ortogonales: %d\n", vec_son_ortogonales(vector_1, vector_2, 3, NULL));

	double* vector_3 = vec_producto_escalar(5, vector_1, 3);
	vec_imprimir(vector_3, 3);
	printf("\n");

	free(vector_3);

	vec_imprimir(vector_1, 3);
	printf(" + ");
	vec_imprimir(vector_2, 3);
	printf(" = ");
	double* vector_suma = vec_sumar(vector_1, vector_2, 3);
	vec_imprimir(vector_suma, 3);
	printf("\n");
	free(vector_suma);

	double** base_1 = malloc(2 * sizeof(double*));
	double* e1 = malloc(3 * sizeof(double));
	e1[0] = 1;e1[1] = 2;e1[2] = 2;
	double* e2 = malloc(3 * sizeof(double));
	e2[0] = -2;e2[1] = 2;e2[2] = -1;
	base_1[0] = e1;base_1[1] = e2;
	
	double v[3] = {2,0,1};
	double* vec_proy = vec_proyeccion_ortogonal(base_1, v, 3, NULL);
	vec_imprimir(vec_proy, 3);
	free(vec_proy);

	foreach(double* p, base_1) {
		free(p);
	}
	free(base_1);

    return 0;
}

int main(int argc, char *argv[])
{
    char* archivo = NULL;
    if (argc == 2) {
        archivo = argv[1];
    }

    return procesar_entrada(archivo);
}
