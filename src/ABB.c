#include "../include/ABB.h"

#define TAM_DISCO 1000000

struct arv
{
  long int info;
  arv *esq;
  arv *dir;  
};

arv* abb_cria()
{
  return NULL;
}

void abb_imprime(arv *a)
{
  if(a != NULL)
  {
    abb_imprime(a->esq);
    printf("%ld ",a->info);
    abb_imprime(a->dir);
  }
}

arv* insereArvore(arv *a,long int num,int *qtdDiscos)
{
  //busca na arvore se há espaço para num
  arv *aux = abb_busca(a,num);
  
  // se retornar null não há espaço para salvar os dados 
  if (aux == NULL)
  {
    (*qtdDiscos)++;
    //inserir na arvore
    a = abb_insere(a,TAM_DISCO - num);
  }
  else
  {
    //retornou o disco que cabe os dados -> aux
    long int resto = aux->info - num;
    //retira ele da arv
    a = abb_retira(a,aux->info);

    if(resto > 0)
    {
      //ainda sobrou espaço no disco, reinsere na arvore
      a = abb_insere(a,resto); 
    }
  }
  return a;
}

arv* abb_busca(arv *a, long int num)
{
  if (a == NULL)
  {
    return NULL;
  }
  else
  {
    if(num < a->info)
    {
      arv *aux = abb_busca(a->esq,num);
      
      if(aux == NULL)
      {
        //é o com menor espaço disponivel que cabe
        return a;            
      }
      else
      {
        //achou com o espaço exato
        return aux;
      }
    }
    else if (num > a->info)
    {
      return abb_busca(a->dir,num);
    }
    else
    {
      // caso perfeito -> é igual
      return a;
    }
  }
}

arv* abb_insere(arv *a,long int num)
{
  if(a==NULL)
  {
    a=(arv*)malloc(sizeof(arv));
    a->info=num;
    a->esq=NULL;
    a->dir=NULL;
  } 
  else
  {
    if(num < a->info)
    {
      a->esq = abb_insere(a->esq,num);
    }
    else
    {
      a->dir = abb_insere(a->dir,num);
    }
  }
  return a;
}

arv* abb_retira(arv *a, long int num)
{  
  if(a==NULL)
  {
    return NULL;
  }
  else if(num < a->info)
  {
    a->esq=abb_retira(a->esq,num);
  }
  else if(num > a->info)
  {
    a->dir = abb_retira(a->dir,num);
  }    
  else
  {
    //caso 1 : nó folha
    if(a->dir==NULL && a->esq==NULL)
    {
      free(a);
      return NULL;
    }
    else if(a->dir==NULL) //caso 2.1: nó com um filho a esq
    {      
      arv* aux=a;
      a=a->esq;
      free(aux);
    }
    else if(a->esq==NULL)  //caso 2: nó com um filho a dir
    {
      arv*aux=a;
      a=a->dir;
      free(aux);
    }
    else  //caso 3: nó raiz
    {
      arv *aux = a->esq;
      while(aux->dir!=NULL)
      {
        aux=aux->dir;
      }
      //trocar informações
      long int auxiliar = a->info;
      a->info = aux->info;
      aux->info=auxiliar;

      a->esq=abb_retira(a->esq,num);
    }
  }  
  return a;
}

arv* abb_libera(arv *a)
{
  if(a==NULL)
  {
    return NULL;
  }
  abb_libera(a->esq);
  abb_libera(a->dir);
  free(a);
  return NULL;  
}