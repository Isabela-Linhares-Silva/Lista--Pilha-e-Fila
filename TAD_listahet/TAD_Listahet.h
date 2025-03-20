#ifndef __TAD_LISTAHET_H__
    #define __TAD_LISTAHET_H__

    #define RET 0
    #define CIR 1
    #define TRI 2

    

    struct listahet{
        int id;
        int tipo;
        void* info;//ponteiro amofo
        struct listahet* prox;
    };

    typedef struct listahet Listahet;

    struct retangulo
    {
        float h;
        float b;
    };

    typedef struct retangulo Retangulo;

    struct triangulo{
        float b;
        float h;
    };

    typedef struct triangulo Triangulo;

    struct circulo{
        float r;
    };

    typedef struct circulo Circulo;
    

    Listahet* lsthet_cria(void);
    Listahet* lsthet_libera(Listahet* l);

    void * lsthet_cria_elemento(int tipo);

    Listahet* lsthet_insere(Listahet *l, int id, int tipo, void* info);
    Listahet* lsthet_retira(Listahet* l, int id);

    int lsthet_vazia(Listahet* l);
    Listahet* lsthet_busca(Listahet *l, int id);
    void lsthet_imprime(Listahet *l);

    #include "TAD_Listahet.c"
#endif