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
