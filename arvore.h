
#define NOT_FOUND -999999

typedef struct _no {
  struct _no *esq;
  struct _no *dir;
  int info;
} No;

typedef struct _arvore {
  No *raiz;
} Arvore;

Arvore *criarABB();

void inserirABB(Arvore *arv, int v);

void imprimir_preordem(Arvore *arv);
void imprimir_emordem(Arvore *arv);
void imprimir_posordem(Arvore *arv);

int buscarABB(Arvore *arv, int v);

int alturaABB(Arvore *arv);

void removerABB(Arvore *arv, int v);

void destruirABB(Arvore *arv);
