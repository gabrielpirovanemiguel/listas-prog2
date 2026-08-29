#include <stdio.h>
/*
1. Fazer um programa para receber um número inteiro de segundos do usuário e imprimir
a quantidade correspondente em horas, minutos e segundos.
*/

/*

void main()
{
    int s,h,m = 0;

    printf("segundos totais: ");
    scanf("%d", &s);
    printf("\n\n%d segundos são ", s);

    h = s/3600;
    s = s%3600;

    m = s/60;
    s = s%60;

    printf("%d horas, %d minutos e %d segundos.", h,m,s);

}
*/


/*
2. Fazer um programa que recebe 3 valores inteiros do usuário e mostra o maior deles, o
menor deles, os valores pares e a média.
*/
/*
void main()
{

    int n[3];
    int evens[3];
    int min;
    int max = 0;
    float sum,avg = 0;


    for(int i=0;i<3;i++)
    {
        printf("%dº inteiro: ", i+1);
        scanf("%d",&n[i]);

        sum+=n[i];

        if(n[i] > max)
            max = n[i];

        if(n[i] < min || i == 0) // se for menor que o antigo menor OU for a primeira iteração
            min = n[i];
    }
    printf("\nmaior: %d, menor: %d", max,min);

    for(int i=0;i<3;i++)
    {
        if(n[i]%2==0)
            printf("\n%d é par",n[i]);
    }

    avg = sum/3;
    printf("\nmédia: %f",avg);
}
*/


/*
3. Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois
números reais. O programa deve retornar o resultado da operação recebida sobre estes
dois números.
*/
/*
void main()
{
    char c;
    float a,b;

    printf("operação (+, -, / ou *): ");
    scanf("%c", &c);

    printf("valores reais separados por espaço: ");
    scanf("%f %f",&a,&b);

    switch(c)
    {
        case '+':printf("%f + %f = %f", a,b,a+b); break;
        case '-':printf("%f - %f = %f", a,b,a-b); break;
        case '/':printf("%f / %f = %f", a,b,a/b); break;
        case '*':printf("%f * %f = %f", a,b,a*b); break;
        default: printf("operação nao existe");
    }
}
*/

/*
4. Um funcionário da UFF precisa validar as notas de 3 provas fornecidas por um
professor e indicar: a média, se está aprovado/reprovado e se tem direito de realizar a VS.
Inicialmente, faça um programa que recebe como entrada as 3 notas e mostre os
resultados solicitados. Posteriormente, coloque o código de cálculo da média em uma
função. Em um passo seguinte, realize os controles necessários para não receber notas
inválidas.
*/

/*
float calcAvg(float p1, float p2, float p3)
{
    return (p1+p2+p3)/3;
}

void main()
{
    float p1,p2,p3;
    float avg;
    int valid;

    do
    {
        valid = 1; //a principio, toda nota é válida, se for inválida, volta no while
        printf("nota da p1: ");
        scanf("%f", &p1);
        printf("nota da p2: ");
        scanf("%f", &p2);
        printf("nota da p3: ");
        scanf("%f", &p3);



        if(p1 < 0 || p1 > 10)
        {
            printf("Valor da p1 inválido.\n");
            valid = 0;
        }
        if(p2 < 0 || p2 > 10)
        {
            printf("Valor da p2 inválido.\n");
            valid = 0;
        }
        if(p3 < 0 || p3 > 10)
        {
            printf("Valor da p3 inválido.\n");
            valid = 0;
        }


    }while(valid != 1);

    avg = calcAvg(p1,p2,p3);
    printf("Média: %f", avg);

    if(avg>6)
        printf("\nAprovado");
    else
        printf("\nReprovado");

    if(4.0 <= avg <= 5.9)
    {
        printf("\nApto para VS");
    }
}
*/


/*
5)
*/

/*
void main()
{
    int a = 3;
    float b = a/2.0;
    float c = b + 3.1;

    printf("%.1f ", c);

    int b2 = a/2;
    c = b2 + 3.1;
    printf("%.1f ", c);

    int c3 = b2 + 3.1;
    printf("%d ", c3);
}
*/



