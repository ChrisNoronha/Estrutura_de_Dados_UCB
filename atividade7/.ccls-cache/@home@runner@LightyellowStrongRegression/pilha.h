#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha Pilha;

Pilha* criar_pilha(int capacidade);
void destruir_pilha(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
int pilha_cheia(Pilha* pilha);
void push(Pilha* pilha, int elemento);
int pop(Pilha* pilha);

#endif
