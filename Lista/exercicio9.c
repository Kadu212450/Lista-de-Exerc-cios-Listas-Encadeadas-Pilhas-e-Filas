#include <stdio.h>

#define MAX 100

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

int esta_vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha *pilha) {
    if (esta_vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha->dados[pilha->topo--];
}

int topo(Pilha *pilha) {
    if (esta_vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha->dados[pilha->topo];
}

int main() {
    Pilha pilha;
    inicializar_pilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    
    printf("Topo da pilha: %d\n", topo(&pilha)); // Saída esperada: 30
    printf("Removendo elemento: %d\n", pop(&pilha)); // Saída esperada: 30
    printf("Novo topo: %d\n", topo(&pilha)); // Saída esperada: 20

    return 0;
}
