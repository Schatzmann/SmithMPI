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

#define TAM_BLOCO 3 

/* Retorna a direção máxima entre os 3 elementos calculados, caso todos sejam negativos, retorna 0 */
int maxDirecao(int diagonal, int topo, int esquerda){
	int max = 0;

	if(diagonal > max)
		max = diagonal;

	if(topo > max)
		max = topo;

	if(esquerda > max)
		max = esquerda;

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

	int score, diag, topo, esq;

	
	for(int i = 1; i < TAM_BLOCO; i++){
		for(int j = 1; j < TAM_BLOCO; j++){
			score = sequencias.seqA[j - 1] == sequencias.seqB[i - 1] ? MATCH : MISMATCH;
			diag = matrizValores[j - 1][i - 1] + score;
			topo = matrizValores[j - 1][i] + GAP;
			esq = matrizValores[j][i - 1] + GAP;
			matrizValores[i][j] = maxDirecao(diag, topo, esq);
		}
	}

	for(int k = TAM_BLOCO; k < coluna; k += TAM_BLOCO){
		for(int i = 1; i < TAM_BLOCO; i++){
			for(int j = k; j < (k + TAM_BLOCO); j++){
				score = sequencias.seqA[j - 1] == sequencias.seqB[i - 1] ? MATCH : MISMATCH;
				diag = matrizValores[j - 1][i - 1] + score;
				topo = matrizValores[j - 1][i] + GAP;
				esq = matrizValores[j][i - 1] + GAP;
				matrizValores[i][j] = maxDirecao(diag, topo, esq);
			}
			
		}
	}

	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			printf("%d ", matrizValores[i][j]);
		}
		printf("\n");
	}

}


/* Realizando Backtrace */
void Backtrace(int** matrizPosicao, TSequencias *sequencias, TPosicao *posicao){
	char *alinhamentoOtimoB, *alinhamentoOtimoA, lacuna;

	lacuna = '-';

	/*TESTE
	posicao->linha = 5;
	posicao->coluna = 5;

	posicao->linha = posicao->linha - 1;
	printf("%d %d\n",posicao->linha, posicao->coluna);
	*/
	
	alinhamentoOtimoA = (char*) malloc(sizeof(char) * sequencias->tamSeqA);
	alinhamentoOtimoB = (char*) malloc(sizeof(char) * sequencias->tamSeqB);

	while(matrizPosicao[posicao->linha][posicao->coluna] > 0){
		if (matrizPosicao[posicao->linha][posicao->coluna] == DIAGONAL){
			strcat(alinhamentoOtimoA, (sequencias->seqA - 1));
			strcat(alinhamentoOtimoB, (sequencias->seqB - 1));

			posicao->linha = posicao->linha - 1;  
			posicao->coluna = posicao->coluna - 1;
		}

		if (matrizPosicao[posicao->linha][posicao->coluna] == TOPO){
			strcat(alinhamentoOtimoA, &lacuna);
			strcat(alinhamentoOtimoB, (sequencias->seqB - 1));

			posicao->linha = posicao->linha - 1;
		}

		if (matrizPosicao[posicao->linha][posicao->coluna] == ESQUERDA){
			strcat(alinhamentoOtimoA, (sequencias->seqA - 1));
			strcat(alinhamentoOtimoB, &lacuna);

			posicao->coluna = posicao->coluna - 1;      //posMaior[lin][col] = posMaior[lin][col -1];
		}
	}


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