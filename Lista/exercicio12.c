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

void inverter_string(char *str) {
    Pilha pilha;
    inicializar_pilha(&pilha);
    int tamanho = strlen(str);

    for (int i = 0; i < tamanho; i++) {
        push(&pilha, str[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        str[i] = pop(&pilha);
    }
}

int main() {
    char palavra[] = "hello";
    inverter_string(palavra);
    printf("String invertida: %s\n", palavra); // Saída: "olleh"

    return 0;
}
