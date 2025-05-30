#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct Pilha {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo < MAX - 1) {
        pilha->dados[++pilha->topo] = valor;
    }
}

int pop(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->dados[pilha->topo--];
    }
    return -1;
}

int avaliar_posfixa(char *expressao) {
    Pilha pilha;
    inicializar_pilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (isdigit(expressao[i])) {
            push(&pilha, expressao[i] - '0');
        } else {
            int op2 = pop(&pilha);
            int op1 = pop(&pilha);
            switch (expressao[i]) {
                case '+': push(&pilha, op1 + op2); break;
                case '-': push(&pilha, op1 - op2); break;
                case '*': push(&pilha, op1 * op2); break;
                case '/': push(&pilha, op1 / op2); break;
            }
        }
    }
    return pop(&pilha);
}

int main() {
    char expressao[] = "34+2*"; // Representa: (3 + 4) * 2
    printf("Resultado da expressão pós-fixa: %d\n", avaliar_posfixa(expressao)); // Saída esperada: 14

    return 0;
}
