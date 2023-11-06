#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    No* lista_nao_ordenada = criar_no(0.0, NULL);
    No* lista_ordenada = criar_no(0.0, NULL);
    char line[50]; // Buffer para ler cada linha do arquivo

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo '1kk_rand_float.csv'\n");
        return 1;
    }

    while (fgets(line, sizeof(line), arquivo)) {
        float numero;
        if (sscanf(line, "%f", &numero) == 1) {
            No* novo_no = criar_no(numero, NULL);
            inserir_no(lista_nao_ordenada, novo_no);
            lista_inserir_no_ordenado(lista_ordenada, novo_no);
        }
    }

    fclose(arquivo);

    printf("Lista Não Ordenada: ");
    imprimir_lista(lista_nao_ordenada);
    printf("Lista Ordenada: ");
    imprimir_lista(lista_ordenada);

    liberar_lista(lista_nao_ordenada);
    liberar_lista(lista_ordenada);

    return 0;
}
