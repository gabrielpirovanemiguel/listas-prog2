#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define PI 3.14159265


/*
1. Implemente a função calcula_circulo, que calcula a área e a circunferência de um círculo de raio
r. Essa função deve obedecer o protótipo:
void calc_circulo(float r, float * circunferencia, float * area);
Fórmulas:
A = π r²;
c = 2 π r;
π = 3.14159265
Note que essa passagem dos 2 últimos parâmetros é uma passagem por referência.
*/

/*
void calc_circulo(float r, float * circunferencia, float * area);

void main() {
	float r, circunferencia, area;
	printf("Digite o valor do raio: ");
	do {
		scanf("%f", &r);
	} while (r <= 0);
	calc_circulo(r, &circunferencia, &area);
	printf("Circunferência: %f\nÁrea: %f\n", circunferencia, area);
}

void calc_circulo(float r, float * circunferencia, float * area) {
	*area = PI * (r*r);
	*circunferencia = 2 * PI * r;
}
*/


/*
2. Seja o seguinte trecho de programa:
int i=3,j=5;
int *p, *q;
p = &i;
q = &j;
Qual é o valor das seguintes expressões?
a) p == &i: true
b) *p - *q: -2
c) **&p: 3
d) 3* - *p/(*q)+7: 6
*/

/*
void main() {
	int i=3, j=5;
	int *p, *q;
	p = &i;
	q = &j;
	printf("%d", 3* - *p/(*q)+7);
}
*/


/*
3. (Questão teórica — sem código)
Qual a saída do trecho de programa apresentado?
Resposta: a saída será 4094, 7 e 15.
*/


/*
4. Fazer uma função denominada divs() que:
a. recebe como parâmetro um número inteiro n por valor e dois números inteiros max e min por
referência;
b. retorna 0 se o número num é primo e 1 caso contrário. Se o número não for primo, as variáveis
max e min devem assumir os valores do menor e do maior divisores inteiros do número,
respectivamente, desconsiderando o número 1 e o próprio número num.
*/

/*
int divs(int num, int *max, int *min) {
	int qnt_divisores = 0;
	*min = 1;
	*max = num;
	for (int i = 1; i < num; i++) {
		if (num % i == 0)
			if ( i < *min)
				*min = i;
			else if (i > *max && i != num)
				*max = i ;
			qnt_divisores++;
	}
	return qnt_divisores > 2 ? 0 : 1;
}

void main() {
	int max, min;
	printf("%d\n", divs(7, &max, &min));
	printf("%d %d", max, min);
}
*/


/*
5. Implemente a função max_vet, que recebe como parâmetro um vetor de números de ponto
flutuante (vet) de tamanho n e retorna o maior número armazenado nesse vetor. Essa função deve
obedecer o protótipo:
float max_vet (int n, float * vet);
Faça também a função main.
*/

/*
#define TAMANHO 5

float max_vet(int n, float *vet) {
	float max = *vet;
	for (int i = 0; i < n; i++) {
		if (*(vet+i) > max)
			max = *(vet+i);
	}
	return max;
}

void main() {
	float vet[TAMANHO] = {0, 83, 45, 23};
	float max = max_vet(TAMANHO, vet);
	printf("%f", max);
}
*/


/*
6. Implemente a função maiores, que recebe como parâmetro um vetor de números inteiros (vet)
de tamanho n e um valor x. A função deve retornar quantos números maiores do que x existem
nesse vetor. Essa função deve obedecer ao protótipo:
int maiores(int n, int * vet, int x);
*/

/*
#define TAMANHO 5

int maiores(int n, int * vet, int x);

void main() {
	int vet[TAMANHO] = {46, 45, 25, 67, 69};
	int x = 45;
	int qntd = maiores(TAMANHO, vet, x);
	printf("%d\n", qntd);
}

int maiores(int n, int * vet, int x) {
	int qntd = 0;
	for (int i = 0; i < n; i++)
		if (vet[i] > x)
			qntd++;
	return qntd;
}
*/


/*
7. Seja a seguinte sequência de instruções em um programa C:
int *pti;
int veti[]={10,7,2,6,3};
pti = veti;
Qual afirmativa é falsa?
a. *pti é igual a 10
b. *(pti+2) é igual a 2
c. pti[4] é igual a 3
d. pti[1] é igual a 10

Resposta: A alternativa d) é falsa.
*/


/*
8. Demonstração de acesso a vetor por ponteiro e comparação de endereços.
*/

/*
void main() {
	float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float *f;
	int i;
	f = vet;
	printf("contador/valor/valor/endereco/endereco");
	for (i = 0; i <= 4; i++) {
		printf("\ni = %d", i);
		printf(" vet[%d] = %.1f", i, vet[i]);
		printf(" *(f + %d) = %.1f", i, *(f+i));
		printf(" &vet[%d] = %X", i, &vet[i]);
		printf(" (f + %d) = %X", i, f+i);
	}
}
*/


