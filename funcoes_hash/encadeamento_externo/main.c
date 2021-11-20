#include <stdio.h>
#include <stdlib.h>
#include "hash.c"


int main(){
    //tamanho da tabela
    int m;
    m = 5;
    //criando tabela/ array que guarda ponteiros do tipo Hash
    Hash *tab[m];
    //iniciar as posições com NULL
    inicializa(tab,m);
    insere(tab,m,12,5.8);
    insere(tab,m,11,4.7);
    insere(tab,m,10,3.6);
    imprime(tab,m);
    TAluno *p = busca(tab,m,12);
    if(!p)printf("Não encontrado\n");
    else printf("%d\t%f\n",p->matricula,p->coefiente);
    float cr = excluir(tab,m,11);
    if(cr != -1)printf("indice: %f excluido \n",cr);
    imprime(tab,m);
    libera(tab,m);
    return 0;
}

