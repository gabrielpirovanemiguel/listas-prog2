 #include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int linhas, int colunas);
int **cria_matriz_transposta(int **matriz, int linhas, int colunas);
void preenche_matriz(int **matriz, int linhas, int colunas);
int verifica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas);

void main() {
    int colunas = 3, linhas = 3;
	int **matriz = cria_matriz(linhas, colunas);
    preenche_matriz(matriz, linhas, colunas);
    int **matriz_t = cria_matriz_transposta(matriz, linhas, colunas);
    int verificacao = verifica_matrizes(matriz, matriz_t, linhas, colunas);
    verificacao == 1? printf("Matrizes iguais.\n") : printf("Matrizes diferentes.\n");
}

void preenche_matriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = 2;
}

int verifica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            if(matriz1[i][j] != matriz2[i][j])
                return 0;
    return 1;
}

int **cria_matriz(int linhas, int colunas) {
    int **matriz;
    matriz = (int **) malloc(linhas*sizeof(int*));
    if(matriz == NULL) {printf("Erro de memória."); exit(1);}
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas*sizeof(int));
        if(matriz[i] == NULL) {printf("Erro de memória."); exit(1);}
    }
    return matriz;
}

int **cria_matriz_transposta(int **matriz, int linhas, int colunas) {
    int **matriz_t = cria_matriz(linhas, colunas);
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matriz_t[i][j] = matriz[j][i];
    return matriz_t;
}
