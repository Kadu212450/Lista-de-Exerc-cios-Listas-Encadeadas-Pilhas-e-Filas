#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *temp = *lista;
        while (temp->prox) temp = temp->prox;
        temp->prox = novo;
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
    No *lista = NULL;
    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    imprimir_lista(lista); // Saída: 5 -> 10 -> NULL
    return 0;
}
