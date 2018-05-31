/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* Função que aloca uma matriz alinhada em memória, retornando a mesma zerada para a chamada */
int** alocarMatriz(int linha, int coluna){
	int tamMatriz = linha * coluna;
	int **matrizAlocada;

	matrizAlocada = (int**) malloc(sizeof(int*) * linha);
	matrizAlocada[0] = (int*) malloc(sizeof(int) * tamMatriz);

	for(int i = 0; i < linha; i++){
			matrizAlocada[i] = (*matrizAlocada + coluna * i);
	}

	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			matrizAlocada[i][j] = 0;
		}
	}

	return(matrizAlocada);
}