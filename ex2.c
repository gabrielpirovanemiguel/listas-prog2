#include <stdio.h>

int retornaMaior(int a, int b, int c);
int retornaMenor(int a, int b, int c);
int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int media = (a + b + c) / 3;
  int maior = retornaMaior(a, b, c);
  int menor = retornaMenor(a, b, c);
  printf("Maior: %d\n", maior);
  printf("Pares: ");
  if (a % 2 == 0) printf("%d ", a);
  if (b % 2 == 0) printf("%d ", b);
  if (c % 3 == 0) printf("%d ", c);
  printf("\nMenor: %d\nMédia: %d\n", menor, media);	
}

int retornaMaior(int a, int b, int c)
{
  int maior = a;
  if (b > maior) maior = b;
  if (c > maior) maior = c;
  return maior;
}

int retornaMenor(int a, int b, int c) 
{
  int menor = a;
  if (b < menor) menor = b;
  if (c < menor) menor = c;
  return menor;
}
