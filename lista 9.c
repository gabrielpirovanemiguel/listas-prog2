/******************************************************************************

1. Uma empresa que organiza concursos está realizando um grande processo seletivo e conta com
um sistema informatizado para auxiliar no gerenciamento de informações sobre os candidatos.
Nesse sistema, as informações referentes aos candidatos são armazenadas em um vetor de
ponteiros para dados estruturados do tipo Candidato, conforme descrito a seguir:

a. Faça um programa que leia as informações de n candidatos. Crie uma variável alocada
dinamicamente que armazene as informações lidas.

b. Faça um menu de opções com a opção ‘1’ para leitura dos dados de candidatos e a
opção ‘2’ para impressão de todas as informações dos candidatos.
c. Faça com que uma opção do menu permita alterar o endereço e a sala do local de
provas de um determinado candidado.

c. Faça com que uma opção do menu permita alterar o endereço e a sala do local de
provas de um determinado candidado.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81]; /* endereço do local de provas */
    int sala;       /* numero sala */
} Local;

typedef struct notas {
    float geral;      /* prova de conhecimentos gerais */
    float especifica; /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato {
    int inscr;      /* numero de inscricao */
    char nome[81];  /* nome do candidato */
    Data nasc;      /* data de nascimento */
    Local *loc;     /* local de prova */
    Notas nt;       /* notas de prova */
} Candidato;

int main() {
    int n, i, resp, cn, alt;
    int cont = 0;

    printf("Numero de candidatos: ");
    scanf("%d", &n);

    /* Alocação do vetor de ponteiros para Candidato */
    Candidato **cand = (Candidato **) malloc(n * sizeof(Candidato *));
    if (cand == NULL) {
        printf("Memoria Insuficiente\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        cand[i] = NULL;
    }

    /* Menu em laço para permitir cadastrar, imprimir e alterar */
    do {
        printf("\n1- Inserir dados do(s) candidato(s)\n");
        printf("2- Mostrar dados dos candidatos\n");
        printf("3- Alterar endereco e sala do local de provas\n");
        printf("0- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &resp);

        if (resp == 1) {
            for (i = 0; i < n; i++) {
                if (cand[i] == NULL) {
                    cand[i] = (Candidato *) malloc(sizeof(Candidato));
                    if (cand[i] == NULL) {
                        printf("Memoria insuficiente\n");
                        return 1;
                    }
                    cand[i]->loc = (Local *) malloc(sizeof(Local));
                    if (cand[i]->loc == NULL) {
                        printf("Memoria insuficiente\n");
                        return 1;
                    }
                }

                printf("\n==== Candidato %d ====\n", i + 1);

                printf("Inscricao: ");
                scanf("%d", &cand[i]->inscr);

                printf("Nome: ");
                scanf(" %80[^\n]", cand[i]->nome);

                printf("Data de nascimento (dd mm aaaa): ");
                scanf("%d %d %d", &cand[i]->nasc.dia, &cand[i]->nasc.mes, &cand[i]->nasc.ano);

                printf("Endereco: ");
                scanf(" %80[^\n]", cand[i]->loc->ender);

                printf("Sala: ");
                scanf("%d", &cand[i]->loc->sala);

                printf("Nota geral: ");
                scanf("%f", &cand[i]->nt.geral);

                printf("Nota especifica: ");
                scanf("%f", &cand[i]->nt.especifica);
            }
            cont = 1;
        } 
        else if (resp == 2) {
            if (cont == 0) {
                printf("Nenhum candidato encontrado.\n");
            } else {
                printf("\n==== Candidatos Inscritos ====\n");
                for (i = 0; i < n; i++) {
                    printf("- Candidato %d -\n", i + 1);
                    printf("Inscricao: %d\n", cand[i]->inscr);
                    printf("Nome: %s\n", cand[i]->nome);
                    printf("Data de nascimento: %d/%d/%d\n", cand[i]->nasc.dia, cand[i]->nasc.mes, cand[i]->nasc.ano);
                    printf("Local de prova: %s\nSala: %d\n", cand[i]->loc->ender, cand[i]->loc->sala);
                    printf("Nota da prova geral: %.2f\n", cand[i]->nt.geral);
                    printf("Nota da prova especifica: %.2f\n", cand[i]->nt.especifica);
                    printf("============================\n");
                }
            }
        } 
        else if (resp == 3) {
            if (cont == 0) {
                printf("Impossivel alterar o local de prova, motivo: Nenhum candidato encontrado.\n");
            } else {
                printf("Qual candidato tera seu local alterado (1 a %d)? ", n);
                scanf("%d", &cn);
                cn = cn - 1;

                if (cn >= 0 && cn < n) {
                    printf("1- Alterar o endereco\n2- Alterar a sala\n3- Alterar os dois\n");
                    scanf("%d", &alt);

                    if (alt == 1) {
                        printf("Insira o novo endereco: ");
                        scanf(" %80[^\n]", cand[cn]->loc->ender);
                    } 
                    else if (alt == 2) {
                        printf("Insira a nova sala: ");
                        scanf("%d", &cand[cn]->loc->sala);
                    } 
                    else if (alt == 3) {
                        printf("Insira o novo endereco: ");
                        scanf(" %80[^\n]", cand[cn]->loc->ender);
                        printf("Insira a nova sala: ");
                        scanf("%d", &cand[cn]->loc->sala);
                    }
                } else {
                    printf("Candidato invalido.\n");
                }
            }
        }
    } while (resp != 0);

    /* Liberação de toda a memória alocada */
    for (i = 0; i < n; i++) {
        if (cand[i] != NULL) {
            free(cand[i]->loc);
            free(cand[i]);
        }
    }
    free(cand);

    return 0;
}

/******************************************************************************

2. Tendo o seguinte código:

typedef struct data {
	int dia;
	int mes;
	char nomeMes[12];
} Data;

main() {
	Data aniversarios[3] = { {5,1,"JANEIRO"},
	{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
	int a;
	Data *p_dt;
	p_dt=&aniversarios[2];
	printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
	strcpy(p_dt->nomeMes, "MARÇO");
	printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));
	Data p_dt2 = (Data *) malloc(sizeof(Data));
	p_dt2 = &aniversarios[0];
}

a. O programa acima pode ter no máximo 1 erro. Caso tiver, explique qual é o erro.

b. Qual o valor mostrado na tela no segundo (último) printf?

*******************************************************************************/

// a: Data p_dt2 = (Data *) malloc(sizeof(Data)); deveria ser:
// Data * p_dt2 = (Data *) malloc(sizeof(Data));

// b: 5

/******************************************************************************

3. Uma instituição de pesquisa recolheu amostras de estados brasileiros a respeito do
salário da população. Tendo o seguinte código:

a. Implemente a função cadastra, que atribui os parâmetros recebidos aos campos da
estrutura Assalariados.

b. Implemente a função imprime, que imprime todos os elementos do vetor de
Assalariados.

c. Implemente a função relatório, que imprime a quantidade de homens por estado com
mais de 40 anos que recebem salários superiores a R$ 1000,00. Caso a quantidade no
estado analisado seja zero, então não imprime nada. A mensagem de impressão deve ser:
Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado) {
    Assalariados * cadastrado = malloc(sizeof(Assalariados));
 
    if (cadastrado != NULL) {
 
        strncpy(cadastrado->nome, nome, 50);
        cadastrado->nome[50] = '\0';
        cadastrado->sexo = sexo;
        cadastrado->idade = idade;
        cadastrado->salario = salario;
        strncpy(cadastrado->estado, estado, 2);
        cadastrado->estado[2] = '\0';
 
        return cadastrado;
 
    }
 
        return NULL;
}

void imprime(Assalariados ** ptr, int numAssalariados) {
    for (int i = 0; i < numAssalariados; i++) {
        if (ptr[i] != NULL) {
            printf("Nome: %s\n", ptr[i]->nome);
            printf("Sexo: %c\n", ptr[i]->sexo);
            printf("Idade: %d\n", ptr[i]->idade);
            printf("Salário: %.2f\n", ptr[i]->salario);
            printf("Estado: %s\n", ptr[i]->estado);
            printf("-----------------\n");
        }
    }
}

void relatorio(Assalariados ** ptr, int numAssalariados) {
    char * estadoAnalisado;
    char * estadoComparado;
    for (int i = 0; i < 27; i++) {
        estadoAnalisado = estado[i];
        int contador = 0;
        for (int j = 0; j < numAssalariados; j++) {
            estadoComparado = ptr[j]->estado;
            if (ptr[j]->idade > 40 && ptr[j]->salario > 1000  && ptr[j]->sexo == 'M') {
                for (int k = 0; k < 1; k++) {
                    if (estadoAnalisado[k] == estadoComparado[k] && estadoAnalisado[k + 1] == estadoComparado[k + 1]) {
                        contador++;
                    }
                }
            }
        }
        if (contador > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00\n", estado[i], contador);
        }
    }
}

int main(void) {
    Assalariados **pessoas;
    int numAssalariados = 3;
    pessoas = (Assalariados **) malloc (numAssalariados * sizeof(Assalariados *));
 
    pessoas[0] = cadastra("Fulano de tal", 'M', 45, 1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M', 50, 2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M', 42, 500.00, "RS");
 
    imprime(pessoas, numAssalariados);
 
    relatorio(pessoas,numAssalariados);
    
    for (int i = 0; i < numAssalariados; i++) {
        free(pessoas[i]);
    }
    free(pessoas);
 
    return 0;
}

/******************************************************************************

4. Tendo o seguinte trecho de código (compilável e executável corretamente):

a. Implemente a função atribui, conforme o seu protótipo (dica: somente 1 linha de
código no corpo da função).

b. Implemente a função get_sobrenome, conforme o seu protótipo, que retorna a última
palavra do nome.

c. O que será impresso no segundo printf?

d. O que será impresso no terceiro printf?

*******************************************************************************/

#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome) {
    strcpy(nomes[indice], nome);
}

char * get_sobrenome(char *nome) {
    char * sobrenome = malloc(MAXNOME * sizeof(char));
    int i = 0, j = 0;
    while (nome[i] != '\0') {
        if (nome[i] == ' ') {
            strcpy(sobrenome, "");
            sobrenome[30] = '\0';
            j = 0;
            i++;
        }
        else {
            sobrenome[j] = nome[i];
            i++;
            j++;
        }
    }
 
    sobrenome[j] = '\0';
 
    return sobrenome;
}

void main() {
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for (i = 0 ; i < MAX ; i++) {
        nomes[i] = (char *) malloc(sizeof(char) * MAXNOME);
    }

    atribui(nomes,0,"Fulano Silva");
    atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte");
    atribui(nomes,3,"Pedro dos Santos");
 
    for (i = 0 ; i < MAX ; i++) {
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d", strlen(sobrenome) > 5?i:0); // 2o printf
        free(sobrenome);
    }

    printf("\n%c", nomes[0][3]); // 3o printf
    
    for (int i = 0; i < MAX; i++) {
        free(nomes[i]);
    }
    free(nomes);
}

/******************************************************************************

O que será impresso no segundo printf? RESPOSTA: 0 0 2 3

d. O que será impresso no terceiro printf? RESPOSTA: a

*******************************************************************************/

/******************************************************************************

5. Considere um sistema de apoio escolar que armazena as informações sobre as notas dos alunos
de uma turma em um vetor de ponteiros para variáveis do tipo Aluno, descrito a seguir:

5a. Escreva uma função que aloca espaço em memória para n alunos.

5b. Escreva uma função que atribui a um determinado elemento do vetor de ponteiros para
estruturas os dados passados como parâmetro. A função recebe o vetor a, o índice do vetor e os
dados a serem preenchidos na estrutura. A função tem o seguinte protótipo:

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco {
    char rua[100]; /* Nome da rua */
    int numero; /* Numero do imovel */
} Endereco;

typedef struct notas {
    float p1, p2, p3; /* Notas nas provas */
} Notas;

typedef struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
    Notas nota; /* Notas nas provas */
    Endereco *end; /* Endereco do aluno */
} Aluno;

