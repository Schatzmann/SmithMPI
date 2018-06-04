/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

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

/* Função responsável pela abertura e leitura do arquivo de sequencias */
void lerSequencias(char* nomeArquivo, TSequencias *sequencias){
	FILE *arq;
	char *seqArquivo;
	int tamSequenciaA, tamSequenciaB;

  arq = fopen(nomeArquivo, "r");    

  if ( !arq ){
    perror("Erro ao abrir arquivo") ;
    exit(1);
  }

  fscanf(arq, "%d %d", &sequencias->tamSeqA, &sequencias->tamSeqB);

	sequencias->seqA = (char*) malloc(sizeof(char) * sequencias->tamSeqA);
	sequencias->seqB = (char*) malloc(sizeof(char) * sequencias->tamSeqB);

 	fscanf(arq, "%s %s", sequencias->seqA, sequencias->seqB);

  fclose(arq);
}

/* Calculo do algoritmo de Smith-Waterman */
void calcSmithWaterman(){
	printf("CALCULANDO SMITH-WATERMAN\n");
}
