#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
1. Faça uma função que verifique se um número dado é primo ou não.
*/

/*
void eh_primo(int num)
{
  int antecessores = 1;
  int divisores = 0;
  while (antecessores <= num)
  {
     if (num % antecessores == 0)
	divisores++;
     antecessores++;
  }
  divisores > 2 ? printf("NUMERO NAO PRIMO") : printf("NUMERO PRIMO");
}

void main()
{
  int num;
  scanf("%d", &num);
  eh_primo(num);
}
*/


/*
2. Faça uma função que receba um inteiro positivo n (n >= 1) e imprima a soma dos
primeiros n números ímpares.
*/

/*
void imprime_soma(int quantidade);

void main() {
	int quantidade;
	do {
		scanf("%d", &quantidade);
	} while (quantidade < 1);
	imprime_soma(quantidade);
}

void imprime_soma(int quantidade) {
  int soma = 0;
  int numeros = 1;
  for(int i = 0; i < quantidade; i++) {
  	soma += numeros;
	numeros += 2;
  }
  printf("Resultado da soma: %d\n", soma);
}
*/


/*
3. Faça uma função que receba um inteiro positivo n (n >= 2) e imprima os n primeiros
termos da sequência de Fibonacci.
*/

/*
void mostra_fibonnaci(int quantidade) {
  int proximo_termo;
	int penultimo_termo = 1;
	int ultimo_termo = 1;
	printf("%d %d ", penultimo_termo, ultimo_termo);
	if (quantidade == 2) {
		printf("\n");
		return;
	}
	for (int i = 0; i < (quantidade - 2); i++) {
		proximo_termo = penultimo_termo + ultimo_termo;
		printf("%d ", proximo_termo);
		penultimo_termo = ultimo_termo;
		ultimo_termo = proximo_termo;
	}
	printf("\n");
}

void main() {
	int quantidade;
	do {
		scanf("%d", &quantidade);
	} while (quantidade < 2);
	mostra_fibonnaci(quantidade);
}
*/


/*
4. Faça um programa que sorteie uma letra do alfabeto e peça para o usuário adivinhar
qual é essa letra. O programa deve indicar se a letra sorteada está "acima" ou "abaixo"
da entrada do usuário.
*/

/*
void verifica_acerto(int entrada_usuario, int letra_sorteada) {
	if (entrada_usuario == letra_sorteada)
		printf("Você acertou a letra!");
	else if (entrada_usuario < letra_sorteada)
		printf("A letra sorteada está acima da entrada.");
	else
		printf("A letra sorteada está abaixo da entrada.");
}

int sorteia_char_letra() {
	srand(time(NULL));
	int letra = ((rand() % 26) + 97);
	return letra;
}

void main() {
	int letra;
	do {
		scanf("%c", &letra);
	} while (letra < 1 || letra > 26);
	int letra_sorteada = sorteia_char_letra();
	verifica_acerto(letra, letra_sorteada);
}
*/


/*
5. Dados dois números positivos X e Z, sendo Z >= X, faça um programa que calcule
quantas vezes é preciso executar a operação X = X + (X+1) até que X >= Z.
*/

/*
void obter_x_z(int *x, int *z) {
	do {
		printf("Insira o valor de X: ");
		scanf("%d", x);
	} while (*x < 0);
	do {
		printf("Insira o valor de Z: ");
		scanf("%d", z);
	} while (*z < 0 || *z < *x);
}

void main() {
	int x, z, q;
	obter_x_z(&x, &z);
	while (x < z) {
		x += (x+1);
		q++;
	}
	printf("\n%d\n", q);
}
*/


/*
6. Faça um programa que sorteie um número entre 0 e 100 e peça para o usuário
adivinhar o número. O programa deve indicar se o número sorteado é maior ou menor
do que a tentativa do usuário e contar o número de tentativas até o acerto.
*/

