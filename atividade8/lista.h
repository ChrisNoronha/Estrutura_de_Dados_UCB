#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No* proximo_no;
} No;

No* criar_no(char valor, No* proximo_no);
void inserir_no(No* L, No* novo_no);
void imprimir_lista(No* L);
int contar_nos(No* L);
No* copiar_lista(No* L);
void concatenar_listas(No* L, No* Lc);
void liberar_lista(No* L);
int verificar_existencia(No* L, char valor_busca);
int verificar_ocorrencias(No* L, char valor_busca);
void imprimir_inverso(No* L);
void inserir_no_i(No* L, int i, char valor);
void remover_no_i(No* L, int i);
void remover_nos(No* L, char valor_busca);

#endif
