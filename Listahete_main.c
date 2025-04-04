#include<stdio.h>
#include"TAD_listahete\TAD_listahete.h"

int main(){
    Listahet* minha_lista = cria_lista();
    minha_lista= insere_lista(minha_lista,1,CIR,cria_elemento(CIR));
    minha_lista= insere_lista(minha_lista,2,RET,cria_elemento(RET));
    minha_lista= insere_lista(minha_lista,3,TRI,cria_elemento(TRI));
    printf("\n");
    imprime_lista(minha_lista);
    return 0;
}