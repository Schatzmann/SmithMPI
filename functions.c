/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


#define MATCH     2
#define MISMATCH -1
#define GAP      -1

#define TOPO     3
#define DIAGONAL 2
#define ESQUERDA 1

/* Retorna a direção máxima entre os 3 elementos calculados, caso todos sejam negativos, retorna 0 */
int maxDirecao(int diagonal, int topo, int esquerda){
	int max = 0;

	if(diagonal > max)
		max = DIAGONAL;

	if(topo > max)
		max = TOPO;

	if(esquerda > max)
		max = ESQUERDA;

	return max;
}

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
void calcSmithWaterman(int** matrizValores, int** matrizPosicao, int linha, int coluna, TSequencias sequencias){
	printf("CALCULANDO SMITH-WATERMAN\n");

	int qtdeDiagonais, score, diag, topo, esq, valorMaiorElem;

	qtdeDiagonais = (linha + coluna) - 1;

	/* Calculo do primeiro elemento da matriz */
	score = sequencias.seqA[0] == sequencias.seqB[0] ? MATCH : MISMATCH;
	diag = matrizValores[0][0] + score;
	topo = matrizValores[0][1] + GAP;
	esq = matrizValores[1][0] + GAP;
	matrizPosicao[1][1] = maxDirecao(diag, topo, esq);



	// for (int i = 0; i < linha; ++i){
	// 	for (int j = 0; j < coluna; ++j){
	// 		printf("%d ", matrizValores[i][j]);
	// 	}
	// 	printf("\n");
	// }
}


/* Realizando Backtrace */
void Backtrace(int** matrizPosicao, TSequencias *sequencias, TPosicao *posicao){
	char *alinhamentoOtimoB, *alinhamentoOtimoA, lacuna;

	lacuna = '-';

	/*TESTE*/
	posicao->linha = 5;
	posicao->coluna = 5;

	posicao->linha = posicao->linha - 1;
	printf("%d %d\n",posicao->linha, posicao->coluna);
	
	/*TESTE*/
	
	alinhamentoOtimoA = (char*) malloc(sizeof(char) * sequencias->tamSeqA);
	alinhamentoOtimoB = (char*) malloc(sizeof(char) * sequencias->tamSeqB);

	/*while(matrizPosicao[posicao->linha][posicao->coluna] > 0){
		if (matrizPosicao[posicao->linha][posicao->coluna] == DIAGONAL){
			strcat(alinhamentoOtimoA, (&sequencias->seqA - 1));
			strcat(alinhamentoOtimoB, (&sequencias->seqB - 1));

			posicao->linha = posicao->linha - 1;  
			posicao->coluna = posicao->coluna - 1;
		}

		if (matrizPosicao[posicao->linha][posicao->coluna] == TOPO){
			strcat(alinhamentoOtimoA, &lacuna);
			strcat(alinhamentoOtimoB, (&sequencias->seqB - 1));

			posicao->linha = posicao->linha - 1;
		}

		if (matrizPosicao[posicao->linha][posicao->coluna] == ESQUERDA){
			strcat(alinhamentoOtimoA, (&sequencias->seqA - 1));
			strcat(alinhamentoOtimoB, &lacuna);

			posicao->coluna = posicao->coluna - 1;      //posMaior[lin][col] = posMaior[lin][col -1];

		}
	}*/


	alinhamentoOtimoA = "GATCGA";	
	alinhamentoOtimoB = "AGCTAG";

	for(int i = (sequencias->tamSeqA); i >= 0; i--){
		printf("%c", alinhamentoOtimoA[i]);
   	}

   	printf("\n");

   	for(int i = (sequencias->tamSeqB); i >= 0; i--){
   		printf("%c", alinhamentoOtimoB[i]);
    }

    printf("\n");
  	
}