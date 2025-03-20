#include<stdio.h>
#include<stdlib.h>
typedef struct lista{
    float info;
    struct lista* prox;
}Lista;
typedef Lista * LLista;

typedef struct pilha{
    LLista topo;
}Pilha;
typedef Pilha * PPilha;

PPilha cria_pilha();
int verifica_pilha(PPilha p);
void push_pilha(PPilha p,float valor);
float pop_pilha(PPilha p );
void imprime_pila(PPilha p);
void libera_pilha(PPilha p);

int main(){
    PPilha pil= cria_pilha();
    push_pilha(pil,1);
    push_pilha(pil,2);
    push_pilha(pil,3);
    imprime_pila(pil);
    printf("\n\n");
    pop_pilha(pil);
    imprime_pila(pil);
    return 0;
}

PPilha cria_pilha(){
    PPilha p = (PPilha)malloc(sizeof(Pilha));
    p->topo= NULL;
    return p;
}

int verifica_pilha(PPilha p){
    return p->topo==NULL;
}

void push_pilha(PPilha p,float valor){
    LLista nova = (LLista)malloc(sizeof(Lista));
    nova->info=valor;
    nova->prox= p->topo;
    p->topo= nova;

}

float pop_pilha(PPilha p ){
    if(p->topo==NULL)
    {
        printf("Pilha vazia!!");
        exit(1);
    }
    LLista aux;
    aux=p->topo;
    p->topo= aux->prox;

    float valor;
    valor=aux->info;
    free(aux);
    return valor;

}

void imprime_pila(PPilha p){
    LLista percorre = p->topo;
    if (!verifica_pilha(percorre))
    {
        while (percorre!=NULL)
        {
            printf("%f\n",percorre->info);
            percorre= percorre->prox;
        }
        
    }
    else{
        printf("Pilha vazia!");
    }
    
    
}

void libera_pilha(PPilha p){
    LLista passear= p->topo;
    while (passear!= NULL)
    {
        LLista aux = passear->prox;
        free(passear);
        passear= aux;
    }
    free(p);
    
}