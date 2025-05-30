#include <stdio.h>
#include <string.h>

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

int eh_palindromo(char *str) {
    Pilha pilha;
    inicializar_pilha(&pilha);
    int tamanho = strlen(str);

    for (int i = 0; i < tamanho; i++) {
        push(&pilha, str[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        if (str[i] != pop(&pilha)) return 0;
    }

    return 1;
}

int main() {
    char palavra1[] = "radar";
    char palavra2[] = "hello";

    printf("Palavra 'radar' é palíndromo? %d\n", eh_palindromo(palavra1)); // Sa