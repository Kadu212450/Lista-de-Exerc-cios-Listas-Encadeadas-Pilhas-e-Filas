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

void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}

int main() {
    No* raiz = NULL;

    inserir(&raiz, 10);
    inserir(&raiz, 5);
    inserir(&raiz, 15);
    inserir(&raiz, 2);
    inserir(&raiz, 7);

    printf("Busca em ordem: ");
    em_ordem(raiz); // Saída esperada: 2 5 7 10 15

    return 0;
}
