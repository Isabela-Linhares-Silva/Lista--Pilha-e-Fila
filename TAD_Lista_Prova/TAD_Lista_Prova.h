#ifndef __TAD_LISTA_PROVA_H__
    #define __TAD_LISTA_PROVA_H__
    

    typedef struct lista
    {
        void* info;
        struct lista* prox;
    }Lista;
    
    Lista* cria_lst();
    int vazia_lst(Lista* l);
    Lista* insere_lst(Lista* l, void * info);
    Lista* retira_lst(Lista* l, void * info);
    Lista* busca_lst(Lista* l, void * info);
    void imprime_lst(Lista* l,(void *imprime)(void *));
    Lista* libera_lst(Lista* l);
#endif    