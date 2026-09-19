#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*1.*/

/*
void main()
{
    char c[] = "stupid"; 
    int x[10];
    int y[10];
    
    
    for(int j=0; j<10;j++)
        scanf("%d", &x[j]);
    
    
    
    int i = 9;
    for(int j=0;j<10;j++)
    {
        y[j] = x[i];
        
        i--;
    }
    
    
    for(int j=0;j<10;j++)
    {
        printf("%d ", y[j]);
    }
}
*/


/*2*/

/*
void elemComuns(int *r, int *s, int *x, int *qtdComuns)
{
    int encontrou;
    int jaTem;
    
    for(int i=0;i<5;i++)
    {
        encontrou=0;

        for(int j=0;j<5;j++)
        {
            if (r[i] == s[j])
            {
                encontrou=1;
                break;
            }
        }

        if(encontrou)
        {
            jaTem = 0;

            for(int k=0;k<*qtdComuns;k++)
            {
                if(r[i] == x[k])
                {
                    jaTem = 1;
                    break;
                }
            }

            if(!jaTem)
            {
                x[*qtdComuns] = r[i];
                (*qtdComuns)++;
            }
        }
    }
}

int main(void)
{
    int r[5];
    int s[5];
    int x[5];
    int qtdComuns = 0;

    printf("Vetor r:\n");
    for(int i=0;i<5;i++)
        scanf("%d", &r[i]);

    printf("Vetor s:\n");
    for(int i=0; i<5;i++)
        scanf("%d", &s[i]);

    elemComuns(r, s, x, &qtdComuns);

    printf("\nValores comuns:\n");
    for(int i=0;i<qtdComuns;i++)
        printf(" | %d", x[i]);

    printf("\n");

    return 0;
}
*/


// 3. O que será impresso na tela pelo seguinte programa:
/*
R: 1020304050
*/

/*
int main()
{
    int numbers[5];
    int *p;
    int n;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;
    for (n = 0; n < 5; n++)
        printf("%d", numbers[n]);
}
*/




/*8*/

/*
void main()
{
    int len;
    int *vet;
    int l;
    int r;

    do
    {
        printf("tamanho do vetor (par): ");
        scanf("%d",&len);
    } while (len % 2 != 0);

    vet = (int *) malloc(len*sizeof(int));
    if(vet ==NULL)
        exit(1);
    
    for(int i=0;i<len;i++)
    {
        printf("%do valor: ",i+1);
        scanf("%d",vet+i);
    }
    
    printf("\n\n");
    for(int i=0;i<len/2;i++)
    {
        l = *(vet+i); //left
        r = *((vet+len-1)-i); //right

        printf("%d - %d\n",l,r);
    }
    free(vet);
}
*/


/*9*/

/*
void trocarVals(int *vet, int len);

void listVector(int *vet,int len);

int ind(int *vet, int len, int num);

int main()
{

    int *vet;
    int len=7;
    int num;

    vet = (int *) malloc(len*sizeof(int));

    if(vet==NULL)
        exit(1);

    for(int i=0;i<len;i++){
        printf("%do valor: ",i+1);
        scanf("%d",vet+i);
    }

    listVector(vet,len);


    printf("\n\nnumero quer procurar no vetor: ");
    scanf("%d",&num);

    int indice = ind(vet,len,num);

    indice != -1 ? printf("index do numero %d: (%d)", num, indice) :  printf("\n%d nao encontrado na lista", num);

    trocarVals(vet,len);

    listVector(vet,len);

    free(vet);
    return 0;
}


void listVector(int *vet,int len)
{
    printf("\n\nvalores e indices:\n");
    for(int i=0;i<len;i++)
    {
        printf(" %d    |     %d\n",*(vet+i),i);    
    }
    printf("\n\n");
}


int ind(int *vet, int len, int num)
{
    int j = -1; //valor padrao pra caso nao encontre

    for (int i=0;i<len;i++)
    {
        if(*(vet+i) == num)
        {
            j = i; 
            break; //retornar o ind da primeira ocorrencia igual python
        }
    }
    return j;
}

void trocarVals(int *vet, int len)
{
    int *aux;

    aux = (int *) malloc(len*sizeof(int));

    if(aux==NULL)
        exit(1);
    
    for(int i=0;i<len;i++)
    {
        if(i==0)
            aux[i] = vet[i];
        else
            aux[i] = aux[i-1] + vet[i]; //soma do anterior + o atual
    }
    for(int i=0;i<len;i++)
    {
        vet[i] = aux[i];
    }
    free(aux);
}
*/