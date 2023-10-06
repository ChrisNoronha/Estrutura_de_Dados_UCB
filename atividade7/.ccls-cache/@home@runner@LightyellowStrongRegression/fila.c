#include "fila.h"
#include <stdlib.h>

struct Fila {
    int* elementos;
    int frente;
    int fundo;
    int capacidade;
};

Fila* criar_fila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->elementos = (int*)malloc(sizeof(int) * capacidade);
    fila->frente = 0;
    fila->fundo = -1;
    fila->capacidade = capacidade;
    return fila;
}

void destruir_fila(Fila* fila) {
    free(fila->elementos);
    free(fila);
}

int fila_vazia(Fila* fila) {
    return fila->frente > fila->fundo;
}

int fila_cheia(Fila* fila) {
    return fila->fundo - fila->frente + 1 == fila->capacidade;
}

void enfileirar(Fila* fila, int elemento) {
    if (!fila_cheia(fila)) {
        fila->elementos[++fila->fundo] = elemento;
    }
}

int desenfileirar(Fila* fila) {
    if (!fila_vazia(fila)) {
        return fila->elementos[fila->frente++];
    }
    return -1; // Valor de erro, se a fila estiver vazia
}
