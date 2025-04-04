#ifndef __TAD_LISTAHETE_H__
    #define __TAD_LISTAHETE_H__

    //chora buaaaaa buaa
    #include<stdio.h>
    #define RET 0
    #define CIR 1
    #define TRI 2

    typedef struct listahet
    {
        int id;
        int tipo;
        void* info;
        struct listahet * prox; 
    }Listahet;

    typedef struct circulo
    {
        float raio;
    }Cir;

    typedef struct retangulo
    {
        float base;
        float altura;
    }Ret;

    typedef struct triangulo
    {
        float base;
        float altura;
    }Tri;

    Listahet* cria_lista();
    int vazia_lista(Listahet* cabeca);
    Listahet * insere_lista(Listahet* cabeca, int id, int tipo, void* info);
    Listahet* libera_lista(Listahet* cabeca);
    Listahet* busca_lista(Listahet* cabeca, int id);
    void* cria_elemento(int tipo);
    void imprime_lista(Listahet* cabeca);
    Listahet * retira_lista( Listahet* cabeca, int id);

    
    
    
    

    #include"TAD_listahete.c"
#endif