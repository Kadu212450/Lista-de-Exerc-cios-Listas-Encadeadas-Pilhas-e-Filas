#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Fila {
    No *frente, *tras;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}

int esta_vazia(Fila *fila) {
    return fila->frente == NULL;
}

void enfileirar(Fila *fila, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (esta_vazia(fila)) {
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->prox = novo;
        fila->tras = novo;
    }
}

int desenfileirar(Fila *fila) {
    if (esta_vazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    No *temp = fila->frente;
    int valor = temp->dado;
    fila->frente = temp->prox;
    free(temp);
    return valor;
}

int frente(Fila *fila) {
    if (esta_vazia(fila)) return -1;
    return fila->frente->dado;
}

int main() {
    Fila fila;
    inicializar_fila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    printf("Frente da fila: %d\n", frente(&fila)); // Saída esperada: 10
    printf("Removendo elemento: %d\n", desenfileirar(&fila)); // Saída esperada: 10
    printf("Nova frente: %d\n", frente(&fila)); // Saída esperada: 20

    return 0;
}
