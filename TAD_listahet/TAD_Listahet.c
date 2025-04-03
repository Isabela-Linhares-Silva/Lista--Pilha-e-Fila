#include <stdlib.h>


Listahet* lsthet_cria(void){
    return NULL;
}

/* LISTA LIBERA ! 
Parametros: 
l= cabeça da lista

Retorna: 
NULL
Libera toda a memoria da lista;

*/
Listahet* lsthet_libera(Listahet* l){
    Listahet* p = l;
    while (p!= NULL)
    {
        Listahet* temp= p->prox;
        free (p->info);
        free(p);
        p=temp;
        
    }
    return NULL;
}

/* LISTA INSERE!
l = cabeça da lista
id = chave primaria que identifica unicamente um obejeto da lista
tipo = inteiro definido que identifica o tipo guardado na lista
info = ponteiro void que guarda o endereço para a estrutura que guarda as informações de um tipo específico
RETURN : retorna o ponteiro da cabeça da lista
*/ 

Listahet* lsthet_insere(Listahet *l, int id, int tipo, void* info){
    Listahet * novo = (Listahet*)malloc(sizeof(Listahet));
    novo->id = id;
    novo->tipo = tipo;
    novo->info = info;
    novo->prox = l;

    return novo;
}

void * lsthet_cria_elemento(int tipo){
    switch (tipo)
    {
        case RET:
        Retangulo* ptr1 = (Retangulo*)malloc(sizeof(Retangulo));

        printf("Criando um RETANGULO: \n");
        printf("Digite a base: ");
        scanf("%f%*c",&ptr1->b);
        printf("Digite a altura: ");
        scanf("%f%*c",&ptr1->h);
        return (void*)ptr1;
        break;
    
        case CIR:
        Circulo* ptr2 = (Circulo*)malloc(sizeof(Circulo));

        printf("Criando um CIRCULO: \n");
        printf("Digite o raio: ");
        scanf("%f%*c",&ptr2->r);
        return (void*)ptr2;
        break;
    
        case TRI:
        Triangulo* ptr3 = (Triangulo*) malloc (sizeof(Triangulo));
        printf("Criando um TRIANGULO: \n");
        printf("Digite a base: ");
        scanf("%f%*c",&ptr3->b);
        printf("Digite a altura: ");
        scanf("%f%*c",&ptr3->h);
        return (void*)ptr3;
        break;
    
    default:
        printf("\nTipo indefinido!\n");
        return NULL;
    }
}

/* LISTA RETIRA! 
Parametros: 
l= cabeça da lista;
id= indice do elemento que deseja excluir;

Retorna:
Nova cabeça da lista. NULL, caso a lista esvazie.

*/
Listahet* lsthet_retira(Listahet* l, int id){
    Listahet* p = l;  
    Listahet* ant= NULL;
    while (p!= NULL)
    {
        if(p->id == id){
            break;
        }
        else
        {
            ant= p;
            p= p->prox;
        }
        
    } 
    
    if (p !=NULL)
    {
        //Elemento na cabeça da lista
        if (ant == NULL)
        {
            l = p->prox;// atualiza a cabeça da lista
        }
        //Elemento no corpo ou final da lista
        else{
            // matem a cabeça da lista
            ant->prox = p->prox ;//??? usa o p só na liberação ?

        }
        free(p->info);
        free(p);
        
    }
    
    return l;
}

/* LISTA VAZIA !

Parametros: 
l= cabeça da lista;

Retorna: 
inteiro sinalizando se a lista esta vazia(1) ou não(0)

*/

int lsthet_vazia(Listahet* l){
    return l == NULL;
}

/* LISTA BUSCA! 
Parametros:
l= cabeça da lista;
id = indice do elemento que deseja excluir;
Retorna: 
Ponteiro para o elemento buscado ou NULL, caso o elemneto nao seja encontrado
*/

Listahet* lsthet_busca(Listahet *l, int id){
    Listahet* p = l;
    while (p!=NULL)
    {
        if(p->id==id){
            printf("ELEMENTO ENCONTRADO\n");
            return p;
        }
        p=p->prox;
    }
    printf("ELEMENTO NAO ENCONTRADO!\n");
    return NULL;
    
}

void lsthet_imprime(Listahet *l){
    for( ;l!=NULL;l=l->prox){
        switch (l->tipo)
        {
        case RET:
            Retangulo* ret = (Retangulo*)l->info;
            printf("===RETANGULO===\n");
            printf("Base: %.2f\n",ret->b);
            printf("Altura: %.2f\n",ret->h);
            printf("===============\n");
            break;
        
        case CIR:
            Circulo* cir = (Circulo*)l->info;
            printf("===CIRCULO===\n");
            printf("Raio: %.2f\n",cir->r);
            printf("=============\n");
            break;

        case TRI:
            Triangulo* tri= (Triangulo*)l->info;
            printf("===TRIANGULO===\n");
            printf("Base: %.2f\n",tri->b);
            printf("Altura: %.2f\n",tri->h);
            printf("===============\n");
            break;
        
        default:
            break;
        }
    }
    
}