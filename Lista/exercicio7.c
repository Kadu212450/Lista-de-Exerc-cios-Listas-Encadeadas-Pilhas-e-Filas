#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No* encontrar_meio(No *lista) {
    No *rapido = lista, *lento = lista;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
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

    imprimir_lista(lista);
    No *meio = encontrar_meio(lista);
    printf("Elemento do meio: %d\n", meio->dado); // Saída: 20

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
