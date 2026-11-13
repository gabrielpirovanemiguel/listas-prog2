#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int linhas, int colunas);
void preenche_vetor(int *vetor, int colunas);
void soma_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]);
void multiplica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]);
int soma_diagonal(int **matriz, int colunas);

int main() {
    int linhas = 3, colunas = 3;
    int **matriz1 = cria_matriz(linhas, colunas);
    int **matriz2 = cria_matriz(linhas, colunas);
    int matriz3[linhas][colunas];
    soma_matrizes(matriz1, matriz2, linhas, colunas, matriz3);
    int diagonal1 = soma_diagonal(matriz1, colunas);
    int diagonal2 = soma_diagonal(matriz2, colunas);
    int matriz4[linhas][colunas];
    multiplica_matrizes(matriz1, matriz2, linhas, colunas, matriz4);
    printf("\nDiagonal 1: %d", diagonal1);
    printf("\nDiagonal 2: %d\n", diagonal2);
    return 0;
}


int **cria_matriz(int linhas, int colunas) {
    int **matriz;
    matriz = (int **) malloc(linhas*sizeof(int*));
    if(matriz == NULL) {printf("Erro de memória."); exit(1);}
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas*sizeof(int));
        if(matriz[i] == NULL) {printf("Erro de memória."); exit(1);}
        preenche_vetor(matriz[i], colunas);
    }
    return matriz;
}

void preenche_vetor(int *vetor, int colunas) {
    for (int i = 0; i < colunas; i++)
        vetor[i] = i +3;
}

void soma_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]) {
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
}

void multiplica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matriz3[i][j] = 0;
            for(int k = 0; k < colunas; k++) {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int soma_diagonal(int **matriz, int colunas) {
    int soma = 0;
    for(int j = 0; j < colunas; j++)
        soma += matriz[j][j];
    return soma;
}
