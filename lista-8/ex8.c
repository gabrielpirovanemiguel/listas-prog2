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
