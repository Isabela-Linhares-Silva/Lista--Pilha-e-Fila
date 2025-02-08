#include<stdio.h>
#include<stdlib.h>
typedef struct lista{
    float info;
    LLista prox;
}Lista;
typedef Lista* LLista;

typedef struct fila{
    LLista ini;
    LLista fim;
}Fila;
typedef Fila* FFila;

FFila fila_cria ();
void fila_insere(FFila f, float v);
float fila_retira(FFila f);
int fila_vazia(FFila f);
void fila_libera(FFila f);

int main(){

    return 0;
}

FFila fila_cria (){
    FFila f= (FFila)malloc(sizeof(Fila));
    f->ini= NULL;
    f->fim=NULL;
    return f;
}

void fila_insere(FFila f, float v){
    LLista n= (LLista)malloc(sizeof(Lista));
    n->info = v;
    n->prox= NULL;
    if(f->fim!=NULL){
        f->fim->prox= n;

    }
    else{
        f->ini=n;
    }
    f->fim=n;

}
