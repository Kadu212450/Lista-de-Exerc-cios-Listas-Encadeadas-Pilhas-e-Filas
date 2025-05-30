#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

int detectar_ciclo(No *lista) {
    No *rapido = lista, *lento = lista;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;

        if (lento == rapido) return 1; // Ciclo detectado
    }
    return 0; // Sem ciclo
}

int main() {
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));

    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = n3;
    n3->dado = 30; n3->prox = NULL;

    printf("A lista tem ciclo? %d\n", detectar_ciclo(n1)); // Saída esperada: 0 (Sem ciclo)

    // Criando um ciclo artificialmente
    n3->prox = n1;

    printf("A lista tem ciclo? %d\n", detectar_ciclo(n1)); // Saída esperada: 1 (Ciclo detectado)

    // **Importante**: Não podemos liberar memória se há um ciclo, pois geraria um loop infinito!

    return 0;
}
