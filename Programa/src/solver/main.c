#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Modo de uso: ./solver test.txt\n");
		return 0;
	}

	/* Abrimos el archivo input en modo de lectura */
	FILE *input_file = fopen(argv[1], "r");

	/* Abrimos el archivo output en modo de escritura */
	FILE *output_file = fopen("output.txt", "w");

	/* Revisa que el archivo fue abierto correctamente */
	if (!input_file)
	{
		printf("¡El archivo %s no existe!\n", argv[1]);
		return 2;
	}


	/* Definimos y asignamos las constantes del problema */
	int n; int m; int l;

	fscanf(input_file, "%d %d %d", &n, &m, &l);
	Stack ***matrix = malloc(n * sizeof(Stack **)); //Reserva de memoria para n (son n filas) arrays de punteros
	for (size_t i = 0; i < n; i++){
		matrix[i] = malloc(m * sizeof(Stack*)); //Reserva de memoria para m (son m columnas) punteros de Stacks
		for (size_t j = 0; j < m; j++){
			matrix[i][j] = stack_init();
	}
}
	for (int i = 0; i < l; i++)
	{
		/* Definimos las variables del problema */
		int o; int r; int c; int k;
		/* Leemos cada linea del archivo */
		fscanf(input_file, "%d %d %d %d", &o, &r, &c, &k);
		/* operación push */
		if (o == 0)
		{
			push(matrix[r][c],k, r, c);
			// printf("%d\n", k);
		}
		/* operación pop */
		else if (o == 1)
		{
			int k_node;
			int cond;
			cond = 1;
			while (cond) {
				k_node = pop(matrix[r][c]);
				printf("%d\n", k_node);
				if (k_node == -1){
					fprintf(output_file, "vacio\n" );
				}
				else {
					fprintf(output_file, "%d\n", k_node );
				}
				//printf(" POP: (%d,%d)  color popeado %d,color buscado: %d\n" , r,c,k_node, k);
			 	if (k_node == k)
				{
			 		// fprintf(output_file, "vacio\n" );
					// printf("Entré al if cuando son iguales POP: %d ,color buscado: %d\n OH YES son IGUALES" , k_node, k);
			 		cond = 0;
			 	}
				else if (k_node == -1){
					cond = 0;
				}
			 }

		}

	}

	/* Cerramos los archivos correctamente */
	fclose(input_file);
	fclose(output_file);

	///////////////// Recuerda que antes de acabar tu programa debes liberar toda la memoria reservada ///////////////////

	for (size_t i = 0; i<n; i++){
		for (size_t j = 0; j<m; j++){
			destroy(matrix[i][j]);
		}
	}
	for (size_t i = 0; i<n; i++){
		free(matrix[i]);
	}
	free(matrix);
	/* Esta linea indica que el programa termino sin errores*/
	return 0;
}
