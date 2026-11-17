/* ========================================================
 * EXERCÍCIO 1
 * ======================================================== */

#include <stdio.h>
#define N_LINHAS 3
#define N_COLUNAS 3

int verifica_valor_matriz(int n_colunas, int n_linhas, int a[n_linhas][n_colunas], int b[n_linhas][n_colunas]);

void main()
{
    int a[N_LINHAS][N_COLUNAS] = {{1, 2, 1}, {0, 2, 2}, {3, 0, 1}};
    int b[N_LINHAS][N_COLUNAS] = {{1, 12, 1}, {0, 2, 2}, {3, 0, 1}};
    int verifica = verifica_valor_matriz(N_COLUNAS, N_LINHAS, a, b);
    if (verifica == 1)
        printf("As matrizes possuem o mesmo valor.\n");
    else
        printf("As matrizes não possuem o mesmo valor.\n");
}

int verifica_valor_matriz(int n_colunas, int n_linhas, int a[n_linhas][n_colunas], int b[n_linhas][n_colunas])
{
    int v[n_linhas];
    for (int i = 0; i < n_linhas; i++) {
        int soma_a = 0, soma_b = 0;
        for (int j = 0; j < N_COLUNAS; j++)
        {
            soma_a += a[i][j];
            soma_b += b[i][j];
        }
        if (soma_a != soma_b)
            return 0;
        else
            v[i] = soma_a;
    }

    for (int i = 1; i < N_LINHAS; i++)
        if (v[i - 1] != v[i])
            return 0;
    return 1;
}


/* ========================================================
 * EXERCÍCIO 2
 * ======================================================== */

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


/* ========================================================
 * EXERCÍCIO 3
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int linhas, int colunas);
int **cria_matriz_transposta(int **matriz, int linhas, int colunas);
void preenche_matriz(int **matriz, int linhas, int colunas);
int verifica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas);
void libera_matriz(int **matriz, int linhas);

void main() {
    int colunas = 3, linhas = 3;
	int **matriz = cria_matriz(linhas, colunas);
    preenche_matriz(matriz, linhas, colunas);
    int **matriz_t = cria_matriz_transposta(matriz, linhas, colunas);
    int verificacao = verifica_matrizes(matriz, matriz_t, linhas, colunas);
    verificacao == 1? printf("Matrizes iguais.\n") : printf("Matrizes diferentes.\n");
    libera_matriz(matriz, linhas);
    libera_matriz(matriz_t, linhas);
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

void libera_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}


/* ========================================================
 * EXERCÍCIO 4
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO 100

char **preenche_matriz(char **matriz, int *linhas, int maximo);
float calcula_media(char **matriz, int *linhas);
float calcula_variancia(char **matriz, int media, int *linhas);
void libera_matriz(char **matriz, int *linhas);

int main() {
    static int linhas = 0;
    char **matriz;
    float media, variancia;
    matriz = preenche_matriz(matriz, &linhas, MAXIMO);
    media = calcula_media(matriz, &linhas);
    variancia = calcula_variancia(matriz, media, &linhas);
    libera_matriz(matriz, &linhas);
    printf("Média: %f\n", media);
    printf("Variância: %f\n", variancia);
    return 0;
}

char **preenche_matriz(char **matriz, int *linhas, int maximo) {
    int i = 0, j = 0, tamanho_novo = 0;
    matriz = (char**) malloc(sizeof(char*));
    char terminador[] = "fim";
    while (1) {
        char *nome = (char*) malloc(maximo*sizeof(char));
        if(nome == NULL) {printf("Erro de memória"); exit(1);}
        printf("\nDigite um nome: ");
        scanf("%100s", nome);
        int resultado = strcmp(nome, terminador);
        if (resultado == 0) {
            free(nome);
            break;
        }
        int bytes_utilizados = strlen(nome) + 1;
        char *temp = (char*) realloc(nome, bytes_utilizados);
        if (temp == NULL) {free(nome);}
        nome = temp;
        matriz[i] = nome;
        (*linhas)++;
        int tamanho_novo = (*linhas + 1)*sizeof(char*);
        i++;
        matriz = (char**) realloc(matriz, tamanho_novo);
        if(matriz == NULL) {printf("Erro de memória"); exit(1);}
    }
    return matriz;
}

float calcula_media(char **matriz, int *linhas) {
    int soma = 0;
    for (int i = 0; i < *linhas; i++){
        printf("%s\n", matriz[i]);
        soma += strlen(matriz[i]);
    }
    float media = soma / (float)*linhas;
    return media;
}

float calcula_variancia(char **matriz, int media, int *linhas) {
    float variancia = 0;
    for (int i = 0; i < *linhas; i++) {
        variancia += (media - strlen(matriz[i])) * (media - strlen(matriz[i]));
    }
    return variancia;
}

void libera_matriz(char **matriz, int *linhas) {
    for(int i = 0; i < *linhas; i++)
        free(matriz[i]);
    free(matriz);
}


/* ========================================================
 * EXERCÍCIO 5
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int linhas, int colunas);
void preenche_vetor(int *vetor, int colunas);
void soma_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]);
void multiplica_matrizes(int **matriz1, int **matriz2, int linhas, int colunas, int matriz3[linhas][colunas]);
int soma_diagonal(int **matriz, int colunas);
void libera_matriz(int **matriz, int linhas);

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
    libera_matriz(matriz1, linhas);
    libera_matriz(matriz2, linhas);
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

void libera_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}


/* ========================================================
 * EXERCÍCIO 6
 * ======================================================== */

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


/* ========================================================
 * EXERCÍCIO 7
 * ======================================================== */

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



/* ========================================================
 * EXERCÍCIO 8
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *vetor, int tamanho);
void quick_sort(int *vetor, int inicio, int fim);

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main() {
    int vetor1[] = {3,4,5,7,8};
    int vetor2[] = {3,4,5,7,8};
    int vetor3[] = {3,4,5,7,8};
    int tamanho_v1 = sizeof(vetor1) / sizeof(vetor1[0]);
    int tamanho_v2 = sizeof(vetor2) / sizeof(vetor2[0]);
    int tamanho_v3 = sizeof(vetor3) / sizeof(vetor3[0]);
    bubble_sort(vetor1, tamanho_v1);
    for (int i = 0; i < tamanho_v1; i++)
        printf("%d ", vetor1[i]);
    printf("\n");
    quick_sort(vetor2, 0, tamanho_v2-1);
    for (int i = 0; i < tamanho_v2; i++)
        printf("%d ", vetor2[i]);
    printf("\n");
    qsort(vetor3, tamanho_v3, sizeof(int), compara);
    for (int i = 0; i < tamanho_v3; i++)
        printf("%d ", vetor3[i]);
    printf("\n");
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i+1], &vetor[fim]);
    return (i+1);
}

void quick_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int particao = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, particao -1);
        quick_sort(vetor, particao + 1, fim);
    }
}


void bubble_sort(int *vetor, int tamanho) {
    for(int i = 0;  i < tamanho - i; i++)
        for (int j = 0; j < i - tamanho - i; j++) {
            if (vetor[j] > vetor[j+1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
}
