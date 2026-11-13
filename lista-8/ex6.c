#include <stdlib.h>
#include <stdio.h>
#define ORDEM 8
#define PEAO 1
#define CAVALO 2
#define TORRE 3
#define BISPO 4
#define REI 5
#define RAINHA 6
#define VAZIO 0

void soma_bispos_peoes_vazios(int linhas, int colunas, int tabuleiro[linhas][colunas], int *qntd_peao, int *qntd_bispo, int *qntd_vazio);
void conta_pecas(int linhas, int colunas, int tabuleiro[linhas][colunas], int qntd_peao, int qntd_bispo);

void main() {
    int tabuleiro[ORDEM][ORDEM] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };
    int qntd_peao = 0, qntd_bispo = 0, qntd_vazio = 0;
    soma_bispos_peoes_vazios(ORDEM, ORDEM, tabuleiro, &qntd_peao, &qntd_bispo, &qntd_vazio);
    printf("\nSoma de bispos e peões: %d\n", qntd_peao + qntd_bispo);
    printf("Quantidade de posições vazias: %d\n", qntd_vazio);
    conta_pecas(ORDEM, ORDEM, tabuleiro, qntd_peao, qntd_bispo);
}

void soma_bispos_peoes_vazios(int linhas, int colunas, int tabuleiro[linhas][colunas], int *qntd_peao, int *qntd_bispo, int *qntd_vazio) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (tabuleiro[i][j] == PEAO)
                (*qntd_peao)++;
            else if (tabuleiro[i][j] == BISPO)
                (*qntd_bispo)++;
            else if(tabuleiro[i][j] == VAZIO)
                (*qntd_vazio)++;
        }
    }
}

void conta_pecas(int linhas, int colunas, int tabuleiro[linhas][colunas], int qntd_peao, int qntd_bispo) {
    int qntd_cavalo = 0, qntd_torre = 0, qntd_rei = 0, qntd_rainha = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            switch(tabuleiro[i][j]) {
                case CAVALO:
                    qntd_cavalo++;
                    break;
                case TORRE:
                    qntd_torre++;
                    break;
                case REI:
                    qntd_rei++;
                    break;
                case RAINHA:
                    qntd_rainha++;
                    break;
            }
        }
    }
    printf("Quantidade de cavalos: %d\n", qntd_cavalo);
    printf("Quantidade de torres: %d\n", qntd_torre);
    printf("Quantidade de peões: %d\n", qntd_peao);
    printf("Quantidade de bispos: %d\n", qntd_bispo);
    printf("Quantidade de rainhas: %d\n", qntd_rainha);
    printf("Quantidade de reis: %d\n", qntd_rei);
}
