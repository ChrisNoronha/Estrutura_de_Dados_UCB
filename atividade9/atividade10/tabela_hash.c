#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

// Estrutura para os elementos da tabela hash
typedef struct HashNode {
    char* chave;
    char* dado;
    struct HashNode* proximo;
} HashNode;

// Tabela hash (array de ponteiros)
static HashNode* tabela[TABLE_SIZE];

// Função de hash simples
unsigned int hash(char* chave) {
    unsigned int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash = (hash * 31 + chave[i]) % TABLE_SIZE;
    }
    return hash;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    unsigned int index = hash(chave);
    HashNode* atual = tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    unsigned int index = hash(chave);
    HashNode* novo = (HashNode*)malloc(sizeof(HashNode));
    if (novo == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para novo nó.\n");
        exit(1);
    }
    novo->chave = strdup(chave);
    novo->dado = strdup(dado);
    novo->proximo = tabela[index];
    tabela[index] = novo;
}

int hash_table_contains(char* chave) {
    unsigned int index = hash(chave);
    HashNode* atual = tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1;  // A chave existe na tabela
        }
        atual = atual->proximo;
    }
    return 0;  // A chave não existe na tabela
}

void hash_table_remove(char* chave) {
    unsigned int index = hash(chave);
    HashNode* anterior = NULL;
    HashNode* atual = tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela[index] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual->chave);
            free(atual->dado);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

