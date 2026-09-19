#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2
*/

/*
char *compactar(char *s);


char *compactar(char *s);

int main(void)
{
    char s[81];

    scanf("%[^\n]", s);

    char *compact = compactar(s);

    printf("compactado: '%s'\n", compact);

    free(compact);

    return 0;
}

char *compactar(char *s)
{
    int spaceleft = 0;

    char *copia = malloc((strlen(s) + 1) * sizeof(char));

    if (copia == NULL)
        exit(1);

    for (int i = 0; i <= strlen(s); i++)
        copia[i] = s[i];
   

    for (int i = strlen(copia) - 1; i >= 0; i--)
    {
        if (copia[i] != ' ')
        {
            copia[i + 1] = '\0';
            break;
        }
    }

    while (copia[spaceleft] == ' ')
        spaceleft++;

    
    int j = 0;

    for (int i = spaceleft; copia[i] != '\0'; i++)
    {
        copia[j] = copia[i];
        j++;
    }

    copia[j] = '\0';

    return copia;
}

*/


/*
3
*/

int *aprovados(int n, int *mat, float *notas, int *tam);

int main(void)
{
    int n;
    int *mat;
    float *notas;
    int *tam;
    int *aprov;


    printf("quantidade de alunos: ");
    scanf("%d", &n);

    mat = (int *)malloc(n *sizeof(int));
    notas = (float *)malloc(n *sizeof(float));

    if (mat == NULL || notas == NULL)
        exit(1);

    for (int i=0;i<n;i++)
    {
        printf("\nmatricula do %do aluno: ", i+1);
        scanf("%d", &mat[i]);
        printf("nota do %do aluno: ", i+1);
        scanf("%f", &notas[i]);
    }

    aprov = aprovados(n, mat, notas, tam);

    printf("\n\nalunos aprovados: %d\n", *tam);
    for (int i=0;i<*tam;i++)
    {
        printf("matricula: %d\n", aprov[i]);
    }

    free(mat);
    free(notas);
    return 0;
}

int *aprovados(int n, int *mat, float *notas, int *tam)
{
    int count = 0;
    int j = 0; //contador pro vet de aprovads

    for (int i=0;i<n;i++)
    {
        if (notas[i] >= 5.0)
            count++;
    }
    *tam = count;

    int *aprov = (int *)malloc(count * sizeof(int));

    if (aprov == NULL)
        exit(1);

    
    for (int i=0;i<n;i++)
    {

        if (notas[i] >= 5.0)
        {
            aprov[j] = mat[i];
            j++;
        }
    }
    return aprov;
}