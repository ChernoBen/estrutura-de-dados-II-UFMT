#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main(){
    Lista  *ls = criaLista();
    //Questão número 1:

    ls = insereFim(ls,10);
    ls = insereFim(ls,9);
    ls = insereFim(ls,8);
    ls = insereFim(ls,7);
    imprimeLista(ls);
    
    // número 2:
    ls = insere_ordenado_recursivo(ls,ls,19);
    ls = insere_ordenado_recursivo(ls,ls,18);
    ls = insere_ordenado_recursivo(ls,ls,11);
    ls = insere_ordenado_recursivo(ls,ls,4);
    imprimeLista(ls);

    // número 3:
    ls = exclui(ls,19);
    imprimeLista(ls);

    // número 4:
    ls = altera(ls,11,10);
    imprimeLista(ls);  
}