/*
int sorteia_numero() {
	srand(time(NULL));
	return (rand() % 101);
}

void obtem_numero(unsigned int *tentativa) {
	printf("Entre sua tentativa: ");
	scanf("%u", tentativa);
}

void main() {
  	int numero_sorteado = sorteia_numero();
  	int q_tentativas = 1;
  	unsigned int tentativa;
	obtem_numero(&tentativa);
	while (tentativa != numero_sorteado) {
		if (tentativa < numero_sorteado)
			printf("\nO número sorteado é maior que a tentativa.\n");
		else
			printf("\nO número sorteado é menor que a tentativa.\n");
		obtem_numero(&tentativa);
		q_tentativas++;
	}
	printf("\nVocê acertou o numero. Tentativas até o acerto: %d\n", q_tentativas);
}
*/


/*
7. Faça um programa que calcule o salário semanal de um funcionário. O programa deve
receber as horas trabalhadas e o valor da hora. Se trabalhar menos de 40h, recebe
normalmente; entre 40h e 60h, recebe 60% a mais por hora extra; acima de 60h, recebe
100% a mais por hora extra.
*/

/*
void main() {
	float horas, valor_hora, salario;
	do {
		printf("Entre as horas trabalhadas: ");
		scanf("%f", &horas);
		printf("Entre o valor da hora: ");
		scanf("%f", &valor_hora);
	} while (horas < 0 || valor_hora < 0);

	if (horas < 40)
		salario = horas * valor_hora;
	else if (horas < 60)
		salario = (horas * valor_hora) * 1.6;
	else
		salario = (horas * valor_hora) * 2;

	printf("Salário semanal: %.2f\n", salario);
}
*/


/*
8. Encontre todos os números entre 0,10 e 0,99 (inclusive) onde a soma dos dois dígitos
após a vírgula elevada ao quadrado resulta no número original (em centésimos). Exemplo:
0,81 → (8+1)² = 81.
*/

/*
void main() {
	int a, b, c;
	float i = 0.1000f;
	while (i < 1) {
		a = i * 100;
		b = ((i*100) - a)*100;
		c = i * 10000;
		if ((a + b) * (a + b) == c)
			printf("%d, ", c);
		i += 0.0001f;
	}
}
*/


/*
9. Faça uma função que inverta os dígitos de um número inteiro de 3 dígitos.
Exemplo: 123 → 321.
*/

/*
unsigned int inverte(unsigned int numero) {
	unsigned int digito, numero_invertido, divisor;
	int j, i;
	numero_invertido = 0;
	i = 10;
	divisor = 1;
	while (i <= 1000) {
		digito = (numero % i) / divisor;
		numero -= digito;
		numero_invertido += digito * (1000/i);
		divisor*=10;
		i*=10;
	}
	return numero_invertido;
}

void main() {
	unsigned int numero, numero_invertido;
	do {
		scanf("%u", &numero);
	} while (numero < 100 || numero >= 1000);
	numero_invertido = inverte(numero);
	printf("%u\n", numero_invertido);
}
*/


/*
10. O maior divisor comum (MDC) de dois números inteiros é o maior número inteiro
que faz uma divisão exata (com resto zero) desses dois números. Por exemplo, o MDC de
32 e 40 é 8, o MDC de 9 e 27 é 9 e o MDC de 13 e 25 é 1. Implemente uma função que
receba como parâmetros dois números inteiros x e y e calcule o MDC desses números.
Essa função deve ter o seguinte protótipo:
int mdc (int x, int y);
*/

/*
#define MENOR(x,y) (x < y ? x : y)

int mdc (int x, int y);

void main () {
	int x, y;
	printf("Entre x: ");
	scanf("%d", &x);
	printf("Entre y: ");
	scanf("%d", &y);
	printf("MDC: %d\n", mdc(x,y));
}

int mdc (int x, int y) {
	int maximo_divisor = 1;
	int numero_maximo = MENOR(x,y);

	for (int i = 1; i <= numero_maximo; i++) {
		if (x % i == 0 && y % i == 0)
			maximo_divisor = i;
	}
	return maximo_divisor;
}
*/


/*
11. Faça uma função que receba dois inteiros x e y e retorne x elevado a y.
Utilize a função pow da biblioteca math.h.
*/

/*
double eleva(int x, int y) {
	return pow(x,y);
}

void main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%f\n", eleva(x, y));
}
*/
