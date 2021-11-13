#include <stdio.h>
#include <stdlib.h>

//estrutura aluno será atabela hash
typedef struct aluno{
    int matricula;
    float coefiente;
    struct aluno *prox;
}TAluno;
typedef TAluno* Hash;

//assinaturas
void inicializa(Hash *tab, int tamanho);
int hash(int matricula,int tamanho);
void insere(Hash *tab,int tamanho,int matricula, float coeficiente);
TAluno *aloca(int matricula,float coefiente);
//void imprime(Hash *tab, int tamanho);

int main(){
    //tamanho da tabela
    int m;
    m = 5;
    //criando tabela/ array que guarda ponteiros do tipo Hash
    Hash *tab[m];
    //iniciar as posições com NULL
    //inicializa(tab,m);
    //insere(tab,m,12,5.8);
    //insere(tab,m,11,4.7);
    //insere(tab,m,10,3.6);
    //imprime(tab,m);
}

//implementações

//metodo que inicializa as posicões da tabela como NULL
void inicializa(Hash *tab, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        tab[i] = NULL;
    }
}

//metodo que insere valores na tabela
void insere(Hash *tab,int tamanho,int matricula, float coeficiente){
    /*
    matricula é a chave a ser passada para a função hash
    quer retornará o indice a ser inserido.
    */
   int h = hash(matricula,tamanho);
   TAluno *posicao = tab[h];
   //anterior é uma variavel auxiliar para guardar a posição anterior da lista encadeada
   TAluno *anterior = NULL;
   /*
    Percorra a lista até achar o ultimo elemento
    ou se encontrar o numero de matricula:
        execute o processo dentro do while
   */
    while((posicao!= NULL) && (posicao->matricula != matricula)){
        anterior = posicao;
        posicao = posicao->prox;
    }
    //criar novo nó
    TAluno *novo = aloca(matricula,coeficiente);
    //e anterior existir entao a tabela recebe novo
    if(anterior){
        tab[h] = novo;
    }else{
        anterior->prox = novo;
    }
}

//metodo que aloca um novo aluno
TAluno *aloca(int matricula,float coefiente){
    TAluno *novo = (TAluno*) malloc (sizeof(TAluno));
    novo->matricula = matricula;
    novo->coefiente = coefiente;
    novo->prox = NULL;
    return novo;
}

//metodo responsável por distribuir as informações pela tabela / gerar indice
int hash(int matricula,int tamanho){
    /*
    formula:
        hash(matricula) = matricula mod tamanho 
    */
    return matricula % tamanho;
}

//metodo que imprime valores da tabela hash
/*
void imprime(Hash *tab, int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d",i);
        if(tab[i]){
            TAluno *posicao = tab[i];
            printf("\n");
            while(posicao){
                printf("\t%d\t%f\t%p\n",posicao->matricula,posicao->coefiente,posicao->prox);
                posicao = posicao->prox;
            }
        }else printf("NULL\n");
    }
}
*/