Aluno ** alocaAlunos(int n) {
    Aluno ** alunosAlocado = (Aluno **) malloc(n * sizeof(Aluno *));
    if (alunosAlocado != NULL) {
        for (int i = 0; i < n; i++) {
            alunosAlocado[i] = malloc(sizeof(Aluno));
            alunosAlocado[i]->end = NULL;
        }
        return alunosAlocado;
    }
 
    return NULL;
}

void atribui(Aluno ** a, int indice, int matricula, char *nome, float nota1, float nota2, float nota3, char *nomeRua, int numero) {
    if (a != NULL) {
        a[indice]->mat = matricula;
        strncpy(a[indice]->nome, nome, 80);
        a[indice]->nome[80] = '\0';
        a[indice]->nota.p1 = nota1;
        a[indice]->nota.p2 = nota2;
        a[indice]->nota.p3 = nota3;
 
        if (a[indice]->end == NULL) {
            a[indice]->end = (Endereco *) malloc(sizeof(Endereco));
        }
 
        if (a[indice]->end != NULL) {
            strncpy(a[indice]->end->rua, nomeRua, 99);
            a[indice]->end->rua[99] = '\0';
            a[indice]->end->numero = numero;
        }
    }
}

void main() {
    Aluno **alunos;
    alunos = alocaAlunos(3);
    atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
    atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
    atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);
    for (int i = 0; i < 3; i++) {
        free(alunos[i]->end);
        free(alunos[i]);
    }
    free(alunos);
}

