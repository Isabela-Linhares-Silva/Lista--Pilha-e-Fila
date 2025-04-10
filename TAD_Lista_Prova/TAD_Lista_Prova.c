#include"TAD_Lista_Prova.h"
#include<stdlib.h>

Lista* cria_lst(){
    return NULL;
}

int vazia_lst(Lista* l){
    return l == NULL;
}

Lista* insere_lst(Lista* l, void * info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));

    novo->info= info;
    novo->prox = l;
    
    return novo;
}

Lista* retira_lst(Lista* l, void * info){
    Lista* p = l;
    Lista* ant = NULL;
    while (p!= NULL)
    {
        if (p->info == info)
        {
            break;
        }
        else{
            ant = p;
        }
        
        p= p->prox;
    }
    
    
    if (vazia_lst(p))
    {
        return l;
    }
    
    if (ant == NULL)
    {
        l = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    
    free(p->info);
    free(p);
    return l;
}

Lista* busca_lst(Lista* l, void * info){
    if (!(vazia_lst(l)))
    {
        while (l!=NULL)
        {
            if (l->info==info)
            {
                printf("Elemento encontrado! YAY!");
                return l;
            }
            l = l->prox;
        }
            
        printf("Elemento não foi encontrado! Ahhhh!");
        return NULL; 
    }
    return NULL;
    
}

void imprime_lst(Lista* l, void (*imprime)(void*)){
    for (; l != NULL; l = l->prox)
    {
        (imprime(l->info));
    }
    
}

Lista* libera_lst(Lista* l){
    Lista* p = l;
    while (p!= NULL)
    {
        l=l->prox;

        free(p);
        p=l;
    }
    return NULL;
}