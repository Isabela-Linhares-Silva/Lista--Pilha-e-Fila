#include<stdio.h>
#include"TAD_Listahet/TAD_Listahet.h"
int main(){
    Listahet* minha_lista = lsthet_cria();
    minha_lista = lsthet_insere(minha_lista,1,RET,lsthet_cria_elemento(RET));
    minha_lista = lsthet_insere(minha_lista,2,CIR,lsthet_cria_elemento(CIR));
    minha_lista = lsthet_insere(minha_lista,3,TRI,lsthet_cria_elemento(TRI));
    lsthet_imprime(minha_lista);
    printf("\n");
    lsthet_busca(minha_lista,2);
    lsthet_libera(minha_lista);


    return 0;
}