/******************************************************************************

6. Um cadastro de pessoas é representado por um vetor de ponteiros para o tipo Pessoa, conforme
descrito a seguir:

Considere que esse vetor está em ordem crescente de código, e, além disso, o código é a identificação única da pessoa.

Aplicando a técnica de busca binária, implemente uma função que verifique se um código fornecido
como parâmetro existe no vetor. A função retorna o ponteiro para esta pessoa (Pessoa *).
Caso contrário, a função deve retornar NULL. A função recebe como parâmetros o ponteiro vet,
para o primeiro elemento do vetor, o inteiro n, que representa o tamanho do vetor, e o código.

Seu protótipo é:

Faça também um programa para testar essa função.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define linhasPessoas 3


struct pessoa {
int codigo;
char nome[81];
};

typedef struct pessoa Pessoa;

Pessoa* busca(int n, Pessoa** vet, int codigo) {
    int inicio = 0;
    int fim = n - 1;
 
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio)/2;
        if (vet[meio]->codigo == codigo) {
            return vet[meio];
        }
        else if (vet[meio]->codigo < codigo) {
            inicio = meio + 1;
        }
        else if (vet[meio]->codigo > codigo) {
            fim = meio - 1;
        }
    }
 
    printf("Pessoa não identificada!");
    return NULL;
}

int main()
{
	Pessoa ** Pessoas = malloc(linhasPessoas * sizeof(Pessoa *));
	if (Pessoas == NULL) {
	    exit(1);
	}
	else {
	    for (int i = 0; i < linhasPessoas; i++) {
	        Pessoas[i] = (Pessoa *) malloc(sizeof(Pessoa));
	        printf("Digite o código da Pessoa[%d]: ", i);
	        scanf("%d", &Pessoas[i]->codigo);
	        printf("Digite o nome da Pessoa[%d]: ", i);
	        scanf(" %[^\n]", Pessoas[i]->nome);
	    }
	}
	
	int codigo;
	int n = linhasPessoas;
	
	printf("Escolha um código para acessar as informações: ");
	scanf("%d", &codigo);
	
	Pessoa * dados = busca(n, Pessoas, codigo);
	
	if (dados != NULL) {
	    printf("Nome do Cadastrado: %s", dados->nome);
	}
	
	for (int i = 0; i < linhasPessoas; i++) {
	    free(Pessoas[i]);
	}
	
	free(Pessoas);
	
	return 0;
}

/******************************************************************************

7. Considere o tipo Aluno, que representa um aluno da disciplina, e o tipo Prova, que representa a
prova de um aluno, ambos descritos a seguir:

Essa função ordena o vetor em ordem decrescente de nota da prova --- que equivale à soma das
notas das quatro questões ---, com desempate pela ordem alfabética do nome do aluno. Por

exemplo, se Maria e Ana tiram 6.0 e Sandra tira 7.0, a ordem deve ser Sandra, Ana e Maria.
Implemente as funções compara e troca de forma que o algoritmo descrito funcione corretamente.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};

typedef struct aluno Aluno;

struct prova {
    Aluno a; /* Aluno que fez a prova */
    float q1, q2, q3, q4; /* Nota em cada questao */
};

