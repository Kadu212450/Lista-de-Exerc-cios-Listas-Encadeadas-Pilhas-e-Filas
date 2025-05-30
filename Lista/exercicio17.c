#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado[10];
    struct No *prox;
} No;

typedef struct Fila {
    No *frente, *tras;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}

void enfileirar(Fila *fila, char *valor) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->dado, valor);
    novo->prox = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->prox = novo;
        fila->tras = novo;
    }
}

char* desenfileirar(Fila *fila) {
    if (fila->frente == NULL) return NULL;

    No *temp = fila->frente;
    char *valor = temp->dado;
    fila->frente = temp->prox;

    if (fila->frente == NULL) fila->tras = NULL;

    free(temp);
    return valor;
}

void gerar_binarios(int n) {
    Fila fila;
    inicializar_fila(&fila);

    enfileirar(&fila, "1");

    for (int i = 0; i < n; i++) {
        char *bin = desenfileirar(&fila);
        printf("%s ", bin);

        char bin1[10], bin2[10];
        sprintf(bin1, "%s0", bin);
        sprintf(bin2, "%s1", bin);

        enfileirar(&fila, bin1);
        enfileirar(&fila, bin2);
    }

    printf("\n");
}

int main() {
    int N = 5;
    gerar_binarios(N); // Saída esperada: 1 10 11 100 101

    return 0;
}
