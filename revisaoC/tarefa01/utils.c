#ifndef UTILS_C
#define UTILS_C
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct lista{
    int valor;
    struct lista *prox;
}Lista;

//-------assinaturas
Lista *criaLista();
Lista *insere_fim_recursivo(Lista *lista,int vl);
void imprimeLista(Lista *lista);
Lista *insere_ordenado_recursivo(Lista *lista,Lista *ant,int vl);
Lista *exclui(Lista *lista, int valor);
Lista *altera(Lista *lista, int valor,int novo_valor);
Lista *insere_inicio(Lista *lista,int valor);
Lista *insere_fim(Lista *lista,int valor);
Lista *insere_ordenado(Lista *lista,int valor);
void imprime(Lista *lista);

//-------implementações

//metodo para criar lista
Lista *criaLista(){
    return NULL;
}

//metodo que insere valores de forma ordenada
Lista *insere_ordenado(Lista *lista,int valor){
    Lista *novo_no;
    Lista *ant = NULL;
    Lista *prox = lista;
    while(prox!=NULL && prox->valor < valor){
        ant = prox;
        prox = prox->prox;
    }
    novo_no = (Lista*)malloc(sizeof(Lista));
    novo_no->valor = valor;
    if(ant == NULL){
        novo_no->prox = lista;
        lista = novo_no;
    }else{
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
    }
    return lista;
}

//metodo que insere de forma ordenada recursivamente
Lista *insere_ordenado_recursivo(Lista *lista,Lista *ant,int vl){
    //lp lista -> proxima posicao
    //la lista valor anterior
    Lista *lp = lista;
    Lista *la = ant;
    if (lp!=NULL && lp->valor < vl){
        la = lp;
        lp->prox = insere_ordenado_recursivo(lp->prox,la,vl);
    }else{
        Lista *novo_no = (Lista*)malloc(sizeof(Lista));
        novo_no->valor = vl;
        if(la==NULL){
            novo_no->prox = la;
            la = novo_no;
        }else{
            novo_no->prox = la->prox;
            la->prox = novo_no;
        }
        return novo_no;
    }
    return lp;
}

//metodo que insere valor no inicio da lista
Lista *insere_inicio(Lista *lista,int valor){
    Lista *novo_no = (Lista*)malloc(sizeof(Lista));
    novo_no->valor = valor;
    novo_no->prox = lista;
    return novo_no;
}

//metodo que insere valor no fim da lista
Lista *insere_fim(Lista *lista,int valor){
    Lista *novo_no = (Lista*)malloc(sizeof(Lista));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    Lista *prox,*ant;
    prox = lista;
    ant = lista;
    while(prox !=NULL){
        ant = prox;
        prox = prox->prox;
    }
    if(ant !=NULL){
        ant->prox = novo_no;
    }else{
        lista = novo_no;
    }
    return lista;
}

//metodo que insere recursivamente um valo no final da lista
Lista *insere_fim_recursivo(Lista *lista,int vl){
    Lista *ls = lista;
    if(ls == NULL){
        Lista *novo_no = (Lista*)malloc(sizeof(Lista));
        novo_no->valor = vl;
        novo_no->prox = NULL;
        return novo_no;
    }else{
        ls->prox = insere_fim_recursivo(ls->prox,vl);
    }
    return ls;
}

//metodo que imprime elementos da lista
void imprimeLista(Lista *lista){
    if(lista==NULL){
        printf("Lista vazia");
    }else{
        printf("inicio->[");
        while(lista!=NULL){
            printf("%d ",lista->valor);
            lista = lista->prox;
        }
        printf("]<-fim\n");
    }
}

//metodo que exclui um elemento da lista
Lista *exclui(Lista *lista, int valor){
    Lista *ls = lista;
    if(lista->valor == valor){
        lista = lista->prox;
        free(ls);
        return lista;
    }
    Lista *anterior;
    while (ls != NULL){
        anterior = ls;
        ls = ls->prox;
        if(ls && ls->valor == valor){
            anterior->prox = ls->prox;
            free(ls);
            return lista;
        }
    }
    printf("valor não existe.\n");
    return lista;
}

//metodo que altera um valor em determinada posicao da lista
Lista *altera(Lista *lista, int valor,int novo_valor){
    Lista *ls = lista;
    while(ls!=NULL){
        if(ls->valor==valor){
           ls->valor = novo_valor;
           return lista;
        }
        ls = ls->prox;
    }
    printf("Valor não encontrado\n"); 
}

//metodo que imprime valores da lista
void imprime(Lista *lista){
    Lista *prox;
    for (prox = lista;prox!=NULL;prox = prox->prox){
        printf("%d ",prox->valor);
    }
    printf("\n");
}
#endif