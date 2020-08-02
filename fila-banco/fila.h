#include <stdio.h>
#include <stdlib.h>

typedef char *Pessoa;

typedef struct No
{
  Pessoa pessoa;
  struct No *prox;
} No;

typedef struct Fila
{
  int elementos;
  No *inicio;
  No *fim;
} Fila;

// CRUD

void iniciaFila(Fila *f)
{
  f->elementos = 0;
  f->inicio = NULL;
  f->fim = NULL;
}

Pessoa sai(Fila *f)
{
  if (f->inicio == NULL)
  {
    return NULL;
  }
  Pessoa primeira = f->inicio->pessoa;
  No *aux = f->inicio;
  f->inicio = f->inicio->prox;
  free(aux);
  f->elementos--;
  return primeira;
}

void entra(Fila *f, Pessoa p)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->pessoa = p;
  novo->prox = NULL;
  if (f->elementos == 0)
  {
    f->inicio = novo;
    f->fim = novo;
  }
  else
  {
    f->fim->prox = novo;
    f->fim = novo;
  }
  f->elementos++;
}

void excluiFila(Fila *f)
{
  No *aux = f->inicio;
  No *temp;
  while (aux)
  {
    temp = aux;
    aux = aux->prox;
    free(temp);
  }
}

// Auxiliares

void exibe(Fila *f)
{
  if (f->elementos == 0)
  {
    printf("Fila vazia.\n");
    return;
  }
  No *aux = f->inicio;
  while (aux != NULL)
  {
    printf("%s ", aux->pessoa);
    aux = aux->prox;
  }
  printf("\n");
}