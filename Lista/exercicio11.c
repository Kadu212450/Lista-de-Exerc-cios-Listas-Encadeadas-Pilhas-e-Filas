#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Pilha {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

void push(Pilha *pilha, char c) {
    if (pilha->topo == MAX - 1) return;
    pilha->dados[++pilha->topo] = c;
}

char pop(Pilha *pilha) {
    if (pilha->topo == -1) return '\0';
    return pilha->dados[pilha->topo--];
}

int verificar_balanceamento(const char *expressao) {
    Pilha pilha;
    inicializar_pilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {
            push(&pilha, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']') {
            char topo = pop(&pilha);
            if ((expressao[i] == ')' && topo != '(') ||
                (expressao[i] == '}' && topo != '{') ||
                (expressao[i] == ']' && topo != '[')) {
                return 0; // Desbalanceado
            }
        }
    }
    return pilha.topo == -1;
}

int main() {
    char expressao1[] = "({[]})";
    char expressao2[] = "({[}])";

    printf("Expressão 1 está balanceada? %d\n", verificar_balanceamento(expressao1)); // Saída: 1 (True)
    printf("Expressão 2 está balanceada? %d\n", verificar_balanceamento(expressao2)); // Saída: 0 (False)

    return 0;
}
