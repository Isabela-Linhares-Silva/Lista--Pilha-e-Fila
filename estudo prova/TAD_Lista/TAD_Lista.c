#ifndef __TAD_LISTA_C__
#define __TAD_LISTA_C__


LLista cria_lista(){
    return NULL;
}

LLista insere_lista(LLista cabeca_lista,float valor){
    LLista novo = (LLista)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return cabeca_lista;  // Retorna a lista original sem alterações
    }
    novo->info= valor;
    novo->prox = cabeca_lista;
    return novo;
}

LLista remove_lista(LLista cabeca_lista,float valor){
    LLista p=cabeca_lista;
    LLista aux = NULL;
    while (p!=NULL && p->info!=valor)
    {
        aux = p;
        p = p->prox;
    }
    
    if (p==NULL)
    {
        return cabeca_lista;
    }
    
    if(aux==NULL){
        cabeca_lista = p->prox;

    }
    else
    {
        aux->prox = p->prox ;
    }
    free(p);
    return cabeca_lista;
    

}

LLista busca_lista(LLista cabeca,float valor){
    LLista p=cabeca;
    while (p!=NULL)
    {
        if (p->info==valor)
        {
            return p;
        }
        p=p->prox;
        
    }
    return NULL;

}

void imprime_lista(LLista cabeca_lista){
    LLista p= cabeca_lista;
    for ( p = cabeca_lista; p !=  NULL; p= p->prox)
    {
        printf("Elemento: %f\n",p->info);
    }
    
}

#endif
