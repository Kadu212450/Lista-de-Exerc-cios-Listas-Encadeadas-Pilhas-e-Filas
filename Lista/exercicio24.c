#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct Pilha {
    int dados[MAX];
    int minimos[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo == MAX - 1) return;

    pilha->dados[++pilha->topo] = valor;

    if (pilha->topo == 0) {
        pilha->minimos[pilha->topo] = valor;
    } else {
        pilha->minimos[pilha->topo] = (valor < pilha->minimos[pilha->topo - 1]) ? valor : pilha->minimos[pilha->topo - 1];
    }
}

int pop(Pilha *pilha) {
    if (pilha->topo == -1) return -1;
    return pilha->dados[pilha->topo--];
}

int obter_minimo(Pilha *pilha) {
    if (pilha->topo == -1) return INT_MAX;
    return pilha->minimos[pilha->topo];
}

int main() {
    Pilha pilha;
    inicializar_pilha(&pilha);

    push(&pilha, 3);
    push(&pilha, 5);
    printf("Mínimo atual: %d\n", obter_minimo(&pilha)); // Saída esperada: 3
    push(&pilha, 2);
    push(&pilha, 1);
    printf("Mínimo atual: %d\n", obter_minimo(&pilha)); // Saída esperada: 1
    pop(&pilha);
    printf("Mínimo após remoção: %d\n", obter_minimo(&pilha)); // Saída esperada: 2

    return 0;
}
