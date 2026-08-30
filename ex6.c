#include<stdio.h>
#include<math.h>

double calculaDelta(double a, double b, double c);
int  main()
{
  double a, b, c;
  do {
    scanf("%lf %lf %lf", &a, &b, &c);
  } while (a == 0);
  double delta = calculaDelta(a, b, c);
  if (delta == 0)
  {
    double raiz = (-b) / (4*a);
    printf("Raíz única: %lf\n", raiz);
    return 0;
  } else if(delta < 0) {
      printf("Não há raízes reais.\n");
      return 0;
  }

  double raiz1 = (-b + sqrt(delta)) / (2*a);
  double raiz2 = (-b - sqrt(delta)) / (2*a);
  printf("Raíz A: %lf\nRaíz B: %lf\n", raiz1, raiz2);
  return 0;
}

double calculaDelta(double a, double b, double c)
{
  return pow(b, 2) - (4 * a * c);
}

