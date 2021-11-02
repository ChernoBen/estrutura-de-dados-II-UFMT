#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main(){
    //chamadas comuns
    printf("inserção normal inicio\n");
    Lista *l1 = criaLista();
    l1 = insere_inicio(l1,4);
    l1 = insere_inicio(l1,5);
    l1 = insere_inicio(l1,6);
    imprime(l1);
    printf("inserção normal fim\n");
    l1 = insere_fim(l1,7);
    l1 = insere_fim(l1,8);
    l1 = insere_fim(l1,9);
    imprime(l1);
    printf("inserção normal ordenada\n");
    l1 = insere_ordenado(l1,1);
    l1 = insere_ordenado(l1,2);
    l1 = insere_ordenado(l1,3);
    imprime(l1);
    
    //chamadas recursivas
    Lista  *l2 = criaLista();
    //Questão número 1:
    printf("inserção recursiva fim\n");
    l2 = insere_fim_recursivo(l2,10);
    l2 = insere_fim_recursivo(l2,9);
    l2 = insere_fim_recursivo(l2,8);
    l2 = insere_fim_recursivo(l2,7);
    imprime(l2);
    
    // número 2:
    printf("inserção recursiva ordenada\n");
    l2 = insere_ordenado_recursivo(l2,l2,19);
    l2 = insere_ordenado_recursivo(l2,l2,18);
    l2 = insere_ordenado_recursivo(l2,l2,11);
    l2 = insere_ordenado_recursivo(l2,l2,4);
    imprime(l2);

    // número 3:
    printf("exclusao\n");
    l2 = exclui(l2,19);
    imprime(l2);

    // número 4:
    printf("alteracao\n");
    l2 = altera(l2,11,10);
    imprime(l2);  
}