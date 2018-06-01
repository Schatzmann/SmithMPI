#ifndef __SMITH__
#define __SMITH__

typedef struct TSequencias{
	int tamSeqA, tamSeqB;
	char *seqA, *seqB;
} TSequencias;

int** alocarMatriz(int, int);
void lerSequencias(char*, TSequencias*);

#endif