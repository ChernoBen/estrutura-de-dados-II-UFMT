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
Lista *insereFim(Lista *lista,int vl);
void imprimeLista(Lista *lista);
//-------implementações

//metodo para criar lista
Lista *criaLista(){
    return NULL;
}

//metodo que insere recursivamente um valo no final da lista
Lista *insereFim(Lista *lista,int vl){
    Lista *ls = lista;
    if(ls == NULL){
        Lista *novo_no = (Lista*)malloc(sizeof(Lista));
        novo_no->valor = vl;
        novo_no->prox = NULL;
        return novo_no;
    }else{
        ls->prox = insereFim(ls->prox,vl);
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


#endif