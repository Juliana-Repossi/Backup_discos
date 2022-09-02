#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

// Implementação de uma heap max 
typedef struct heap heap;

heap* alocaHeap(int tam);

//retorna 1 se adicionou disco ou zero, caso contrario
int insereHeap(heap *heap,int i);

static inline int esq(int indice);
static inline int dir(int indice);
static inline int pai(int indice);

void atualizaVetorParaCima(heap* heap, int posicao);

void heapify(heap *heap);

void imprime(heap *heap);

void liberaHeap(heap *Heap);

#endif