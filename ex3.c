#include <stdio.h>

int main()
{
  float a, b, resultado;
  char sinal;
  scanf("%f %c %f", &a, &sinal, &b);
  switch(sinal)
  {
    case '+':
      resultado = a + b;
      break;
    case '-':
      resultado = a - b;
      break;
    case '/':
      if (b == 0) return 1;
      resultado = a / b;
      break;
    case '*':
      resultado = a * b;
      break;
    default:
      break;
  }
  printf("%f\n", resultado);
  return 0;
}

