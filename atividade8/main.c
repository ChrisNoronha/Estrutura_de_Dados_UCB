#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
    No* lista = criar_no('C', NULL); // Cria uma lista com um nó inicial 'C'

    No* n1 = criar_no('E', NULL);
    No* n2 = criar_no('A', NULL);
    No* n3 = criar_no('D', NULL);
    No* n4 = criar_no('B', NULL);
    No* n5 = criar_no('X', NULL);
    No* n6 = criar_no('Z', NULL);
    No* n7 = criar_no('U', NULL);

    inserir_no(lista, n1); // Insere 'E' na lista
    inserir_no(lista, n2); // Insere 'A' na lista
    inserir_no(lista, n3); // Insere 'D' na lista
    inserir_no(lista, n4); // Insere 'B' na lista
    inserir_no(lista, n5); // Insere 'X' na lista
    inserir_no(lista, n6); // Insere 'Z' na lista
    inserir_no(lista, n7); // Insere 'U' na lista

    printf("Lista Original: ");
    imprimir_lista(lista);
    printf("\nQuantidade de nós: %d\n", contar_nos(lista));

    No* copia_lista = copiar_lista(lista);
    printf("Cópia da Lista: ");
    imprimir_lista(copia_lista);
    printf("\n");

    concatenar_listas(lista, copia_lista);
    printf("Lista Concatenada: ");
    imprimir_lista(lista);
    printf("\n");

    char valor_busca = 'B';
    int existe = verificar_existencia(lista, valor_busca);
    printf("Existe '%c' na lista: %s\n", valor_busca, (existe == 1) ? "Sim" : "Não");

    valor_busca = 'C';
    int ocorrencias = verificar_ocorrencias(lista, valor_busca);
    printf("Ocorrências de '%c' na lista: %d\n", valor_busca, ocorrencias);

    printf("Lista Inversa: ");
    imprimir_inverso(lista);
    printf("\n");

    inserir_no_i(lista, 2, 'M'); // Insere 'M' na posição 2
    printf("Lista com nó inserido na posição 2: ");
    imprimir_lista(lista);
    printf("\n");

    // Remova ou libere a memória da lista e sua cópia conforme necessário.
    liberar_lista(lista);
    liberar_lista(copia
