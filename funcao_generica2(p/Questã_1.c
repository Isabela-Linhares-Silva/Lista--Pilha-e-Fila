#include<stdio.h>
#include<stdlib.h>

int dobra(int a);
int quadrado(int a);
int inverte(int a);

void transforma(int* vet, int tam, int (*faz)(int));

int main(){
    int vet[]={1,4,5,6,9};
    transforma(vet,5,dobra);
    printf("\n");
    transforma(vet,5,quadrado);
    printf("\n");
    transforma(vet,5,inverte);
    printf("\n");
    
    
    return 0;
}

int dobra(int a){
    return a*2;
}
int quadrado(int a){
    return a*a;
}
int inverte(int a){
    return a*(-1);
}

void transforma(int* vet, int tam, int (*faz)(int)){
    for(int i=0; i<tam;i++){
        printf("%d ", faz(vet[i]));
    }
}


