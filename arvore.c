#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arvore *criarABB() {
  Arvore *arv = malloc(sizeof(Arvore));

  arv->raiz = NULL;

  return arv;
}

No * inserir_subarvore(No *noRaiz, int v) {
  // encontrei a posição em que v deve ser inserido
  // criterio de parada da funcao recursiva
  if (noRaiz == NULL) {
    No *no = malloc(sizeof(No));

    no->esq = no->dir = NULL;
    no->info = v;

    return no;
  }

  if (v <= noRaiz->info) {
    noRaiz->esq = inserir_subarvore(noRaiz->esq, v);
  } else {
    noRaiz->dir = inserir_subarvore(noRaiz->dir, v);
  }

  return noRaiz;
}

void inserirABB(Arvore *arv, int v) {
  arv->raiz = inserir_subarvore(arv->raiz, v);
}

void imp_no_preordem(No *noRaiz) {
  // R E D

  if (noRaiz == NULL) {
    return;
  }

  // raiz
  printf(" %d ", noRaiz->info);

  // SAE
  imp_no_preordem(noRaiz->esq);

  // SAD
  imp_no_preordem(noRaiz->dir);
}

void imprimir_preordem(Arvore *arv) {
  printf(" Pré-ordem: [ ");
  imp_no_preordem(arv->raiz);
  printf(" ]\n");
}

void imp_no_emordem(No *noRaiz) {
  // E R D

  if (noRaiz == NULL) {
    return;
  }

  // SAE
  imp_no_emordem(noRaiz->esq);

  // raiz
  printf(" %d ", noRaiz->info);

  // SAD
  imp_no_emordem(noRaiz->dir);
}

void imprimir_emordem(Arvore *arv) {
  printf(" Em ordem:  [ ");
  imp_no_emordem(arv->raiz);
  printf(" ]\n");
}

void imp_no_posordem(No *noRaiz) {
  // E D R

  if (noRaiz == NULL) {
    return;
  }

  // SAE
  imp_no_posordem(noRaiz->esq);

  // SAD
  imp_no_posordem(noRaiz->dir);

  // raiz
  printf(" %d ", noRaiz->info);
}

void imprimir_posordem(Arvore *arv) {
  printf(" Pós-ordem: [ ");
  imp_no_posordem(arv->raiz);
  printf(" ]\n");
}

int buscar_no_subarvore(No *noRaiz, int v) {
  // passei pela última folha e não encontrei o elemento
  if (noRaiz == NULL) {
    return NOT_FOUND;
  }

  // encontrei o elemento que eu procurava
  if (noRaiz->info == v) {
    return v;
  }

  // se eu não encontrei, compare para saber para qual sub-árvore ir

  // procure o elemento na subarvore esquerda
  if (v < noRaiz->info) {
    return buscar_no_subarvore(noRaiz->esq, v);
  } else {
    return buscar_no_subarvore(noRaiz->dir, v);
  }

}

int buscarABB(Arvore *arv, int v) {
  return buscar_no_subarvore(arv->raiz, v);
}

int altura_no_subarvore(No *noRaiz, int altura) {
  int alturaEsq, alturaDir;

  if (noRaiz == NULL) {
    return altura-1;
  }

  alturaEsq = altura_no_subarvore(noRaiz->esq, altura+1);
  alturaDir = altura_no_subarvore(noRaiz->dir, altura+1);

  if (alturaEsq >= alturaDir) {
    return alturaEsq;
  } else {
    return alturaDir;
  }
}

int alturaABB(Arvore *arv) {
  if (arv->raiz == NULL) {
    return -1;
  }

  return altura_no_subarvore(arv->raiz, 0);
}

No * max_subarvore (No *noRaiz) {
  if (noRaiz == NULL) {
    return noRaiz;
  }

  // se o nó não tiver um filho direito, significa que eu encontrei o nó mais à direita
  if (noRaiz->dir == NULL) {
    return noRaiz;
  }

  return max_subarvore(noRaiz->dir);
}

No * remover_subarvore(No *noRaiz, int v) {
  if (noRaiz == NULL) {
    return noRaiz;
  }

  // se v é menor que o valor da raiz, continua a busca na SAE
  if (v < noRaiz->info) {
    noRaiz->esq = remover_subarvore(noRaiz->esq, v);

  // se v for maior que o valor da raiz, continua a busca na SAD
  } else if (v > noRaiz->info) {
    noRaiz->dir = remover_subarvore(noRaiz->dir, v);

  // se v for igual ao elemento raiz, eu encontrei o nó e preciso removê-lo
  } else {
    /*
     * Os próximos dois casos, contemplam sub-árvores que
     * só tenham um dos dois filhos.
     */
    // se eu não tiver um filho esquerdo...
    if (noRaiz->esq == NULL) {
      No *filhoDir = noRaiz->dir;
      free(noRaiz);

      // ... retorna o meu filho direito como a nova raiz da árvore
      return filhoDir;
    
    // caso eu tenha um filho esquerdo, mas não tenha um filho direito...
    } else if (noRaiz->dir == NULL) {
      No *filhoEsq = noRaiz->esq;
      free(noRaiz);

      // ... retorna o meu filho esquerdo como a nova raiz da árvore
      return filhoEsq;

    // o nó raiz tem os dois filhos (esquerdo e direito)
    } else {
      // encontra o maior valor da SAE
      No *maxSAE = max_subarvore(noRaiz->esq);

      noRaiz->info = maxSAE->info;

      noRaiz->esq = remover_subarvore(noRaiz->esq, maxSAE->info);
    }
  }

  return noRaiz;
}

void removerABB(Arvore *arv, int v) {
  arv->raiz = remover_subarvore(arv->raiz, v);  
}

void destruir_subarvore(No *noRaiz) {
  if (noRaiz == NULL) {
    return;
  }

  // destroi SAE
  destruir_subarvore(noRaiz->esq);

  // destroi SAD
  destruir_subarvore(noRaiz->dir);

  // destroi raiz
  free(noRaiz);
}

void destruirABB(Arvore *arv) {
  destruir_subarvore(arv->raiz);

  free(arv);
}