#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inverter_lista(No **lista) {
    No *anterior = NULL, *atual = *lista, *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }
    *lista = anterior;
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

    printf("Lista antes da inversão:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("Lista após a inversão:\n");
    imprimir_lista(lista);

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
