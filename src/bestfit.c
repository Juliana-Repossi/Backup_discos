#include "../include/bestfit.h"

int Bestfit(char *arquivo)
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

  //aloca estrutura vazia
  arv* arvore = abb_cria();

  long int num;
  int qtdDiscos = 0;
  
  while(tam != 0)
  {
    fscanf(arq,"%ld\n",&num);
    //inserir o arquivo no disco de acordo com as especificações
    arvore = insereArvore(arvore,num,&qtdDiscos);
    
    tam --;
  }
  
  //libera a memoria e fecha os arquivos
  arvore = abb_libera(arvore);
  fclose(arq);
  
  return qtdDiscos;
}

static int comparaInteiros(const void *a, const void *b)
{
  return -((*(long int*)a) - (*(long int*)b));  
}

int Bestfit_decrescente(char *arquivo)
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
    
  //aloca estrutura
  arv* arvore = abb_cria();

  int qtdDiscos = 0;
  
  for(int i=0; i<tam; i++)
  {
    //inserir o arquivo no disco de acordo com as especificações
    arvore = insereArvore(arvore,vetor[i],&qtdDiscos);

  }
  //libera a memoria e fecha os arquivos
  arvore = abb_libera(arvore);
  fclose(arq);
  free(vetor);
  
  return qtdDiscos;
}