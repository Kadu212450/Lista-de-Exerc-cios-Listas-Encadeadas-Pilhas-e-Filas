#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void rotacionar_lista(No **lista, int k) {
    if (*lista == NULL || k == 0) return;

    No *atual = *lista;
    int tamanho = 1;
    
    while (atual->prox) {
        atual = atual->prox;
        tamanho++;
    }

    atual->prox = *lista; // Criando uma ligação circular
    k = k % tamanho;
    
    for (int i = 0; i < tamanho - k; i++) {
        atual = atual->prox;
    }

    *lista = atual->prox;
    atual->prox = NULL;
}

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

int main() {
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    No *n4 = (No*)malloc(sizeof(No));
    No *n5 = (No*)malloc(sizeof(No));

    n1->dado = 1; n1->prox = n2;
    n2->dado = 2; n2->prox = n3;
    n3->dado = 3; n3->prox = n4;
    n4->dado = 4; n4->prox = n5;
    n5->dado = 5; n5->prox = NULL;

    printf("Lista original:\n");
    imprimir_lista(n1);

    rotacionar_lista(&n1, 2);

    printf("Lista rotacionada em 2 posições:\n");
    imprimir_lista(n1);

    return 0;
}
