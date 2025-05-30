#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

int contar_nos(No *lista) {
    int contador = 0;
    while (lista) {
        contador++;
        lista = lista->prox;
    }
    return contador;
}

int main() {
    No *lista = NULL;
    
    No *n1 = (No*)malloc(sizeof(No));
    No *n2 = (No*)malloc(sizeof(No));
    
    n1->dado = 10; n1->prox = n2;
    n2->dado = 20; n2->prox = NULL;
    
    lista = n1;
    
    printf("Número de nós: %d\n", contar_nos(lista)); // Saída: 2
    
    free(n1);
    free(n2);

    return 0;
}
