#include "pilha.h"
#include <stdlib.h>

struct Pilha {
    int* elementos;
    int topo;
    int capacidade;
};

Pilha* criar_pilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->elementos = (int*)malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

void destruir_pilha(Pilha* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int pilha_cheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void push(Pilha* pilha, int elemento) {
    if (!pilha_cheia(pilha)) {
        pilha->elementos[++pilha->topo] = elemento;
    }
}

int pop(Pilha* pilha) {
    if (!pilha_vazia(pilha)) {
        return pilha->elementos[pilha->topo--];
    }
    return -1; // Valor de erro, se a pilha estiver vazia
}
