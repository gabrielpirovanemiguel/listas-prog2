//Números de 01 até 09

1)
#include <stdio.h>

int preencher(int *vetor, int tam);
int inverter(int *vetor_ori, int *vetor_dest, int tam);
int exibir(int *vetor, int tam);

void main(void){
    int n = 10;
    int nums[10]= {};
    int inver[10]= {};
    int i = 0;
    preencher(nums,n);
    inverter(nums,inver,n);
    exibir(nums,n);
    exibir(inver, n);

}

int preencher(int *vetor, int tam){
    int num;
    int i = 0;
    for(i; i< tam; i++){
        printf("Insira um valor para o %d numero do vetor, por favor: \n", (i+1));
        scanf("%d", &num);
        vetor[i] = num;
    }

}


int inverter(int *vetor_ori, int *vetor_dest, int tam){
    int i = tam-1;
    int n = 0;
    for(i; i>=0; i--){
        vetor_dest[n] = vetor_ori[i];
        n++;
    }

}

int exibir(int *vetor, int tam){
    int i = 0;
    printf("\n Vetor = [ ");
    for(i; i< tam; i++){
        printf("%d;", vetor[i]);
    }
        printf("]");

}

2)

#include <stdio.h>

int main() {
    int r[5];
    int s[10];
    int x[5];
    int tamX = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor de R[%d]: ", i);
        scanf("%d", &R[i]);
    }

    for (int j = 0; j < 10; j++) {
        printf("Digite o valor de S[%d]: ", j);
        scanf("%d", &S[j]);
    }

    for (int i = 0; i < 5; i++) {
        int achouS = 0;
        for (int j = 0; j < 10; j++) {
            if (R[i] == S[j]) {
                achouS = 1;
            }
        }
        if (achouS == 1) {
            int jaEstaEmX = 0;

            for (int k = 0; k < tamX; k++) {
                if (R[i] == X[k]) {
                    jaEstaEmX = 1;
                }
            }
            if (jaEstaEmX == 0) {
                X[tamX] = R[i];
                tamX++;
            }
        }
    }


    printf("Valores comuns:\n");
    for (int i = 0; i < tamX; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");

}

3)// era uma discursiva sobre as diferentes maneiras de colocar valores em indicees diferentes de um vetor

4)

#include <stdio.h>


int testa_pa(int n, int* v);

int main(void){
    int vetor[5] = {5,10,15,20,25};
    int vetorE[] = {5,2,6,88,100};
    int t = 5;
    int razao = testa_pa( t, vetor);
    int razao2 =testa_pa( t, vetorE);

    printf("%d", razao);
    printf("\n%d", razao2);


}

int testa_pa(int n, int *v){
    if (n<3){
        printf("Tamanho de vetor inválido");
    }
    int k = (v[1]-v[0]);
    int i;
    for (i = 2; i < n; i++ ){
        if ((v[i]-v[i-1]) != k ){
            return 0;
        }
    }

    return k;
}


5)


#include <stdio.h>
 void calcula_corrida(float dist, float *b1, float *b2);

 void main (){}

void calcula_corrida(float dist, float *b1, float *b2){
    *b1 = 4.95 +(2.5 * dist);
    *b2 = 4.95 +(3.00 * dist);

}


6)
#include <stdio.h>
int valida_mail(char *s);
void main(){
}

int valida_mail(char *s) {
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))) {
        return 0;
    }

    int i = 0;
    int cont = 0;
    char ultimo_char = '\0';

    while (s[i] != '\0' && i < 64) {
        char c = s[i];
        ultimo_char = c;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            cont++;
        }

        else if (c == '.' || c == '-' || c == '_') {

            if (c == '.' && i > 0 && s[i - 1] == '.') {
                return 0;
            }
        }

        else {
            return 0;
        }

        i++;
    }

    if (s[i] != '\0') {
        return 0;
    }

    if (ultimo_char == '.') {
        return 0;
    }


    if (cont < 2) {
        return 0;
    }

    return 1;
}


7)

#include <stdio.h>
#include <string.h>

void CamelCase(char *s);


void main() {
    char s[20];

    strcpy(s, "media da turma");
    CamelCase(s);
    printf("%s\n", s);
}

void CamelCase(char *s) {
    int i = 0;
    int j = 0;
    char aux[20];

    while (s[i] != '\0') {
        char l = s[i];
        if (i == 0) {
            if (l >= 'A' && l <= 'Z') {
                l = l + 32;
            }
            aux[j] = l;
            j++;
        }

        if (l == 32) {
            i++;
            l = s[i];

            if (l >= 'a' && l <= 'z') {
                l = l - 32;
            }
            aux[j] = l;
            j++;
        }

        else {
            aux[j] = l;
            j++;
        }
        i++;
    }
    aux[j] = '\0';
    strcpy(s, aux);
}


8)

#include <stdio.h>
#include <stdlib.h>

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


9)

#include <stdio.h>
#include <stdlib.h>

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
