#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct nodo {
	int chave;
	struct nodo* esq;
	struct nodo* dir;
};
typedef struct nodo Nodo;

Nodo* insere(Nodo* p, int x) {
	Nodo* aux;
	if (p == NULL) {
		aux = (Nodo*)malloc(sizeof(Nodo));
		aux->chave = x;
		aux->esq = aux->dir = NULL;
		return aux;
	}
	if (p->chave > x)
		p->esq = insere(p->esq, x);
	else if (p->chave < x)
		p->dir = insere(p->dir, x);
	return p;
}

int e_abb(Nodo *no) {
    if (no == NULL) {
        return TRUE;
    }
    if (no->esq != NULL) {
        if (no->esq->chave >= no->chave) {
            return FALSE;
        }
        if (!e_abb(no->esq)) {
            return FALSE;
        }
    }
    if (no->dir != NULL) {
        if (no->dir->chave <= no->chave) {
            return FALSE;
        }
        if (!e_abb(no->dir)) {
            return FALSE;
        }
    }
    return TRUE;
}

void exibe_simetrica(Nodo* p) {
	if (p == NULL)
		printf("arvore nao foi criada\n");
	if (p->esq != NULL)
		exibe_simetrica(p->esq);
	printf("ptr_no=%p, chave=%d esq=%p dir=%p\n", p, p->chave, p->esq, p -> dir);
	if (p->dir != NULL)
		exibe_simetrica(p->dir);
}

int deletamin(Node* pt) {
  int min;
  Node* aux;
  if (pt->left == NULL) {
    min = pt->data;
    aux = pt;
    pt = pt->right;
    free(aux);
    return min;
  }
  return deletamin(pt->left);
}

void deleta(int x, Node* pt) {
  Node* aux;
  if (pt != NULL) {
    printf("deletando\n");
    if (x < pt->data) {
      deleta(x, pt->left);
    }
    else {
      if (x < pt->right->data)
        deleta(x, pt->right);
      else // ACHOU!!!
        if (pt->left == NULL) { // no com 1 filho a direita
          aux = pt;
          pt = pt->right;
          free(aux);
        }
        else if (pt->right == NULL) { // no com 1 filho a esquerda
            aux = pt;
          pt = pt->left;
          free(aux);
        }
        else // no com 2 filhos
          pt->data = deletamin(pt->right);
    }
  }
}

int main(void) {
    Nodo *raiz = NULL;
    // insere elementos na arvore
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 4);
    raiz = insere(raiz, 6);
    raiz = insere(raiz, 8);

    // exibe a arvore em ordem simetrica
    printf("Exibindo a arvore em ordem simetrica:\n");
    exibe_simetrica(raiz);
    // verifica se a arvore eh uma ABB
    if (e_abb(raiz)) {
        printf("A arvore eh uma ABB.\n");
    } else {
        printf("A arvore NAO eh uma ABB.\n");
    }

    deleta(raiz->dir->data, raiz);
    deleta(raiz->esq->data, raiz);

    return 0; 
}