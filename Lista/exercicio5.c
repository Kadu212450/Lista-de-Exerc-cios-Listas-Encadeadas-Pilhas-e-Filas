#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void remover_valor(No **lista, int valor) {
    No *temp = *lista, *anterior = NULL;

    while (temp != NULL && temp->dado == valor) {
        *lista = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) return;

    anterior->prox = temp->prox;
    free(temp);
}

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));

    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = n3;
    n3->dado = 30; n3->prox = NULL;

    lista = n1;

    printf("Lista antes da remoção:\n");
    imprimir_lista(lista);

    remover_valor(&lista, 20);

    printf("Lista após a remoção:\n");
    imprimir_lista(lista);

    free(n1);
    free(n3);

    return 0;
}
