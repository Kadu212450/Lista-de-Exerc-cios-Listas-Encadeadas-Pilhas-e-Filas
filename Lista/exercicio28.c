#include <stdio.h>

#define MAX 100

typedef struct FilaPrioridade {
    int dados[MAX];
    int tamanho;
} FilaPrioridade;

void inicializar_fila(FilaPrioridade *fila) {
    fila->tamanho = 0;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void enfileirar(FilaPrioridade *fila, int valor) {
    if (fila->tamanho == MAX) return;

    fila->dados[fila->tamanho] = valor;
    int i = fila->tamanho;

    while (i > 0 && fila->dados[(i - 1) / 2] > fila->dados[i]) {
        trocar(&fila->dados[i], &fila->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    fila->tamanho++;
}

int desenfileirar(FilaPrioridade *fila) {
    if (fila->tamanho == 0) return -1;

    int menor = fila->dados[0];
    fila->dados[0] = fila->dados[--fila->tamanho];

    int i = 0;
    while (2 * i + 1 < fila->tamanho) {
        int menor_filho = 2 * i + 1;
        if (menor_filho + 1 < fila->tamanho && fila->dados[menor_filho + 1] < fila->dados[menor_filho]) {
            menor_filho++;
        }

        if (fila->dados[i] < fila->dados[menor_filho]) break;

        trocar(&fila->dados[i], &fila->dados[menor_filho]);
        i = menor_filho;
    }

    return menor;
}

int main() {
    FilaPrioridade fila;
    inicializar_fila(&fila);

    enfileirar(&fila, 5);
    enfileirar(&fila, 3);
    enfileirar(&fila, 8);
    enfileirar(&fila, 2);

    printf("Elemento removido: %d\n", desenfileirar(&fila)); // Saída esperada: 2
    printf("Elemento removido: %d\n", desenfileirar(&fila)); // Saída esperada: 3

    return 0;
}
