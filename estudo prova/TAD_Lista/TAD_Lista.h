#include<stdlib.h>
typedef struct lista
{
    float info;
    struct lista * prox;
}Lista;
typedef Lista * LLista;

LLista cria_lista();
LLista insere_lista(LLista cabeca_lista,float valor);
LLista remove_lista(LLista cabeca_lista,float valor);
LLista busca_lista(LLista cabeca,float valor);
void imprime_lista(LLista cabeca_lista);
#include"TAD_Lista.c"