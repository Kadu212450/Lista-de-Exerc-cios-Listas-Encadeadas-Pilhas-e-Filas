#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha->dados[pilha->topo--];
}

void imprimir_reverso(No *lista) {
    Pilha pilha;
    inicializar_pilha(&pilha);  // Inicializando a pilha corretamente

    while (lista) {
        push(&pilha, lista->dado);
        lista = lista->prox;
    }

    while (pilha.topo != -1) {
        printf("%d -> ", pop(&pilha));
    }
    printf("NULL\n");
}

int main() {
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    No *n3 = (No*)malloc(sizeof(No));

    if (!n1 || !n2 || !n3) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = n3;
    n3->dado = 30; n3->prox = NULL;

    printf("Lista original:\n");
    printf("10 -> 20 -> 30 -> NULL\n");

    printf("Lista invertida:\n");
    imprimir_reverso(n1);

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
