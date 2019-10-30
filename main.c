#include <stdio.h>
#include <stdlib.h>
#define ALTURA 100

struct NoArvore //Nó da arvore
  { 
  char chave;  //chave
  unsigned int frequencia; //frequencia da chave
  struct NoArvore *dir, *esq; //filhos da esquerda e direita do nó
  };
