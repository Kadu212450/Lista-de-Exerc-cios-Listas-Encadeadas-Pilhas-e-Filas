#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void remover_todas_ocorrencias(No **lista, int valor) {
    No *temp = *lista, *anterior = NULL;

    while (temp != NULL) {
        if (temp->dado == valor) {
            No *remover = temp;
            if (anterior == NULL) {
                *lista = temp->prox;
            } else {
                anterior->prox = temp->prox;
            }
            temp = temp->prox;
            free(remover);
        } else {
            anterior = temp;
            temp = temp->prox;
        }
    }
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

    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = n3;
    n3->dado = 10; n3->prox = n4;
    n4->dado = 30; n4->prox = NULL;

    printf("Lista antes da remoção:\n");
    imprimir_lista(n1);

    remover_todas_ocorrencias(&n1, 10);

    printf("Lista após a remoção:\n");
    imprimir_lista(n1);

    free(n2);
    free(n4);

    return 0;
}
