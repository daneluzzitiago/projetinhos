#include <stdio.h>
#include <time.h>   //time
#include <stdlib.h> //rand e sradn

#define TAM 200000

// 20 Nem da pra notar, é muito rápido
// 2.000 Ainda é rápido 
// 20.000 mostra que funciona certinho o calculo
// 50.000 já leva um tempinho
// 200.000 já estoura

//Funções auxiliares

void exibeVetor(int *v)
{
  int i;
  for (i = 0; i < TAM; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void copiaVetor(int *origem, int *destino)
{
  int i;
  for (i = 0; i < TAM; i++)
  {
    destino[i] = origem[i];
  }
}

//Funções de ordenação

void bubbleSort(int *v)
{
  int i, j;
  int aux; //lógica de troca
  for (i = 0; i < TAM; i++)
  {
    //Menor vai para o começo
    for (j = TAM - 1; j > i; j--)
    {
      if (v[j] < v[j - 1])
      {
        aux = v[j];
        v[j] = v[j - 1];
        v[j - 1] = aux;
      }
    }
  }
}

void selectionSort(int *v)
{
  int i, j;
  int aux;
  int posMenor; //Armazena menor valor da iteração atual
  for (i = 0; i < TAM; i++)
  {
    posMenor = i; //Assume que já o menor valor;
    for (j = i + 1; j < TAM; j++)
    {
      if (v[j] < v[posMenor])
      {
        posMenor = j;
      }
    }
    aux = v[i];
    v[i] = v[posMenor];
    v[posMenor] = aux;
  }
}

void insertionSort(int *v)
{
  int i, j;
  int key;
  for (i = 1; i < TAM; i++)
  {
    key = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > key)
    {
      v[j + 1] = v[j];
      j--;
    }
    j++;
    v[j] = key;
  }
}

void valoresAleatorios(int *v)
{
  srand(time(NULL));
  int i;
  for (i = 0; i < TAM; i++)
  {
    v[i] = rand()%50;
  }
}

int main()
{
  int valores[TAM];
  int copia[TAM];

  clock_t inicio;
  clock_t fim;

  double total;

  valoresAleatorios(valores);
  copiaVetor(valores, copia);

  //Bubble sort
  // printf("Ordenação com Bubble sort:\nAntes: ");
  // exibeVetor(valores); // REMOVER NA ETAPA FINAL
  inicio = clock();
  bubbleSort(valores);
  fim = clock();

  total = (fim - inicio) / (double)CLOCKS_PER_SEC;

  printf("Tempo de execucao do Bubble sort: %lf\n", total);
  // printf("Depois: ");
  // exibeVetor(valores); // REMOVER NA ETAPA FINAL

  copiaVetor(copia, valores);

  //Selection sort
  // printf("Ordenação com Selection sort:\nAntes: ");
  // exibeVetor(valores);
  inicio = clock();
  selectionSort(valores);
  fim = clock();

  total = (fim - inicio) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execucao do Selection sort: %lf\n", total);
  // printf("Depois: ");
  // exibeVetor(valores);

  copiaVetor(copia, valores);

  //Insertion sort
  // printf("Ordenação com Insertion sort:\nAntes: ");
  // exibeVetor(valores);
  inicio = clock();
  insertionSort(valores);
  fim = clock();

  total = (fim - inicio) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execucao do Insertion sort: %lf\n", total);
  // printf("Depois: ");
  // exibeVetor(valores);

  return 0;
}