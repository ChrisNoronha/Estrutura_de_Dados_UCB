#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char *arr[], int n) {
    int i, j;
    char *temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_de_entrada\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char *words[100];  // Assumindo no máximo 100 palavras
    int numWords = 0;
    char word[100];

    // Ler palavras do arquivo de entrada
    while (fscanf(inputFile, "%s", word) != EOF) {
        words[numWords] = strdup(word);
        numWords++;
    }

    // Ordenar as palavras
    bubbleSort(words, numWords);

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);  // Liberar memória alocada
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Palavras ordenadas em '%s'\n", outputFileName);

    return 0;
}
