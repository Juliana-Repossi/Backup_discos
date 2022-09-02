#include "../include/worstfit.h"

int Worstfit(char *arquivo)
{
  FILE *arq = fopen(arquivo,"r");

  if(arq ==  NULL)
  {
    printf("Falha na abertura do arquivo: %s",arquivo);
    exit(2);
  }
  
  int tam=0;
  //le a quantidade de dados que o arquivo tem 
  fscanf(arq,"%d\n",&tam);

  //ainda não sei se o mais eficiente é alocar isso tudo
  //aloca um heap do tamanho passado
  heap* heap = alocaHeap(tam);

  long int num;
  int qtdDiscos = 0;
  //float soma = 0;
  
  while(tam != 0)
  {
    fscanf(arq,"%ld\n",&num);
    //soma = soma + num;
    //inserir o arquivo no disco de acordo com as especificações
    qtdDiscos += insereHeap(heap,num);
    
    tam --;
  }
  //printf("\n limite inferior : %f\n",soma/1000000);
  //libera a memoria e fecha os arquivos
  liberaHeap(heap);
  fclose(arq);
  
  return qtdDiscos;
}

static int comparaInteiros(const void *a, const void *b)
{
  return -((*(long int*)a) - (*(long int*)b));  
}

int Worstfit_decrescente(char *arquivo)
{
  FILE *arq = fopen(arquivo,"r");

  if(arq ==  NULL)
  {
    printf("Falha na abertura do arquivo: %s",arquivo);
    exit(2);
  }
  int tam=0;
  //le a quantidade de dados que o arquivo tem 
  fscanf(arq,"%d\n",&tam);

  long int *vetor = (long int*)malloc(tam*sizeof(long int));
  long int num;
  for(int i=0; i<tam;i++)
  {
    fscanf(arq,"%ld\n",&num);
    vetor[i] = num;
  }

  //ordenar a entrada
  qsort(vetor,tam,sizeof(long int),comparaInteiros);
  
  //ainda não sei se o mais eficiente é alocar isso tudo
  //aloca um heap do tamanho passado
  heap* heap = alocaHeap(tam);

  int qtdDiscos = 0;
  
  for(int i=0; i<tam; i++)
  {
    //inserir o arquivo no disco de acordo com as especificações
    qtdDiscos += insereHeap(heap,vetor[i]);

  }
  //libera a memoria e fecha os arquivos
  liberaHeap(heap);
  fclose(arq);
  free(vetor);
  
  return qtdDiscos;
}
