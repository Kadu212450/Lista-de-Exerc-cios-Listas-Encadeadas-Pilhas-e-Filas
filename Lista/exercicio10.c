#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void push(Pilha *pilha, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    No *temp = pilha->topo;
    int valor = temp->dado;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}

int topo(Pilha *pilha) {
    if (pilha->topo == NULL) return -1;
    return pilha->topo->dado;
}

int main() {
    Pilha pilha;
    inicializar_pilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    printf("Topo da pilha: %d\n", topo(&pilha)); // Saída: 30
    printf("Removendo elemento: %d\n", pop(&pilha)); // Saída: 30
    printf("Novo topo: %d\n", topo(&pilha)); // Saída: 20

    return 0;
}