typedef struct prova Prova;

void ordena(int n, Prova** v) {
    int fim,i;
    for(fim=n-1; fim>0; fim--)
    for(i=0; i<fim; i++)
    if(compara(v[i],v[i+1]))
    troca(&v[i],&v[i+1]);
}

int compara(Prova *a, Prova *b){
    float somaA = 0, somaB = 0;
    somaA = a->q1 + a->q2 + a->q3 + a->q4;
    somaB = b->q1 + b->q2 + b->q3 + b->q4;
    if(somaA == somaB){
            if(strcmp(a->a.nome, b->a.nome) < 0){
                return 0;
            }
            else{
                return 1;
            }
        }
    else if(somaA < somaB){
        return 1;
    }
    return 0;
}

void troca(Prova **a, Prova **b){
    Prova *tmp = *a;
    *a = *b;
    *b = tmp;
}

/******************************************************************************

8. Uma agenda é representada por um vetor de ponteiros para o tipo Compromisso, que
representa as informações sobre um compromisso diário, conforme descrito a seguir:

Considere que esse vetor está em ordem cronológica, ou seja, ordem crescente de acordo com a
data de cada compromisso, e, além disso, não há mais de um compromisso com uma mesma data.
Aplicando a técnica de busca binária, implemente uma função que, dada uma data (dia, mês e
ano), se há no vetor algum compromisso com essa data, retorna o ponteiro para este
compromisso. Caso contrário, a função deve retornar NULL. A função recebe como parâmetros o
ponteiro vet, para o primeiro elemento do vetor, o inteiro n, que representa o tamanho do vetor, e
os inteiros d, m e a, representando uma data. Seu protótipo é:

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct data {
    int dd, mm, aa; /* Dia, mes e ano */
};

