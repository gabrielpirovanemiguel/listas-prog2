#include<stdio.h>

float calcula_media(float n1, float n2, float n3)
{
  return (n1+n2+n3)/3; 
}

int main()
{
  float n1, n2, n3;
  do {
    scanf("%f %f %f", &n1, &n2, &n3);
  } while (n1 < 0 || n2 < 0 || n3 < 0);
  float media = calcula_media(n1, n2, n3);
  printf("Média: %.2f\n", media);
  if (media >= 6)
    printf("Aprovado.\n");
  else if(media == 6)
    printf("VS\n");
  else
   printf("Reprovado\n");
  return 0;
}
