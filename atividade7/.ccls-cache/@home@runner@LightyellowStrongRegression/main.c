#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    // Caso de uso para pilha
    Pilha* pilha = criar_pilha(5);
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    printf("Elemento desempilhado: %d\n", pop(pilha)); // Deve imprimir 3
    destruir_pilha(pilha);

    // Caso de uso para fila
    Fila* fila = criar_fila(5);
    enfileirar(fila, 4);
    enfileirar(fila, 5);
    enfileirar(fila, 6);
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila)); // Deve imprimir 4
    destruir_fila(fila);

    return 0;
}
