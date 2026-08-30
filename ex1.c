#include <stdio.h>

int main()
{
  int segundos;
  do {
    scanf("%d", &segundos);
  } while (segundos < 0);
  int horas = segundos / 3600;
  int minutos = (segundos % 3600)/60;
  int segundosF = segundos % 60;
  printf("%d:%d:%d\n", horas, minutos, segundosF);
}
