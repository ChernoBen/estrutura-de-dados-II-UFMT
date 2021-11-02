#ifndef UTILS_C
#define UTILS_C
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct estru_no{
    int valor;
    struct estru_no *prox;
};
typedef struct estru_no tipo_no;

//----------assinaturas
tipo_no *alocaNovoNo(int vl);
void insereFim(tipo_no **ls,int vl);
void imprimeLista(tipo_no *ls);


//----------implementação
//funcao que aloca endereco de memoria
tipo_no *alocaNovoNo(int vl){
    tipo_no *novo_no;
    novo_no = (tipo_no*)malloc(sizeof(tipo_no));
    novo_no->valor = vl;
    novo_no->prox = NULL;
    return novo_no;
}
//funcao que insere recursivamente valor no final da lista
void insereFim(tipo_no **ls,int vl){
    if((*ls)==NULL){
        tipo_no *novo_no;
        novo_no = alocaNovoNo(vl);
        (*ls) = novo_no;
    }else{
        insereFim(&(*ls)->prox,vl);
    }
}

//funcao que imprime valores da lista
void imprimeLista(tipo_no *ls){
    if(ls==NULL){
        printf("Lista vazia\n");
    }else{
        printf("Inicio->[");
        while(ls!=NULL){
            printf("%d ",ls->valor);
            ls = ls->prox;
        }
        printf("]<-fim\n");
    }
}

#endif