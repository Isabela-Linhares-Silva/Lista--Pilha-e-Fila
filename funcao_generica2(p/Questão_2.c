#include<stdio.h>

     /*Implemente uma função chamada processa que recebe um vetor
    de inteiros, seu tamanho e dois callbacks: um para aplicar 
    uma transformação em cada elemento do vetor e outro para 
    definir uma condição de exibição na tela. O programa deve 
    modificar os elementos do vetor conforme o primeiro callback
    e imprimir apenas aqueles que satisfazem o segundo callback.
    Teste a função com diferentes combinações, como dobrar os 
    valores e exibir apenas os números divisíveis por 5, ou calcular
    o quadrado e exibir apenas os maiores que 50.*/
int dobra(int a);
int div(int a);
int quadrado(int a);
int maior(int a);


void processa(int* v, int tam, int (*transforma)(int), int(*condicao)(int));


int main(){
    int vet[]={2,5,8,10};
    processa(vet,4,dobra,div);
    printf("\n");
    processa(vet,4,quadrado,maior);
    return 0;
}

int dobra(int a){
    return a*2;
}

int div(int a){
    return a%5==0;
}

int quadrado(int a){
    return a*a;
}

int maior(int a){
    return a>50;
}

void processa(int* v, int tam, int (*transforma)(int), int(*condicao)(int)){
    for (int i = 0; i < tam; i++)
    {
        if(condicao(transforma(v[i]))){
            printf("%d ",v[i] );
        }
    }
    
}