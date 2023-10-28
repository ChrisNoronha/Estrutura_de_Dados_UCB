#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(char valor, No* proximo_no) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para novo nó.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void inserir_no(No* L, No* novo_no) {
    if (L == NULL) {
        fprintf(stderr, "Erro: Lista não inicializada.\n");
        exit(1);
    }

    novo_no->proximo_no = L->proximo_no;
    L->proximo_no = novo_no;
}

void imprimir_lista(No* L) {
    No* atual = L->proximo_no; // Começa a partir do primeiro elemento da lista.
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo_no;
    }
    printf("\n");
}

int contar_nos(No* L) {
    int count = 0;
    No* atual = L->proximo_no;
    while (atual != NULL) {
        count++;
        atual = atual->proximo_no;
    }
    return count;
}

No* copiar_lista(No* L) {
    No* nova_lista = criar_no('\0', NULL); // Cria um nó cabeça vazio.
    No* atual = L->proximo_no;
    No* nova_atual = nova_lista;
    while (atual != NULL) {
        nova_atual->proximo_no = criar_no(atual->valor, NULL);
        nova_atual =
