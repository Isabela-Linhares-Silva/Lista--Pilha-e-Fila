#include<stdio.h>

int impar(int a);
int par(int a);
int primo(int a);

void imprime( int* v,int tam, int (*verifica)(int));

int main (){
    int vet[]= {1,2,10,25,33,40};
    int tam = sizeof(vet)/sizeof(int);//
    printf("Imprimindo pares: ");
    imprime(vet,tam,par);
    printf("\n");
    printf("Imprimindo impares: ");
    imprime(vet,tam,impar);
    printf("\n");
    printf("Imprimindo primos: ");
    imprime(vet,tam,primo);

    return 0;
}

int impar(int a){
    return a%2==1;
    
}
int par(int a){
    return a%2==0;
}
int primo(int a){
    int cont=0;
    for(int i = 1;i<=a;i++){
        if(a%i==0){
            cont++;
        }

    }
    return(cont == 2);
}


void imprime( int* v, int tam,int (*verifica)(int)){
    for (int  i = 0; i < tam; i++)
    {
        if (verifica(v[i]))
        {
            printf("%d ", v[i]);
        }
        
    }
    
}