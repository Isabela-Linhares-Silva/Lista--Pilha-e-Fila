#include<stdio.h>
#include<stdlib.h>
typedef struct lista{
    int info;
    struct lista* prox;
}Lista;
typedef Lista * LLista;
LLista lista_cria();
LLista lista_insere (LLista lista, int valor);
LLista lista_remove (LLista lista, int valor);
LLista lista_busca (LLista lista, int valor);

int main(){

    return 0;
}

LLista cria_lista(){
   return NULL;

}

LLista lista_insere (LLista lista, int valor){
    LLista novo= (LLista)malloc(sizeof(Lista));
    novo->info= valor;
    novo->prox= lista;
}

LLista lista_remove (LLista lista, int valor){

}

LLista lista_busca (LLista lista, int valor){

}

