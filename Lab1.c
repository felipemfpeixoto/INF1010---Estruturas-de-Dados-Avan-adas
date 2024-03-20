#include <stdio.h>
#include <stdlib.h>

// Felipe Peixoto e Ricardo Stuckert

struct itemList {
    int num;
    struct ItemList* prox;
};
typedef struct itemList ItemList;

ItemList* insereNaPilha();
void retiraDaPilha(ItemList* ultimoElem);
ItemList* insereNaFila();
void retiraDaFila(ItemList* primeiroFila);

int main(void) {
    ItemList* ultimoElemPilha = insereNaPilha();
    retiraDaPilha(ultimoElemPilha);
    ItemList* primeiroElemFila = insereNaFila();
    retiraDaFila(primeiroElemFila);
    return 0;
}

ItemList* insereNaPilha() {
    printf("Inserindo na pilha\n");
    ItemList* primeiroItem = (ItemList*)malloc(sizeof(ItemList));
    primeiroItem->prox = NULL;
    for (int i = 1; i <= 10; i++) {
        primeiroItem->num = i;
        printf("%d\n", primeiroItem->num);
        if (i != 10) {
            ItemList* proximo = (ItemList*)malloc(sizeof(ItemList));
            proximo->prox = primeiroItem;
            primeiroItem = proximo;
        }
    }
    printf("\n*** Itens inseridos com sucesso **\n\n\n");
    return primeiroItem;
}

void retiraDaPilha(ItemList* ultimoElem) {
    printf("Retirando os elementos da pilha\n");
    for (int i = 0; ultimoElem->prox != NULL; i++) {
        printf("%d\n", ultimoElem->num);
        ItemList* auxiliar = ultimoElem;
        ultimoElem = ultimoElem->prox;
        free(auxiliar);
    }
    printf("%d\n", ultimoElem->num);
    free(ultimoElem);
    printf("\n*** Itens retirado com sucesso **\n\n\n");
    return;
}

ItemList* insereNaFila() {
    printf("Inserindo na fila\n");
    ItemList* primeiroItem = (ItemList*)malloc(sizeof(ItemList));
    ItemList* auxiliar = primeiroItem;
    for (int i = 1; i <= 10; i++) {
        auxiliar->num = i;
        printf("%d\n", auxiliar->num);
        if (i != 10) {
            ItemList* proximo = (ItemList*)malloc(sizeof(ItemList));
            auxiliar->prox = proximo;
            auxiliar = proximo;
        }
        else {
            auxiliar->prox = NULL;
        }
    }
    printf("\n*** Itens inseridos com sucesso **\n\n\n");
    return primeiroItem;
}

void retiraDaFila(ItemList* primeiroFila) {
    printf("Retirando os elementos da fila\n");
    for (int i = 0; primeiroFila->prox != NULL; i++) {
        printf("%d\n", primeiroFila->num);
        ItemList* auxiliar = primeiroFila;
        primeiroFila = primeiroFila->prox;
        free(auxiliar);
    }
    printf("%d\n", primeiroFila->num);
    free(primeiroFila);
    printf("\n*** Itens retirado com sucesso **\n\n\n");
    return;
}