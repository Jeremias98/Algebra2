#include "algebra.h"
#include <stdlib.h>
#include <stdio.h>

int procesar_entrada(char* archivo) {

	FILE* entrada = !archivo ? stdin : fopen(archivo, "r");

    if (archivo) fclose(entrada);

    double vector_1[3] = {1,2,2};
    double vector_2[3] = {-2,2,-1};

    printf("%f\n", vector_norma(vector_1, 3, NULL));
    printf("%f\n", vec_producto_canonico(vector_1, vector_2, 3));
    printf("Son ortogonales: %d\n", vec_son_ortogonales(vector_1, vector_2, 3, NULL));

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
