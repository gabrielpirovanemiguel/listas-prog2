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