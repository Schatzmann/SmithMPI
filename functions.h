/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#ifndef __SMITH__
#define __SMITH__

typedef struct TSequencias{
	int tamSeqA, tamSeqB;
	char *seqA, *seqB;
} TSequencias;

typedef struct TPosicao{
	int linha, coluna;
} TPosicao;

int** alocarMatriz(int, int);
void lerSequencias(char*, TSequencias*);
void calcSmithWaterman(int**, int**, int, int, TSequencias, TPosicao);

#endif