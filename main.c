#include <stdio.h>
#include "arvore.h"

int main(void) {
  int res_busca = -1;

  Arvore *arv = criarABB();

  inserirABB(arv, 17);
  inserirABB(arv, 11);
  inserirABB(arv, 31);
  inserirABB(arv, 7);
  inserirABB(arv, 15);
  inserirABB(arv, 20);
  inserirABB(arv, 43);
  inserirABB(arv, 5);
  inserirABB(arv, 9);
  inserirABB(arv, 12);
  inserirABB(arv, 16);
  inserirABB(arv, 18);
  inserirABB(arv, 23);
  inserirABB(arv, 37);
  inserirABB(arv, 114);

  imprimir_preordem(arv);
  //imprimir_emordem(arv);
  //imprimir_posordem(arv);

  res_busca = buscarABB(arv, 7);

  if (res_busca == NOT_FOUND) {
    printf("O valor não foi encontrado\n");
  } else {
    printf("Encontrei o valor %d\n", res_busca);
  }

  printf("Altura da árvore: %d\n", alturaABB(arv));

  removerABB(arv, 16);
  imprimir_preordem(arv);

  removerABB(arv, 31);
  imprimir_preordem(arv);

  imprimir_emordem(arv);

  destruirABB(arv);
  return 0;
}