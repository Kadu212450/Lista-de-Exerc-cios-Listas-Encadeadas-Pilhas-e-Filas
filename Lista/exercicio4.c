#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_posicao(No **lista, int valor, int posicao) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;

    if (posicao == 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No *temp = *lista;
    for (int i = 0; temp != NULL && i < posicao - 1; i++)
        temp = temp->prox;

    if (temp == NULL) return;

    novo->prox = temp->prox;
    temp->prox = novo;
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

    inserir_posicao(&lista, 10, 0);
    inserir_posicao(&lista, 20, 1);
    inserir_posicao(&lista, 15, 1); // Insere 15 na posição 1

    imprimir_lista(lista); // Saída esperada: 10 -> 15 -> 20 -> NULL

    return 0;
}