/*
9. (Questão teórica — sem código)
Resposta: Opção a)
*/


/*
10. Implemente um programa que chame a função média com o seguinte protótipo:
float media(int n, float *v)
*/

/*
float media(int n, float *v);

void main() {
	float vet[4] = {0, 1, 2, 3};
	printf("Valor da média: %.2f\n", media(4, vet));
}

float media(int n, float *v) {
	float valor_soma, qntd = 0;
	for (int i = 0; i < n; i++) {
		valor_soma += *(v + i);
		qntd++;
	}
	return valor_soma / qntd;
}
*/


/*
11. Escreva um programa que realize a leitura da idade, da altura e do sexo de n pessoas. Ao final,
mostre o número de mulheres com idade entre 20 e 35 anos e o número de homens com altura
maior que 1,80m. Calcule e mostre também a variância da altura.
*/

/*
#define PESSOAS 3

void obtem_quantidades(int n, int *qntd_h, int *qntd_m, float *vet_altura);
float calcula_variancia(int n, float *vet_altura);

void main() {
	float vet_altura[PESSOAS];
	int qntd_h, qntd_m = 0;
	obtem_quantidades(PESSOAS, &qntd_h, &qntd_m, vet_altura);
	printf("Número de homens acima de 1.80m: %d\n", qntd_h);
	printf("Número de mulheres entre 20 e 35 anos: %d\n", qntd_m);
	printf("Variância da altura: %.2f\n", calcula_variancia(PESSOAS, vet_altura));
}

float calcula_variancia(int n, float *vet_altura) {
	float soma_m = 0, qntd = 0, soma_v = 0;
	for (int i = 0; i < n; i++) {
		qntd += 1;
		soma_m += vet_altura[i];
	}
	float media = soma_m / qntd;
	for (int i = 0; i < n; i++)
		soma_v += ((vet_altura[i] - media) * (vet_altura[i] - media));
	return soma_v / qntd;
}

void obtem_quantidades(int n, int *qntd_h, int *qntd_m, float *vet_altura) {
	int idade, sexo;
	float altura;
	for (int i = 0; i < n; i++) {
		do {
			printf("Entre com o sexo (0 - mulher | 1 - homem): ");
			scanf("%d", &sexo);
		} while (sexo < 0 || sexo > 1);
		do {
			printf("Entre a altura: ");
			scanf("%f", &altura);
		} while (altura < 0);
		do {
			printf("Ente a idade: ");
			scanf("%d", &idade);
		} while (idade < 0);

		if (sexo == 0)
			if (idade >= 20 && idade <= 35)
				*qntd_m += 1;
		else
			if (altura > 1.800)
				*qntd_h += 1;
		vet_altura[i] = altura;
	}
}
*/


/*
12. Escreva um programa que leia frases do teclado (sem buffer) e imprima cada palavra em uma
linha separada, substituindo os espaços por quebras de linha.
*/

/*
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void recebe_frases() {
    char vet[80], c;
    int i, j;
    int *iptr = &i;
    printf("Digite qualquer tecla: ");
    for (*iptr = 0; *iptr < 80; *iptr++) {
        c = getch();
        if (c == '\r')
            break;
        vet[*iptr] = c;
    }
    while (j < i) {
        if (vet[j] == ' ')
            printf("\n");
        printf("%c", vet[j]);
        j++;
    }
}

void main() {
	recebe_frases();
}
*/


/*
13. Fazer um programa para:
a. declarar variáveis a, b, c, d do tipo int.
b. declarar variáveis e, f, g, h do tipo float.
c. declarar vetor v de 10 elementos do tipo char.
d. declarar variável x do tipo int.
e. criar um ponteiro apontando para o endereço de a.
f. incrementar o ponteiro, mostrando o conteúdo do endereço apontado (em forma de número).
Caso o endereço coincida com o endereço de alguma outra variável, informar o fato.
*/

/*
int main() {
	int a, b, c, d;
	float e, f, g, h;
	char vet[10];
	int x;
	int *apt = &a;
	return 0;
}
*/


/*
14. Um cinema que possui capacidade de 100 lugares está quase sempre lotado. Certo dia cada
espectador respondeu a um questionário, onde constava:
- sua idade;
- sua opinião em relação ao filme, que podia ser: ótimo, bom, regular, ruim ou péssimo.
Elabore um programa que, recebendo estes dados calcule em funções e mostre:
a. a quantidade de respostas ótimo;
b. a diferença percentual entre respostas bom e regular;
c. a média de idade das pessoas que responderam ruim;
d. a porcentagem de respostas péssimo e a maior idade que utilizou esta opção;
e. a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim.
*/

/*
void main() {

}
*/
