#include <stdio.h>
#include <stdlib.h>

void preenche_matriz(int **matriz, int n_linhas, int n_colunas) {
	for (int i = 0; i < n_linhas; i++)
		for (int j = 0; j < n_colunas; j++) 
			matriz[i][j] = 80;
}

int **cria_matriz(int n_linhas, int n_colunas) {
	int **matriz;
	matriz = (int **) malloc(n_linhas * sizeof(int *));
	if (matriz == NULL) {printf("Erro."); exit(1);}
	for (int i = 0; i < n_linhas; i++) {
		matriz[i] = (int *) malloc(n_colunas* sizeof(int));
		if (matriz[i] == NULL) {printf("Erro."); exit(1);}
	}
	return matriz;
}



float **libera_matriz(int **matriz, int tamanho) {
	if (matriz != NULL) {
		for (int i = 0; i < tamanho; i++)
			if(matriz[i] != NULL) {free(matriz[i]);}
		free(matriz);	
	}	
	return NULL;
}

void main() {
	int linhas = 3, colunas = 3, count = 0;
	int **matriz_A = cria_matriz(linhas, colunas);
	int **matriz_B = cria_matriz(linhas, colunas);
	preenche_matriz(matriz_A, linhas, colunas);
	preenche_matriz(matriz_B, linhas, colunas);
	int **matriz_C = cria_matriz(linhas, colunas);
	for (int i = 0; i < linhas; i++) 
		for (int j = 0; j < colunas; j++)
			matriz_C[i][j] = matriz_A[i][j] + matriz_B[i][j];
	libera_matriz(matriz_A, linhas);
	libera_matriz(matriz_B, linhas);
	for (int i = 0; i < linhas; i++)
		for (int j = 0; j < colunas; j++) {
			if (count == 3) {
				printf("\n%d ", matriz_C[i][j]);
				count = 1;
				continue;
			}
			printf("%d ", matriz_C[i][j]);
			count++;
		}
	printf("\n");
	libera_matriz(matriz_C, linhas);
}
