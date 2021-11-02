#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main(){
    Lista  *ls = criaLista();
    //Questão número-1
    ls = insereFim(ls,10);
    ls = insereFim(ls,9);
    ls = insereFim(ls,8);
    ls = insereFim(ls,7);
    imprimeLista(ls);
    
    
}