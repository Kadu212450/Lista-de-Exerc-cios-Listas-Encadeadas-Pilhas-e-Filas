#include <stdio.h>

#define MAX 100

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

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

int topo(Pilha *pilha) {
    if (pilha->topo == -1) return -1;
    return pilha->dados[pilha->topo];
}

void ordenar_pilha(Pilha *pilha) {
    Pilha aux;
    inicializar_pilha(&aux);

    while (pilha->topo != -1) {
        int temp = pop(pilha);
        while (aux.topo != -1 && topo(&aux) > temp) {
            push(pilha, pop(&aux));
        }
        push(&aux, temp);
    }

    while (aux.topo != -1) {
        push(pilha, pop(&aux));
    }
}

int main() {
    Pilha pilha;
    inicializar_pilha(&pilha);

    push(&pilha, 3);
    push(&pilha, 1);
    push(&pilha, 4);
    push(&pilha, 2);

    ordenar_pilha(&pilha);

    printf("Pilha ordenada: ");
    while (pilha.topo != -1) {
        printf("%d ", pop(&pilha));
    }
    printf("\n");

    return 0;
}
