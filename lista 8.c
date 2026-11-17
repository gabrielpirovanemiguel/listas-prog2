/******************************************************************************

1) Considere o tipo Funcionario, que representa um funcionário de uma empresa,
definido pela estrutura a seguir:

Escreva uma função em C que preencha um vetor de ponteiros para Funcionario com os
dados lidos de um arquivo texto. Essa função deve receber como parâmetros o vetor de
ponteiros para Funcionario (representado pelo seu comprimento e pelo endereço de seu
primeiro elemento) previamente alocado e o nome do arquivo de entrada. Nesse arquivo
de entrada, os dados de cada funcionário são armazenados em duas linhas: uma com o
seu nome (cadeia com até 80 caracteres), e outra com o valor de sua hora de trabalho e
com o número de horas trabalhadas em um mês (nessa ordem). Um exemplo desse
formato é mostrado abaixo.
João da Silva
15.0 160
Manuel Santos
15.0 80
Fulana de Tal
23.5 40
Considere que: não existem linhas em branco no arquivo; o parâmetro vet já vem com
todas as suas posições inicializadas com NULL; o comprimento do vetor (parâmetro n) é
no mínimo igual à quantidade de registros de funcionários no arquivo de entrada; se não
for possível abrir o arquivo, a função deve imprimir a mensagem “ERRO” e terminar a
execução do programa. A função implementada deve ter o seguinte protótipo:
void carrega (int n, Funcionario** vet, char* arquivo);

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numFuncionarios 3

struct funcionario {
char nome[81];
float valor_hora;
int horas_mes;
};

typedef struct funcionario Funcionario;

void carrega (int n, Funcionario** vet, char* arquivo) {
 
    FILE * arquivoAnalisado = fopen(arquivo, "r");
 
    if (arquivoAnalisado == NULL) {
        printf("ERRO");
        exit(1);
    }
 
    if (vet != NULL) {
        for (int i = 0; i < n; i++) {
            vet[i] = (Funcionario *) malloc(sizeof(Funcionario));
            fscanf(arquivoAnalisado, " %[^\n]", vet[i]->nome);
            fscanf(arquivoAnalisado, "%f", &vet[i]->valor_hora);
            fscanf(arquivoAnalisado, "%d", &vet[i]->horas_mes);
        }
    }
    else {
        printf("ERRO");
        exit(1);
    }
 
    fclose(arquivoAnalisado);
}

int main() {
 
    char nomeArquivo[100];
    Funcionario ** funcionarios = malloc(numFuncionarios * sizeof(Funcionario *));
    for (int i = 0; i < numFuncionarios; i++) {
        funcionarios[i] = NULL;
    }
 
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]", nomeArquivo);

    carrega(numFuncionarios, funcionarios, nomeArquivo);
 
    printf("\nDados carregados com sucesso:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i] != NULL) {
            printf("Nome: %s | Hora: %.2f | Horas Mes: %d\n",
                   funcionarios[i]->nome, funcionarios[i]->valor_hora, funcionarios[i]->horas_mes);
 
            free(funcionarios[i]);
        }
    }
    free(funcionarios);

    return 0;
}

/******************************************************************************

2) Considere um arquivo texto onde cada linha contém a matrícula de um aluno e seu
respectivo CR, como ilustra o exemplo a seguir:

9010087-2 7.3
8820324-3 8.7
9210478-5 9.2
9020256-8 6.7

Implemente uma função que receba como parâmetros o nome de um arquivo no formato
descrito acima e a matrícula de um aluno, e retorne o CR do aluno. Se não for encontrado
no arquivo a matrícula procurada, a função deve retornar –1.0. Se não for possível abrir o
arquivo, a função deve imprimir a mensagem "ERRO" e terminar a execução do
programa. O protótipo dessa função deve ser:
float busca (char* arquivo, char* matricula);

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula){
    FILE *arq;
    char linha[256];
    char mat[50];
    float nota;
    arq = fopen(arquivo, "r");
    if(arq==NULL){printf("ERRO"); exit(1);}
    while(fgets(linha, sizeof linha, arq)!=NULL){
        if(sscanf(linha, "%s %f", mat, &nota)==2){
            if(strcmp(mat, matricula)==0){
                return nota;
            }
        }
    }
    fclose(arq);
    return nota = -1.0;
}

int main()
{
    char matriculaNome[100];
    char matriculaNumero[100];
 
    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", matriculaNome);
    printf("Digite a matrícula do aluno do arquivo: ");
    scanf(" %[^\n]", matriculaNumero);
 
    float nota = busca(matriculaNome, matriculaNumero);
    printf("O CR da matrícula escolhida é: %.1f", nota);

    return 0;
}

/******************************************************************************

3) Considere um arquivo texto com as notas dos alunos de uma disciplina. Cada linha do
arquivo contém a matrícula de um aluno (cadeia de nove caracteres), seguida pelos
valores de suas três notas (P1, P2 e P3). Considere ainda que não existem linhas em
branco no arquivo. Um exemplo desse formato é mostrado abaixo.

9010087-2 2.0 4.3 6.5
8820324-3 7.0 8.2 8.5
9210478-5 6.0 7.5 7.8
9020256-8 3.0 0.5 4.2

Escreva uma função que receba como parâmetros o número de matrícula de um aluno e o
nome de um arquivo com as notas de uma disciplina no formato descrito acima, e retorne
a média do aluno na disciplina. A média de um aluno é calculada pela fórmula
(P1+P2+P3)/3. Caso o número de matrícula passado como parâmetro não seja encontrado
no arquivo, a função deve retornar -1.0. Por exemplo, considerando um arquivo com o
conteúdo apresentado acima, sua função deve retornar 7.9 caso o número de matrícula
passado como parâmetro seja “8820324-3”. O protótipo da função deve ser:
float media (char* mat, char* nome_arquivo);
Obs.: Se não for possível abrir o arquivo de entrada, a função deve imprimir a mensagem
“ERRO” e terminar a execução do programa.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media (char* mat, char* nome_arquivo) {
    FILE * arquivo = fopen(nome_arquivo, "r");
    char matricula[100];

    if (arquivo == NULL) {
        printf("ERRO");
        exit(1);
    }
 
    float nota1;
    float nota2;
    float nota3;
 
    while (fscanf(arquivo, "%s %f %f %f", matricula, &nota1, &nota2, &nota3) == 4) {
        if (strcmp(matricula, mat) == 0) {
            fclose(arquivo);
            return (nota1 + nota2 + nota3)/3.0;
        }
    }
 
    fclose(arquivo);
    return -1.0;
}

int main () {
    char matriculaCodigo[100];
    char nomeArquivo[100];
 
    printf("Coloque o nome do arquivo: ");
    scanf(" %[^\n]", nomeArquivo);
 
    printf("Digite a matrícula do aluno: ");
    scanf(" %[^\n]", matriculaCodigo);
 
    float mediaNota = media(matriculaCodigo, nomeArquivo);
 
    printf("Média igual a: %.2f", mediaNota);
 
    return 0;
}

/******************************************************************************

4) Faça um programa que leia um nome de “arquivo .c” digitado pelo usuário e gere um
novo que remove as linhas com comentários “//”

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
 
    char arquivoNome[100];
 
    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivoNome);
 
    FILE *arquivo = fopen(arquivoNome, "r");
    FILE *arquivoNovo = fopen("arquivoNovo.c", "w");

    if (arquivo == NULL || arquivoNovo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    char linha[200];
    int cond = 0;
 
    while (fscanf(arquivo, " %[^\n]", linha) == 1) {
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '/' && linha[i + 1] == '/') {
                cond = 1;
            }
        }
        if (cond == 0) {
            fprintf(arquivoNovo, "%s\n", linha);
        }
        cond = 0;
    }

    fclose(arquivo);
    fclose(arquivoNovo);

    return 0;
}

/******************************************************************************

5) Escreva um programa que leia de um arquivo, cujo nome será fornecido pelo usuário,
um conjunto de números reais e armazene em um vetor. O programa ao final calcula a
media dos números lidos.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nomeArquivo[100];
 
    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", nomeArquivo);
 
    FILE * arquivo = fopen(nomeArquivo, "r");
 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
 
    int numValores = 0;
    float lixo;
 
    while (fscanf(arquivo, "%f", &lixo) == 1) {
        numValores = numValores + 1;
    }
 
    if (numValores == 0) {
        printf("Arquivo sem dados!");
        exit(1);
    }
 
    float * vetor = malloc(numValores * sizeof(float));
    int i = 0;
    float media = 0;
    rewind(arquivo);
 
    while (fscanf(arquivo, "%f", &vetor[i]) == 1) {
        media = media + vetor[i];
        i = i + 1;
    }
 
    printf("Média igual a: %.2f", (media/numValores));
 
    fclose(arquivo);
    free(vetor);

    return 0;
}

/******************************************************************************

6) Faça um programa que gere 10 arquivos com o nome “testeXX”, onde XX é ”01”, ...,
”10” (exemplo: teste01.txt”). Cada arquivo deve conter dentro dele o texto ”Texto do
arquivo [NÚMERO DO ARQUIVO]”.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char vetor[12] = "teste0";
    char numero = '0';
    char vetorUltimo[] = "teste10.txt";
 
    for (int i = 1; i <= 10; i++) {
        if (i <= 9) {
            vetor[6] = numero + i;
            vetor[7] = '.';
            vetor[8] = 't';
            vetor[9] = 'x';
            vetor[10] = 't';
            vetor[11] = '\0';
            FILE * arquivoMenor = fopen(vetor, "w");
            fprintf(arquivoMenor, "%s" "%d", "Texto do arquivo 0", i);
            fclose(arquivoMenor);
        }
        else if (i == 10) {
            FILE * arquivoMaior = fopen(vetorUltimo, "w");
            fprintf(arquivoMaior, "%s", "Texto do arquivo 10");
            fclose(arquivoMaior);
        }
    }

    return 0;
}

/******************************************************************************

7) Um arquivo do tipo texto, chamado ‘‘numeros.txt’’ contém uma quantidade
desconhecida de números reais. Escreva um programa que leia estes números, os coloque
em ordem crescente e depois os grave em um arquivo binário chamado ‘‘numeros.bin’’.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * arquivo = fopen("numeros.txt", "r");
 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
 
    int numValores = 0;
    float lixo;
 
    while (fscanf(arquivo, "%f", &lixo) == 1) {
        numValores = numValores + 1;
    }
 
    if (numValores == 0) {
        printf("Não há dados no arquivo!");
        exit(1);
    }
 
    rewind(arquivo);
    float * vetor = malloc(numValores * sizeof(float));
    int i = 0;
 
    if (vetor == NULL) {
        printf("Erro de alocação de memória!");
        exit(1);
    }
 
    while (fscanf(arquivo, "%f", &vetor[i]) == 1) {
        i += 1;
    }
 
    int fim = numValores;
    for (fim = numValores - 1; fim > 0; fim--) {
        for (i = 0; i < fim; i++) {
            if (vetor[i] > vetor[i + 1]) {
                float temp = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = temp;
            }
        }
    }
 
    FILE * arquivoBinario = fopen("numeros.bin", "wb");
 
    fwrite(vetor, sizeof(float), numValores, arquivoBinario);
 
    fclose(arquivo);
    fclose(arquivoBinario);
    free(vetor);
 
    return 0;
}

/******************************************************************************

8) Escreva um programa que grave os dados de alunos conforme a estrutura abaixo em
um arquivo do tipo binário de acesso aleatório.

a. Faça uma função para mostrar os alunos que tem média maior do que 6,0.
b. Faça um menu de opções para incluir, alterar, consultar e excluir um aluno.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome [81];
    float nota1 , nota2;
} ALUNO;

int main(){
    ALUNO *turma;
    int nAlunos, i;
    char *alunos = "alunos.dat";
    printf("Quantidade de alunos: ");
    scanf("%d", &nAlunos);
    turma = (ALUNO*) malloc(nAlunos * sizeof(ALUNO));
    if(turma==NULL){ printf("Memoria Insuficiente\n"); exit(-1);}
    for(i=0; i<nAlunos; i++){        
        printf("Nome do aluno: ");
        scanf(" %80[^\n]", turma[i].nome);        

        printf("Notas 1 e 2 respectivamente: ");
        scanf("%f %f", &turma[i].nota1, &turma[i].nota2);
        printf("===================\n");
    }
    FILE *arq = fopen(alunos, "ab");
    if(arq==NULL){ printf("ERRO\n"); exit(-1); }
    fwrite(turma, sizeof(ALUNO), nAlunos, arq);
    fclose(arq);
    free(turma);
    return 0;
}
/*8a)*/
void aprovados(FILE *arquivo){
    fseek(arquivo, 0, SEEK_END);
    int tam = ftell(arquivo);
    int n = tam/sizeof(ALUNO);
    rewind(arquivo);
    if(n==0){ printf("Arquivo vazio.\n"); return;}
    
    ALUNO *alunos = (ALUNO*) malloc(n * sizeof(ALUNO));
    if(alunos == NULL){ printf("Memoria Insuficiente\n"); exit(-1); }
    
    fread(alunos, sizeof(ALUNO), n, arquivo);
    printf("APROVADOS:\n");
    for(int i = 0; i<n; i++){
        float media = (alunos[i].nota1+alunos[i].nota2)/2;
        if(media > 6.0){
            printf("%s: %.2f\n", alunos[i].nome, media);}
    }
    free(alunos);
}
/*8b)*/
int main(){
    ALUNO *turma = NULL;
    int nAlunos, i=0;
    int resp, add = 0;
    int alt;
    char *alunos = "alunos.dat";
    FILE *arq;
    do{
    printf("Escolha uma opcao\n1-Incluir aluno(s)\n2-Alterar aluno(s)\n");
    printf("3-Consultar aluno\n4-Excluir aluno(s)\n0-Encerrar programa\n");
    scanf("%d", &resp);
    if(resp==1){
        printf("Quantidade de alunos a incluir: ");
        scanf("%d", &add);
        if(add <= 0){ printf("Quantidade invalida\n"); continue; }

        ALUNO *novos = (ALUNO*) malloc(add * sizeof(ALUNO));
        if(novos==NULL){ printf("Memoria Insuficiente\n"); exit(-1); }

        for(i=0; i<add; i++){
            printf("Nome do aluno: ");
            scanf(" %80[^\n]", novos[i].nome);
            printf("Notas 1 e 2 respectivamente: ");
            scanf("%f %f", &novos[i].nota1, &novos[i].nota2);
            printf("===================\n");
        }

        arq = fopen(alunos, "ab");
        if(arq==NULL){ printf("ERRO\n"); free(novos); exit(-1); }
        fwrite(novos, sizeof(ALUNO), add, arq);
        fclose(arq);
        free(novos);
    }
        
    if(resp==2){   
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);   
    
        ALUNO rep;
        printf("Aluno a ser alterado(1 a %d): ", n);
        scanf("%d", &alt);
        alt = alt - 1;

        printf("Novo nome: ");
        scanf(" %80[^\n]", rep.nome);
        printf("Novas notas n1 e n2: ");
        scanf("%f %f", &rep.nota1, &rep.nota2);
        
        arq = fopen(alunos, "r+b");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, alt * sizeof(ALUNO), SEEK_SET);
        fwrite(&rep, sizeof(ALUNO), 1, arq);
        fclose(arq);
        printf("Alteracao concluida\n");
    }
    
    if(resp==3){
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);

        ALUNO rep;
        printf("Aluno a ser consultado(1 a %d): ", n);
        scanf("%d", &alt);
        alt --;

        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, alt * sizeof(ALUNO), SEEK_SET);
        fread(&rep, sizeof(ALUNO), 1, arq);
        fclose(arq);

        printf("Nome: %s\n", rep.nome);
        printf("Nota 1: %.2f // Nota 2: %.2f\n", rep.nota1, rep.nota2);
        float media = (rep.nota1 + rep.nota2) / 2;
        printf("Media: %.2f", media);
        if(media > 6){printf(" - Aprovado\n\n");}
        else{ printf(" - Reprovado\n\n");}
    }
    
    if(resp==4){
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);            
        
        ALUNO *aluno = (ALUNO*) malloc(n*sizeof(ALUNO));
        if(aluno==NULL){ printf("Memoria Insuficiente\n"); exit(-1);}
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        
        fread(aluno, sizeof(ALUNO), n, arq);
        fclose(arq);
        
        printf("Aluno a ser excluido(1 a %d): ", n);
        scanf("%d", &alt);
        alt--;
        for(i=alt; i<n-1; i++){
            aluno[i] = aluno[i+1];}
        n--;
        arq = fopen(alunos, "wb");
        fwrite(aluno, sizeof(ALUNO), n, arq);
        fclose(arq);
        free(aluno);        
    }
    }while(resp!=0);
    free(turma);
    return 0;
}