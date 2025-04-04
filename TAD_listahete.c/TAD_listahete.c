#include<stdlib.h>
#include"TAD_listahete.h"


Listahet* cria_lista(){
    return NULL;
}

Listahet * insere_lista(Listahet* cabeca, int id, int tipo, void* info){
    Listahet* novo=(Listahet*)malloc(sizeof(Listahet));
    novo->id=id;
    novo->info= info;
    novo->tipo= tipo;
    novo->prox=cabeca;
    return novo;
}

Listahet* libera_lista(Listahet* cabeca){
    Listahet* p= cabeca;
    while (p!= NULL)
    {
        Listahet *temp= p->prox;
        free(p->info);
        free(p);
        p=temp;
    }
    return NULL;
    
}

Listahet* busca_lista(Listahet* cabeca, int id){
    
    for (Listahet* p = cabeca; p->id != id ; p=p->prox)
    {
        if (p->id == id)
        {
            printf("O elemento foi encontrado!");
            return p;
        }
        
    }
    printf("O elemento nao foi encontrado!");
    return NULL;
    
}

void* cria_elemento(int tipo){
    switch (tipo)
    {
    case CIR:
        Cir* ptr1 = (Cir*)malloc(sizeof(Cir));
        printf("======CIRCULO======");
        printf("Informe o valor do raio: ");
        scanf("%f",&ptr1->raio);
        printf("===================");
        return (void*)ptr1;
        
        break;
    case RET:
        Ret* ptr2= (Ret*)malloc(sizeof(Ret));
        printf("====RETANGULO====");
        printf("Informe o valor base: ");
        scanf("%f",&ptr2->base);
        printf("Informe o valor da altura: ");
        scanf("%f",&ptr2->altura);
        printf("=================");
        return (void*)ptr2;
        break;
    case TRI:
        Tri* ptr3= (Tri*)malloc(sizeof(Tri));
        printf("====TRIANGULO====");
        printf("Informe o valor base: ");
        scanf("%f",&ptr3->base);
        printf("Informe o valor da altura: ");
        scanf("%f",&ptr3->altura);
        printf("=================");
        return (void*)ptr3;
        break;
    
    default:
        break;
    }
}