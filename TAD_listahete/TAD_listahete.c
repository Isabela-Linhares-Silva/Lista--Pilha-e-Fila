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
            printf("======CIRCULO======\n");
            printf("Informe o valor do raio: ");
            scanf("%f",&ptr1->raio);
            printf("===================\n");
            return (void*)ptr1;
            
            
        case RET:
            Ret* ptr2= (Ret*)malloc(sizeof(Ret));
            printf("====RETANGULO====\n");
            printf("Informe o valor base: ");
            scanf("%f",&ptr2->base);
            printf("Informe o valor da altura: ");
            scanf("%f",&ptr2->altura);
            printf("=================\n");
            return (void*)ptr2;
            
        case TRI:
            Tri* ptr3= (Tri*)malloc(sizeof(Tri));
            printf("====TRIANGULO====\n");
            printf("Informe o valor base: ");
            scanf("%f",&ptr3->base);
            printf("Informe o valor da altura: ");
            scanf("%f",&ptr3->altura);
            printf("=================");
            return (void*)ptr3;
            
        
        default:
            return NULL;
    }
}

int vazia_lista(Listahet* cabeca){
    return cabeca == NULL;
}

void imprime_lista(Listahet* cabeca){
    if (!vazia_lista(cabeca))
    {
        while (cabeca!= NULL)
        {
            switch (cabeca->tipo)
            {
                case CIR:
                    Cir* ptr1 = (Cir*)cabeca->info;
                    printf("======CIRCULO======\n");
                    printf("Raio: %f\n",ptr1->raio);
                    printf("===================\n");
                    break;
                case RET:
                    Ret* ptr2= (Ret*)cabeca->info;
                    printf("====RETANGULO====\n");
                    printf("Base: %f\n",ptr2->base);
                    printf("Altura: %f\n",ptr2->altura);
                    printf("=================\n");
                    break;

                case TRI:
                    Tri* ptr3= (Tri*)cabeca->info;
                    printf("====TRIANGULO====\n");
                    printf("Base: %f\n",ptr3->base);
                    printf("Altura: %f\n",ptr3->altura);
                    printf("=================\n");
                    break;
                default:
                    break;
            }
            cabeca = cabeca->prox;
        }
    }
}

Listahet * retira_lista( Listahet* cabeca, int id){
    Listahet* p = cabeca;
    Listahet* ant = NULL;
    while (p!=NULL)
    {

        if (p->id==id)
        {
            break;
        }
        else
        {
            ant= p;
            p= p->prox;
        }     
    }

    if (ant==NULL)
    {
        p= p->prox;
        
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p->info);
    free(p);
    return cabeca;
    
}
