#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arv arv;

//Cria uma arvore vazia
arv* abb_cria();

//imprime arvore em ordem
void abb_imprime(arv *a);

//insere de acordo com a politica de bestfit na árvore de discos
arv* insereArvore(arv *a,long int num,int *qtdDiscos);

//Busca na arvore o long int e retorna o "nó" caso ache
// ou null caso não encontre espaço
arv* abb_busca(arv *a, long int num);

//insere na arvore um inteiro 
arv* abb_insere(arv *a,long int num);

//static arv* abb_balanciada(arv *a);

arv* abb_retira(arv *no, long int num);

//libera a estrutura arvore alocada
arv* abb_libera(arv *a);

#endif