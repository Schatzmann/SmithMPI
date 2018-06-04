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
	TPosicao maiorElemento;
	int **matrizValores, **matrizPosicao, linMatriz, colMatriz;

	lerSequencias(argv[1], &sequencias);

	linMatriz = sequencias.tamSeqB + 1;
	colMatriz = sequencias.tamSeqA + 1;
	
	matrizValores = alocarMatriz(linMatriz, colMatriz);
	matrizPosicao = alocarMatriz(linMatriz, colMatriz);

	calcSmithWaterman(matrizValores, matrizPosicao, linMatriz, colMatriz, sequencias, &maiorElemento);

	return 0;
}