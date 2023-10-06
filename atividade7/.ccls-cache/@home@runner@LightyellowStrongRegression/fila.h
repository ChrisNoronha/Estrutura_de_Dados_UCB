#ifndef FILA_H
#define FILA_H

typedef struct Fila Fila;

Fila* criar_fila(int capacidade);
void destruir_fila(Fila* fila);
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
void enfileirar(Fila* fila, int elemento);
int desenfileirar(Fila* fila);

#endif
