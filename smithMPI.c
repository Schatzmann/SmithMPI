/*-------------------------------------------------------------------------------------------------------
  Annelyse Schatzmann - GRR20151731
  Eduardo Zimermam Pereira - GRR20152952  
-------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
	int **matriz;
	int col, lin;

	col = 10;
	lin = 10;

	matriz = alocarMatriz(lin, col);

	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}