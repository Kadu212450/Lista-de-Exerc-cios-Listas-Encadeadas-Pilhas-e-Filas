#include <stdio.h>

#define MAX 100

typedef struct DuasPilhas {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilhas;

void inicializar_pilhas(DuasPilhas *pilha) {
    pilha->topo1 = -1;
    pilha->topo2 = MAX;
}

void push1(DuasPilhas *pilha, int valor) {
    if (pilha->topo1 < pilha->topo2 - 1) {
        pilha->dados[++pilha->topo1] = valor;
    } else {
        printf("Erro: Pilhas cheias!\n");
    }
}

void push2(DuasPilhas *pilha, int valor) {
    if (pilha->topo1 < pilha->topo2 - 1) {
        pilha->dados[--pilha->topo2] = valor;
    } else {
        printf("Erro: Pilhas cheias!\n");
    }
}

int pop1(DuasPilhas *pilha) {
    if (pilha->topo1 >= 0) {
        return pilha->dados[pilha->topo1--];
    }
    printf("Erro: Pilha 1 vazia!\n");
    return -1;
}

int pop2(DuasPilhas *pilha) {
    if (pilha->topo2 < MAX) {
        return pilha->dados[pilha->topo2++];
    }
    printf("Erro: Pilha 2 vazia!\n");
    return -1;
}

int main() {
    DuasPilhas pilha;
    inicializar_pilhas(&pilha);

    push1(&pilha, 10);
    push1(&pilha, 20);
    push2(&pilha, 30);
    push2(&pilha, 40);

    printf("Pilha 1 pop: %d\n", pop1(&pilha)); // Saída esperada: 20
    printf("Pilha 2 pop: %d\n", pop2(&pilha)); // Saída esperada: 40

    return 0;
}
