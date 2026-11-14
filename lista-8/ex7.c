#include <stdio.h>
#define LINHAS 5
#define COLUNAS 5

int mostra_distancia(int matriz[LINHAS][COLUNAS]);
void imprime_tabela_sem_repeticoes(int matriz[LINHAS][COLUNAS]);
int calcula_perscurso(int *vetor, int matriz[LINHAS][COLUNAS], int tamanho);

int main() {
    int matriz[LINHAS][COLUNAS] = {
        {0, 15, 30,  5, 12},
        {15, 0, 10, 17, 28},
        {30, 10, 0,  3, 11},
        {5, 17,  3,  0, 80},
        {12, 28, 11, 80, 0}
    };
    mostra_distancia(matriz);
    imprime_tabela_sem_repeticoes(matriz);
    int percurso[] = {1,2,3,2,5,1,4};
    int tamanho = sizeof(percurso) / sizeof(percurso[0]);
    calcula_perscurso(percurso, matriz, tamanho);
    return 0;
}

int mostra_distancia(int matriz[LINHAS][COLUNAS]) {
    while (1) {
        int cidade1, cidade2;
        printf("Digite o número da cidade A: ");
        scanf("%d", &cidade1);
        printf("Digite o número da cidade B: ");
        scanf("%d", &cidade2);
        if (cidade1 == 0 && cidade2 == 0)
            return 0;
        int index_linha = cidade2 - 1;
        int index_coluna = cidade1 - 1;
        int distancia = matriz[index_linha][index_coluna];
        printf("Distância entre cidade %d e cidade %d: %d\n", cidade1, cidade2, distancia);
        return distancia;
    }

}

void imprime_tabela_sem_repeticoes(int matriz[LINHAS][COLUNAS]) {
    int coluna_inicial = 0;
    printf("    1  2  3  4  5 \n");
    for(int i = 0; i < LINHAS; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < COLUNAS; j++) {
            if(j < coluna_inicial){
                printf("   ");
                continue;
            }
            printf(" %02d", matriz[i][j]);
        }
        printf(" |\n");
        coluna_inicial++;
    }
}

int calcula_perscurso(int *vetor, int matriz[LINHAS][COLUNAS], int tamanho) {
    int distancia = 0;
    int indice_l = 0, indice_c = 0;
    for (int i = 0; i < tamanho; i++) {
        if (i+1 >= tamanho)
            break;
        indice_c = vetor[i]-1;
        indice_l = vetor[i+1]-1;
        distancia += matriz[indice_l][indice_c];
        if (i != 0)
            printf("+ ");
        printf("%d ", matriz[indice_l][indice_c]);
    }
    printf("= %d km\n", distancia);
}

