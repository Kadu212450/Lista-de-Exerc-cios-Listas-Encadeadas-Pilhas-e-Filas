#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No* unir_listas_ordenadas(No *lista1, No *lista2) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    if (lista1->dado < lista2->dado) {
        lista1->prox = unir_listas_ordenadas(lista1->prox, lista2);
        return lista1;
    } else {
        lista2->prox = unir_listas_ordenadas(lista1, lista2->prox);
        return lista2;
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
    No *l1_n1 = (No*)malloc(sizeof(No));
    No *l1_n2 = (No*)malloc(sizeof(No));
    No *l1_n3 = (No*)malloc(sizeof(No));

    l1_n1->dado = 1; l1_n1->prox = l1_n2;
    l1_n2->dado = 3; l1_n2->prox = l1_n3;
    l1_n3->dado = 5; l1_n3->prox = NULL;

    No *l2_n1 = (No*)malloc(sizeof(No));
    No *l2_n2 = (No*)malloc(sizeof(No));
    No *l2_n3 = (No*)malloc(sizeof(No));

    l2_n1->dado = 2; l2_n1->prox = l2_n2;
    l2_n2->dado = 4; l2_n2->prox = l2_n3;
    l2_n3->dado = 6; l2_n3->prox = NULL;

    printf("Lista 1:\n");
    imprimir_lista(l1_n1);
    
    printf("Lista 2:\n");
    imprimir_lista(l2_n1);

    No *lista_unida = unir_listas_ordenadas(l1_n1, l2_n1);
    printf("Lista unida:\n");
    imprimir_lista(lista_unida);

    return 0;
}
