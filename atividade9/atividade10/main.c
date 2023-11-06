#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("Valor associado à chave 'chave1': %s\n", hash_table_get("chave1"));

    if (hash_table_contains("chave2")) {
        printf("A chave 'chave2' existe na tabela.\n");
    } else {
        printf("A chave 'chave2' não existe na tabela.\n");
    }

    hash_table_remove("chave3");

    if (hash_table_contains("chave3")) {
        printf("A chave 'chave3' existe na tabela.\n");
    } else {
        printf("A chave 'chave3' não existe na tabela.\n");
    }

    return 0;
}