typedef struct data Data;

struct compromisso {
    char descricao[81]; /* Descricao do compromisso */
    Data dta; /* Data do compromisso */
};

typedef struct compromisso Compromisso;

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a){
int ini = 0;
    int fim = n-1;
    while(ini <= fim){
        int meio = (ini+fim)/2;
        if(a < vet[meio]->dta.aa || (a== vet[meio]->dta.aa && m < vet[meio]->dta.mm)
        || (a==vet[meio]->dta.aa && m==vet[meio]->dta.mm && d < vet[meio]->dta.dd)){
            fim = meio-1;
        }
        else if(a > vet[meio]->dta.aa || (a== vet[meio]->dta.aa && m > vet[meio]->dta.mm)
        || (a==vet[meio]->dta.aa && m==vet[meio]->dta.mm && d > vet[meio]->dta.dd)){
            ini = meio+1;
        }
        else{
            return vet[meio];
                }
    }
    return NULL;
}

/******************************************************************************

9. Faça a função main para funcionar com a função ordena.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    float media;
} ALUNO;

void ordena (ALUNO turma[], int tam) {
    int i, foraOrdem, jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados ; i++) {
            if (turma[i].media > turma[i+1].media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp ;
                foraOrdem = 1;
            }
        }
        jaOrdenados ++;
    } while ( foraOrdem );
}

int main() {
    int tam = 4;
 
    ALUNO * turma = malloc(tam * sizeof(ALUNO));
 
    if (turma == NULL) {
        printf("Erro de alocação de Memória!");
        exit(1);
    }
 
    for (int i = 0; i < tam; i++) {
        printf("Média do Aluno %d: ", i + 1);
        scanf("%f", &turma[i].media);
    }
 
    ordena(turma, tam);
 
    printf("\nMédias ordenadas:\n");
    for (int i = 0; i < tam; i++) {
        printf("Aluno %d: %.2f\n", i + 1, turma[i].media);
    }
 
    free(turma);

    return 0;
}

/******************************************************************************

10. Faça as funções que são invocadas pela função main.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct aluno {
    char nome [81];
    float nota1;
    float nota2;
    float nota3;
    float media;
};

void le (struct aluno * turma) {
    for (int i = 0; i < MAX; i++) {
        printf("Digite o nome do aluno: ");
        scanf(" %80[^\n]", turma[i].nome);
 
        printf("Digite a primeira nota: ");
        scanf("%f", &turma[i].nota1);
 
        printf("Digite a segunda nota: ");
        scanf("%f", &turma[i].nota2);
 
        printf("Digite a terceira nota: ");
        scanf("%f", &turma[i].nota3);
 
        turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3)/3;
    }
 
}

void imprime (struct aluno * turma) {
    for (int i = 0; i < MAX; i++) {
        printf("Nome do Aluno: %s ", turma[i].nome);
        printf("Média do Aluno: %.2f\n", turma[i].media);
    }
}

struct aluno * ordena_medias(struct aluno * turma) {
    for (int i = MAX - 1 ; i > 0; i--) {
        int troca = 0;
        for (int j = 0; j < i; j++) {
            if (turma[j].media < turma[j + 1].media) {
                struct aluno temp = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0) {
            return turma;
        }
    }
 
    return turma;
}

int main (void) {
    struct aluno turma[MAX];
    le(turma);
 
    puts (" Imprimindo dados lidos da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
 
    imprime(turma);
    ordena_medias(turma);
 
    puts (" Imprimindo dados ordenados da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
 
    imprime (turma);
 
    getchar ();
}
/******************************************************************************

11. Criar um tipo Aluno e um tipo Materia tal como dado abaixo:

(A) Criar uma função Aluno* fillAluno() que preenche os campos da estrutura do tipo Aluno com
dados fornecidos pelo usuário.
(B) Criar uma função Materia * fillMateria(int numAlunos) que preenche os campos da estrutura
do tipo Materia realizando chamadas a função fillAluno em um número de vezes igual ao número
contido na variável numAlunos.
(C) Criar uma função void mediaMateria(Materia *m1) que fornece a média de cada prova do
ano para os alunos contidos na variável m1 e assim preenche o campo media de m1.
(D) Criar uma função void mostraMateria(Materia *m1) que mostra as informações dos alunos
contidas na variável m1.
(E) Criar um programa que ilustra o funcionamento das funções anteriores.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Materia {
    Aluno *V; // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos; // Número de alunos matriculados no curso.
}Materia;

Aluno * fillAluno() {
    Aluno * aluno = malloc(sizeof(Aluno));
 
    if (aluno == NULL) {
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
 
    aluno->vNotas = malloc(5 * sizeof(float));
 
    if (aluno->vNotas == NULL) {
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
 
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &aluno->matricula);
 
    for (int i = 0; i < 5; i++) {
        printf("Digite as notas do aluno: ");
        scanf("%f", &aluno->vNotas[i]);
    }
 
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);
 
    return aluno;
}

Materia * fillMateria(int numAlunos) {
    Materia * materia = malloc(sizeof(Materia));
 
    if (materia == NULL) {
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
 
    materia->V = malloc(numAlunos * sizeof(Aluno));
 
    if (materia->V == NULL) {
        printf("Erro de Alocação de Memória!");
        exit(1);
    }
 
    materia->nAlunos = numAlunos;
 
    for (int i = 0; i < materia->nAlunos; i++) {
        Aluno * alunoInfo = fillAluno();
        materia->V[i] = * alunoInfo;
        free(alunoInfo);
    }
 
    return materia;
}

void mediaMateria(Materia *m1) {
    for (int j = 0; j < 5; j++) {
        m1->media[j] = 0;
    }
 
    for (int i = 0; i < m1->nAlunos; i++) {
 
        for (int j = 0; j < 5; j++) {
            m1->media[j] = m1->media[j] + m1->V[i].vNotas[j];
        }
    }
 
    for (int j = 0; j < 5; j++) {
        m1->media[j] = m1->media[j] / m1->nAlunos;
    }
}

void mostraMateria(Materia *m1) {
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("\nAluno (%d) %s - Notas: ", m1->V[i].matricula, m1->V[i].nome);
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", m1->V[i].vNotas[j]);
        }
    }

    printf("\n\nMédias da turma nas 5 provas:\n");
    for (int j = 0; j < 5; j++) {
        printf("Prova %d: %.2f\n", j + 1, m1->media[j]);
    }
}


int main() {
    int n;
    printf("Quantos alunos deseja cadastrar na matéria? ");
    scanf("%d", &n);

    Materia * m = fillMateria(n);
    mediaMateria(m);
    mostraMateria(m);

    for (int i = 0; i < m->nAlunos; i++) {
        free(m->V[i].vNotas);
    }
    free(m->V);
    free(m);

    return 0;
}

/******************************************************************************

12. Criar um tipo Livro e um tipo Biblioteca tal como dado abaixo:

(A) Criar uma função Livro * fillLivro() que preenche os campos da estrutura Livro e retorna
esse novo livro.
(B) Criar uma função Biblioteca * fillBiblioteca(int numLivros) que preenche os campos da
estrutura do tipo Biblioteca realizando chamadas a função fillLivro em um número de vezes igual
ao número contido na variável numLivros.
(C) Criar uma função void valorBiblioteca(Biblioteca * b1, int numLivros) que fornece o
montante gasto para se comprar todos os exemplares existentes na biblioteca.
(D) Criar uma função Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) que retorna o livro
com maior número de exemplares.
(E) Criar um programa que ilustra o funcionamento das funções anteriores.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
}Livro;

typedef struct Biblioteca {
    Livro **V; // Armazena a informação de n livros !!
    int nLivros; // Número de livros existentes na biblioteca.
}Biblioteca;

Livro * fillLivro(){
    Livro *livro = (Livro*) malloc(sizeof(Livro));
    if(livro == NULL){printf("Memoria Insuficiente\n"); exit(1);}
    printf("Ano de lancamento do livro: ");
    scanf("%d", &livro->ano);

    printf("Titulo: ");
    scanf(" %99[^\n]", livro->titulo);

    printf("Autor: ");
    scanf(" %99[^\n]", livro->autor);

    printf("Numero de exemplares: ");
    scanf("%d", &livro->nVolume);

    printf("Preco: ");
    scanf("%f", &livro->preco);
    return livro;
}
/*12b)*/
Biblioteca * fillBiblioteca(int numLivros){
    Biblioteca *biblio = (Biblioteca*) malloc(sizeof(Biblioteca));
    if(biblio == NULL){printf("Memoria Insuficiente"); exit(1);}
    biblio->nLivros = numLivros;
    biblio->V = (Livro**) malloc(numLivros * sizeof(Livro*));
    if(biblio->V == NULL){printf("Memoria Insuficiente"); exit(1);}

    for(int i=0; i<numLivros; i++){
        Livro *tmp = fillLivro();
        biblio->V[i] = tmp;
    }
    return biblio;
}
/*12c)*/
void valorBiblioteca(Biblioteca * b1, int numLivros){
    float valor=0;
    for(int i=0; i<numLivros; i++){
        valor = (b1->V[i]->nVolume * b1->V[i]->preco) + valor;
    }
    printf("Valor de compra de todos os exemplares: %.2f\n", valor);
}
/*12d)*/
Livro * maiorBiblioteca(Biblioteca *b1, int numLivros){
    int i;
    Livro *maior = b1->V[0];
    for(i=0; i<numLivros; i++){
        if(b1->V[i]->nVolume> maior->nVolume){
            maior = b1->V[i];
        }
    }
    return maior;
}
/*12e)*/
void main(){
    int nLivros;
    Biblioteca * bib;
    printf("Quantidade de livros na biblioteca: ");
    scanf("%d", &nLivros);
    bib = fillBiblioteca(nLivros);
    valorBiblioteca(bib, nLivros);
    printf("Livro com mais exemplares: %s", maiorBiblioteca(bib, nLivros)->titulo);
    for(int i=0; i<nLivros; i++){
        free(bib->V[i]);
    }
    free(bib->V);
    free(bib);
}