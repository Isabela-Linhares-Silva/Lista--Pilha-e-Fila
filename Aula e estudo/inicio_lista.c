#include <stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista* prox;
}Lista;
typedef Lista * LLista;

//lst_atual = cabeça da lista
LLista lst_cria();
LLista lst_insere(Lista* lst_atual, int valor);
void lst_imprime(LLista lst_atual);
int lst_vazia(LLista lst_atual);
LLista lst_busca(LLista lst_atual,int num);
LLista lst_retira(LLista lst_atual,int valor);
void lst_libera(LLista lst_atual);
int conta_lista(LLista lst_atual);

LLista lst_max(LLista lst_atual);
LLista lst_crescente(LLista lst_atual);
LLista lst_min(LLista lst_atual);
LLista lst_decres(LLista lst_atual);



int main()
{
    LLista prim= lst_cria();
    prim= lst_insere(prim,1);
    prim= lst_insere(prim,2);
    prim= lst_insere(prim,3);
    prim= lst_insere(prim,4);

    printf("%d",conta_lista(prim));
    printf("\n");
    
    lst_imprime(prim);
    /*lst_retira(prim,3);
    printf("\n");
    lst_imprime(prim);*/

    printf("\n");

    LLista copia_prim1 = lst_copia(prim);  
    LLista copia_prim2 = lst_copia(prim);  
    
    LLista maioral = lst_crescente(copia_prim1);
    printf("Ordem crescente: \n");
    lst_imprime(maioral);
    
    printf("\n");
    
    LLista minmin = lst_decres(copia_prim2);
    printf("Ordem decrescente: \n");
    lst_imprime(minmin);
    
 

    

    
    return 0;
}

LLista lst_cria(){
    return NULL; 
}

LLista lst_insere(Lista* lst_atual, int valor){
    LLista novo= (LLista) malloc (sizeof(Lista));
    novo->info=valor;
    novo->prox= lst_atual;// recebe um ponteiro para a cabeça da lista atual
    return novo;
}

void lst_imprime(LLista lst_atual){
    LLista p;
    p= lst_atual;
    /*if(p!=NULL)
        printf("Elemento: %d ",p->info);
    p= p->prox;
    if(p!=NULL)
        printf("Elemento: %d ",p->info);*/
    
    for(p=lst_atual;p!=NULL;p= p->prox){
        printf("Elemento: %d ",p->info);
        printf("\n");

    }

}
int lst_vazia(LLista lst_atual){
    return (lst_atual==NULL);
}

LLista lst_busca(LLista lst_atual,int num){
    LLista p;
    for(p= lst_atual;p!= NULL;p=p->prox){
        if(p->info == num)
            return p;
    }
    return NULL; // não achou o elemento procurado
}

LLista lst_retira(LLista lst_atual,int valor){
    LLista ant = NULL;
    LLista p= lst_atual;//cópia da cabeça da lista atual
    //for(p=lst_atual;p!= NULL && p->info!= valor;p=p->prox)
    while( p != NULL && p->info!= valor){// ir para o proximo elemnto
        ant =p;
        p= p->prox;

    }
    if(p==NULL)// elemento não foi encontrado(rodou a lista inteira e chegou no final)
    {
        return lst_atual;
    }

    //agora vai se for encontrado
    if(ant==NULL){
        lst_atual = p->prox;

    }
    else{
        ant->prox= p->prox ;
    }
    free(p);
    return lst_atual;
}

void lst_libera(LLista lst_atual){
    LLista p= lst_atual;
    while(p->prox!= NULL){
        LLista t= p->prox;
        free(p);
        p= t;
    }
}

int conta_lista(LLista lst_atual){
    int cont=0;
    
    while (lst_atual!=NULL)
    {
        cont++;
        lst_atual=lst_atual->prox;
    }
        
    
    return cont;

}




LLista lst_max(LLista lst_atual){
    if (lst_atual == NULL) return NULL;  // Retorna NULL se a lista for vazia
    
    LLista maior = lst_atual;
    LLista p = lst_atual->prox;  // Começa a busca no segundo nó

    while (p != NULL) {
        if (maior->info < p->info) {
            maior = p;
        }
        p = p->prox;
    }
    return maior;
}


LLista lst_crescente(LLista lst_atual){
    if (lst_atual == NULL) 
        return NULL;  

    LLista lst_ordena = lst_cria();  

    while (lst_atual != NULL) {  
        LLista maior = lst_max(lst_atual);  
        if (maior != NULL) {  
            lst_ordena = lst_insere(lst_ordena, maior->info);
            lst_atual = lst_retira(lst_atual, maior->info);  
        }
    }
    return lst_ordena;
}


LLista lst_min(LLista lst_atual){
    if (lst_atual == NULL) 
        return NULL;  
    
    LLista min = lst_atual;
    LLista p = lst_atual->prox;
    while (p != NULL) {
        if (min->info > p->info) {
            min = p;
        }
        p = p->prox;
    }
    return min;
}

LLista lst_decres(LLista lst_atual){
    if (lst_atual == NULL)
        return NULL;  
    LLista ordena = lst_cria();  

    while (lst_atual != NULL) { 
        LLista menor = lst_min(lst_atual);  
        if (menor != NULL) {  
            ordena = lst_insere(ordena, menor->info);
            lst_atual = lst_retira(lst_atual, menor->info);  
        }
    }
    return ordena;
}