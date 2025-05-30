#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

int buscar_elemento(No *lista, int valor) {
    while (lista) {
        if (lista->dado == valor) return 1;
        lista = lista->prox;
    }
    return 0;
}

int main() {
    No *lista = NULL;
    
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    
    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = NULL;
    
    lista = n1;

    printf("Elemento 10 existe? %d\n", buscar_elemento(lista, 10)); // Saída: 1 (True)
    printf("Elemento 30 existe? %d\n", buscar_elemento(lista, 30)); // Saída: 0 (False)

    free(n1);
    free(n2);

    return 0;
}
