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
	int **matrizValores, **matrizPosicao;

	lerSequencias(argv[1], &sequencias);
	
	matrizValores = alocarMatriz((sequencias.tamSeqB + 1), (sequencias.tamSeqA + 1));

	return 0;
}