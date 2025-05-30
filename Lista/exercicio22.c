#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No* encontrar_intersecao(No *lista1, No *lista2) {
    No *ptr1 = lista1, *ptr2 = lista2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? lista2 : ptr1->prox;
        ptr2 = (ptr2 == NULL) ? lista1 : ptr2->prox;
    }

    return ptr1;
}

int main() {
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));
    No *n4 = (No*)malloc(sizeof(No));

    n1->dado = 1; n1->prox = n2;
    n2->dado = 2; n2->prox = n3;
    n3->dado = 3; n3->prox = n4;
    n4->dado = 4; n4->prox = NULL;

    No *m1 = (No*)malloc(sizeof(No));
    No *m2 = (No*)malloc(sizeof(No));

    m1->dado = 10; m1->prox = m2;
    m2->dado = 20; m2->prox = n3; // Interseção ocorre em "n3"

    No *intersecao = encontrar_intersecao(n1, m1);
    if (intersecao) {
        printf("Interseção encontrada no nó com valor: %d\n", intersecao->dado);
    } else {
        printf("Nenhuma interseção encontrada.\n");
    }

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(m1);
    free(m2);

    return 0;
}



