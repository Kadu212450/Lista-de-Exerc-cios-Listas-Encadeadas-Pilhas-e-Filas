#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Fila {
    int dados[MAX];
    int frente, tras, tamanho;
} Fila;

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_fila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

void enfileirar(Fila *fila, int valor) {
    if (fila->tamanho == MAX) return;
    fila->tras = (fila->tras + 1) % MAX;
    fila->dados[fila->tras] = valor;
    fila->tamanho++;
}

int desenfileirar(Fila *fila) {
    if (fila->tamanho == 0) return -1;
    int valor = fila->dados[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;
    return valor;
}

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo == MAX - 1) return;
    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha *pilha) {
    if (pilha->topo == -1) return -1;
    return pilha->dados[pilha->topo--];
}

void inverter_primeiros_k(Fila *fila, int k) {
    Pilha pilha;
    inicializar_pilha(&pilha);

    for (int i = 0; i < k; i++) {
        push(&pilha, desenfileirar(fila));
    }

    while (pilha.topo != -1) {
        enfileirar(fila, pop(&pilha));
    }

    for (int i = 0; i < fila->tamanho - k; i++) {
        enfileirar(fila, desenfileirar(fila));
    }
}

void imprimir_fila(Fila *fila) {
    int i, index = fila->frente;
    for (i = 0; i < fila->tamanho; i++) {
        printf("%d ", fila->dados[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializar_fila(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    enfileirar(&fila, 4);
    enfileirar(&fila, 5);

    printf("Fila original: ");
    imprimir_fila(&fila);

    inverter_primeiros_k(&fila, 3);

    printf("Fila após inverter os primeiros 3 elementos: ");
    imprimir_fila(&fila); // Saída esperada: 3 2 1 4 5

    return 0;
}
