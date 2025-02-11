#include<stdio.h>
#include"TAD_Lista/TAD_Lista.h"

int main(){
    LLista listinha= cria_lista();
    listinha= insere_lista(listinha,1);
    listinha= insere_lista(listinha,2);
    listinha= insere_lista(listinha,3);
    listinha= insere_lista(listinha,4);
    listinha= insere_lista(listinha,7);

    float n;
    printf("Informe o numero que deseja consultar: ");
    scanf("%f%*c",&n);
    LLista buscando= busca_lista(listinha,n);
    if (buscando!=NULL)
    {
        printf("Encontrado!!!!\n");
    }
    else
    {
        printf("Ahh :(, nao foi encontrado\n");
    }
    float m;
    printf("Informe o numero que deseja excluir: ");
    scanf("%f%*c",&m);
    printf("\nAntes: \n");
    imprime_lista(listinha);
    listinha= remove_lista(listinha,m);
    printf("\nDepois: \n");
    imprime_lista(listinha);
    
    
    return 0;
}