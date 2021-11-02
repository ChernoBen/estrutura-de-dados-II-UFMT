#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main(){
    tipo_no *lista;
    lista = NULL;
    //Questão número-1
    insereFim(&lista,6);
    insereFim(&lista,5);
    insereFim(&lista,4);
    insereFim(&lista,3);
    imprimeLista(lista);
}