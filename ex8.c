#include<stdio.h>

void total_de_notas(int valor);

void main()
{
  int valor;
  scanf("%d", &valor);
  total_de_notas(valor);
}

void total_de_notas(int valor)
{
  int notas_100 = valor /100;
  valor -= notas_100*100;
  int notas_50 = valor / 50;
  valor -= notas_50*50;
  int notas_20 = valor / 20;
  valor -= notas_20*20;
  int notas_10 = valor / 10;
  valor -= notas_10*10;
  int notas_5 = valor / 5;
  valor -= notas_5*5;
  int notas_2 = valor / 2;
  valor -= notas_2*2;
  int notas_1 = valor;
  printf("100: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n", notas_100, notas_50, notas_20, notas_10, notas_5, notas_2, notas_1);
}
