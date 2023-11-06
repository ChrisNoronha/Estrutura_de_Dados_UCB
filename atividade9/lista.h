#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    float valor;
    struct No* proximo_no;
} No;

No* criar_no(float valor, No* proximo_no);
void inserir_no(No* L, No* novo_no);
void imprimir_lista(No* L);
int contar_nos(No* L);
No* copiar_lista(No* L);
void concatenar_listas(No* L, No* Lc);
void liberar_lista(No* L);
int verificar_existencia(No* L, float valor_busca);
int verificar_ocorrencias(No* L, float valor_busca);
void imprimir_inverso(No* L);
void inserir_no_i(No* L, int i, float valor);
void remover_no_i(No* L, int i);
void remover_nos(No* L, float valor_busca);
void lista_inserir_no_ordenado(No* L, No* no);

#endif
