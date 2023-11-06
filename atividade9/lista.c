#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(float valor, No* proximo_no) {
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
        printf("%.2f ", atual->valor);
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
    No* nova_lista = criar_no(0.0, NULL); // Cria um nó cabeça vazio.
    No* atual = L->proximo_no;
    No* nova_atual = nova_lista;
    while (atual != NULL) {
        nova_atual->proximo_no = criar_no(atual->valor, NULL);
        nova_atual = nova_atual->proximo_no;
        atual = atual->proximo_no;
    }
    return nova_lista;
}

void concatenar_listas(No* L, No* Lc) {
    No* atual = L->proximo_no;
    while (atual->proximo_no != NULL) {
        atual = atual->proximo_no;
    }
    atual->proximo_no = Lc->proximo_no;
    free(Lc); // Liberar o nó cabeça da lista concatenada
}

void liberar_lista(No* L) {
    No* atual = L->proximo_no;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo_no;
        free(temp);
    }
    free(L);
}

int verificar_existencia(No* L, float valor_busca) {
    No* atual = L->proximo_no;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo_no;
    }
    return 0;
}

int verificar_ocorrencias(No* L, float valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo_no;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo_no;
    }
    return ocorrencias;
}

void imprimir_inverso(No* L) {
    if (L->proximo_no == NULL) {
        return; // Lista vazia
    }

    No* atual = L->proximo_no;
    No* proximo = atual->proximo_no;
    L->proximo_no = NULL; // Inicializa a lista inversa com NULL

    while (atual != NULL) {
        proximo = atual->proximo_no;
        atual->proximo_no = L->proximo_no; // Insere na frente
        L->proximo_no = atual;
        atual = proximo;
    }

    imprimir_lista(L); // Imprime a lista inversa
}

void lista_inserir_no_ordenado(No* L, No* no) {
    if (L == NULL) {
        fprintf(stderr, "Erro: Lista não inicializada.\n");
        exit(1);
    }

    No* atual = L;
    while (atual->proximo_no != NULL && atual->proximo_no->valor < no->valor) {
        atual = atual->proximo_no;
    }

    no->proximo_no = atual->proximo_no;
    atual->proximo_no = no;
}

