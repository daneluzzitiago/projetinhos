#include <stdio.h>
#include "fila.h"

int main(){
  Fila fila1;
  iniciaFila(&fila1);
  exibe(&fila1);
  Pessoa p1 = "Jonas";
  entra(&fila1, p1);
  exibe(&fila1);
  Pessoa p2 = "Paula";
  Pessoa p3 = "Lila";
  entra(&fila1, p2);
  entra(&fila1, p3);
  exibe(&fila1);
  printf("Saiu da fila: %s\n", sai(&fila1));
  printf("Saiu da fila: %s\n", sai(&fila1));
  printf("Saiu da fila: %s\n", sai(&fila1));
  printf("Saiu da fila: %s\n", sai(&fila1));

  excluiFila(&fila1);
}