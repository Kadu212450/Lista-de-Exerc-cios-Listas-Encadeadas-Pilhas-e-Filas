#include <stdio.h>

#define MAX 100

typedef struct Fila {
    int dados[MAX];
    int frente, tras, tamanho;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

int esta_vazia(Fila *fila) {
    return fila->tamanho == 0;
}

int esta_cheia(Fila *fila) {
    return fila->tamanho == MAX;
}

void enfileirar(Fila *fila, int valor) {
    if (esta_cheia(fila)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    fila->tras = (fila->tras + 1) % MAX;
    fila->dados[fila->tras] = valor;
    fila->tamanho++;
}

int desenfileirar(Fila *fila) {
    if (esta_vazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = fila->dados[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;
    return valor;
}

int frente(Fila *fila) {
    if (esta_vazia(fila)) return -1;
    return fila->dados[fila->frente];
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
