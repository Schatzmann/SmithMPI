/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	TSequencias sequencias;
	TPosicao posicao;
	int **matrizValores, **matrizPosicao, linMatriz, colMatriz;

	linMatriz = sequencias.tamSeqB + 1;
	colMatriz = sequencias.tamSeqA + 1;

	lerSequencias(argv[1], &sequencias);
	
	matrizValores = alocarMatriz(linMatriz, colMatriz);
	matrizPosicao = alocarMatriz(linMatriz, colMatriz);

	calcSmithWaterman(matrizValores, matrizPosicao, linMatriz, colMatriz, sequencias);
	Backtrace(matrizPosicao, &sequencias, &posicao);

	return 0;
}