#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Pilha {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, char c) {
    if (pilha->topo < MAX - 1) {
        pilha->dados[++pilha->topo] = c;
    }
}

char pop(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->dados[pilha->topo--];
    }
    return '\0';
}

char topo(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->dados[pilha->topo];
    }
    return '\0';
}

int precedencia(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    return 0;
}

void converter_para_posfixa(char *infixa, char *posfixa) {
    Pilha pilha;
    inicializar_pilha(&pilha);
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        if (isdigit(infixa[i])) {
            posfixa[j++] = infixa[i];
        } else if (infixa[i] == '(') {
            push(&pilha, infixa[i]);
        } else if (infixa[i] == ')') {
            while (topo(&pilha) != '(') {
                posfixa[j++] = pop(&pilha);
            }
            pop(&pilha); // Remove '(' da pilha
        } else {
            while (pilha.topo != -1 && precedencia(topo(&pilha)) >= precedencia(infixa[i])) {
                posfixa[j++] = pop(&pilha);
            }
            push(&pilha, infixa[i]);
        }
    }

    while (pilha.topo != -1) {
        posfixa[j++] = pop(&pilha);
    }
    posfixa[j] = '\0';
}

int main() {
    char infixa[] = "3+(4*5)-2";
    char posfixa[MAX];

    converter_para_posfixa(infixa, posfixa);
    printf("Expressão pós-fixa: %s\n", posfixa); // Saída esperada: 345*+2-

    return 0;
}
