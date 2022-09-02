#include "../include/heap.h"

#define TAM_DISCO 1000000

struct heap
{
  long int *vetor;
  int lotacao;
};

heap* alocaHeap(int tam)
{
  heap *H = (heap*)malloc(sizeof(heap));  

  //aloca menbros internos 
  H->vetor = (long int*)calloc(tam,sizeof(long int));
  H->lotacao = -1; 

  return H;
}

int insereHeap(heap *heap,int i)
{
  //verificar se a heap ta vazia
  if(heap->lotacao != -1)
  {
    //vai verificar se cabe na raiz
    if( heap->vetor[0] >= i)
    {
      //cabe no disco de maior tamanho livre
      //atualiza o disco 
      heap->vetor[0] -= i;
      // se o disco encheu -> remove o disco
      if(heap->vetor[0] == 0)
      {
        heap->vetor[0] = heap->vetor[heap->lotacao];
        heap->lotacao --;         
      }           
      //recalcula sua posição no heap
      heapify(heap);
      return 0;
    }    
  }
  //se o heap ta vazio ou não cabe - insere em um novo disco
  //adiciona um elemento no heap
  heap->lotacao++;
  heap->vetor[heap->lotacao] = TAM_DISCO - i;
  //atualiza o heap para cima 
  atualizaVetorParaCima(heap, heap->lotacao); 
  return 1;
}

static inline int esq(int indice)
{
  return 2*indice + 1;
}
static inline int dir(int indice)
{
  return 2*indice + 2;
}
static inline int pai(int indice)
{
  return (indice - 1)/2;
}

void atualizaVetorParaCima(heap* heap, int posicao)
{
  int aux=0;
  while(posicao >= 0)
  {
    //se o filho for maior que o pai -> troca
    if(heap->vetor[posicao] > heap->vetor[pai(posicao)])
    {
      //troca
      aux = heap->vetor[posicao];
      heap->vetor[posicao] = heap->vetor[pai(posicao)];
      heap->vetor[pai(posicao)] = aux;

      //atualiza a posição do testado 
      posicao = pai(posicao);
    }      
    else
    {
      return;
    }
  }  
}

void heapify(heap *heap)
{
  //comeca da raiz
  int posicao = 0;
  int aux = 0;
  while( 2*posicao+1 <= heap->lotacao)
  {
    if(heap->vetor[esq(posicao)] > heap->vetor[dir(posicao)]) 
    {
      //filho da esq maior 
      if(heap->vetor[esq(posicao)] > heap->vetor[posicao])
      {
        //troca 
        aux = heap->vetor[posicao];
        heap->vetor[posicao] = heap->vetor[esq(posicao)];
        heap->vetor[esq(posicao)] = aux;  

        //atualiza posição
        posicao = esq(posicao);
      }
      else
      {
        return;
      }
    }
    else if (2*posicao+2 <= heap->lotacao)
    {
      //filho da dir maior 
      if( heap->vetor[dir(posicao)] > heap->vetor[posicao])
      {
        //troca 
        aux = heap->vetor[posicao];
        heap->vetor[posicao] = heap->vetor[dir(posicao)];
        heap->vetor[dir(posicao)] = aux;  

        //atualiza posição
        posicao = dir(posicao);
      }
      else
      {
        return;
      }
    }
  }
}

void imprime(heap *heap)
{
  for(int i = 0; i<= heap->lotacao; i++)
    {
      printf("%ld ",heap->vetor[i]);
    }
  printf("\n");
}

void liberaHeap(heap *Heap)
{
  if(Heap != NULL)
  {
    if (Heap->vetor != NULL)
    {
      free(Heap->vetor);
    }
  }
  free(Heap);
}