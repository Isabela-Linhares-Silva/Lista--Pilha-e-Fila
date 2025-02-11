#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
    float info;
    struct lista* prox; 
}Lista;
typedef Lista* LLista;

typedef struct pilha
{
    LLista inicio;
}Pilha;
typedef Pilha* PPilha;

PPilha cria_pilha();
int compara_pilha(PPilha p);
void push_pilha(PPilha p, float valor);
float pop_pilha(PPilha p);
void libera_pilha(PPilha p);


int main(){
    PPilha piu= cria_pilha();
    push_pilha(piu,3);
    push_pilha(piu,5);
    push_pilha(piu,7);
    float v= pop_pilha(piu);
    printf("VALOR RETIRADA DA PILHA: %.2f",v);
    libera_pilha(piu);

return 0;
}

PPilha cria_pilha(){
    PPilha p= (PPilha)malloc(sizeof(Pilha));
    p->inicio = NULL;
    return p;

}

int compara_pilha(PPilha p){
    return p->inicio == NULL;
}

void push_pilha(PPilha p, float valor){
    LLista nova_lista = (LLista)malloc(sizeof(Lista));
    nova_lista->info = valor;
    nova_lista->prox = p->inicio;
    p->inicio = nova_lista;

}

float pop_pilha(PPilha p){
    if(compara_pilha(p))
    {
        printf("PILHA VAZIA\n");
        exit(1);
    }
    LLista aux;
    aux = p->inicio;
    p->inicio= aux->prox;

    float valor;
    valor = aux->info;
    free(aux);
    return valor;
}

void libera_pilha(PPilha p){
    LLista passear = p->inicio;
    while(passear!=NULL)
    {
        LLista auxiliar;
        auxiliar = passear->prox;
        free(passear);
        passear = auxiliar;
    }
    free(p);
}