#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = valor;
    no->esq = no->dir = NULL;
    return no;
}

void inserir(No** raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = novo_no(valor);
        return;
    }

    if (valor < (*raiz)->dado)
        inserir(&(*raiz)->esq, valor);
    else
        inserir(&(*raiz)->dir, valor);
}

int buscar(No* raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    if (valor < raiz->dado) return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

int main() {
    No* raiz = NULL;

    inserir(&raiz, 10);
    inserir(&raiz, 5);
    inserir(&raiz, 15);
    inserir(&raiz, 2);
    inserir(&raiz, 7);

    printf("Elemento 7 está na árvore? %d\n", buscar(raiz, 7)); // Saída esperada: 1 (True)
    printf("Elemento 20 está na árvore? %d\n", buscar(raiz, 20)); // Saída esperada: 0 (False)

    return 0;
}
