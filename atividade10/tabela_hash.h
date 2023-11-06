#ifndef TABELA_HASH_H
#define TABELA_HASH_H

// Tamanho da tabela hash
#define TABLE_SIZE 100

void hash_table_init();
char* hash_table_get(char* chave);
void hash_table_put(char* chave, char* dado);
int hash_table_contains(char* chave);
void hash_table_remove(char* chave);

#endif
