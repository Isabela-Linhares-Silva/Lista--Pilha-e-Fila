#include <stdio.h>
#include <stdlib.h>

typedef struct no_lista
{
    int info;
    struct no_lista * prox;
}No_lista;
typedef No_lista * NO_lista;


NO_lista *cria_lista();
void insere_lista(NO_lista * cabeca_lista, int valor);

int main()
{
    return 0;
}

NO_lista *cria_lista()
{
    return NULL;
}
void insere_lista(NO_lista * cabeca_lista, int valor)
{
    NO_lista  novo = (NO_lista )malloc(sizeof(No_lista));
    while(novo == NULL)
    {
        novo->info = valor;
        novo->prox = cabeca_lista;
        cabeca_lista = novo;
    }
}
