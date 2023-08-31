#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para representar um ponto (x, y)
struct Ponto {
    double x;
    double y;
};

int main() {
    FILE *arquivo = fopen("C:\\users\\fnf4\\Documents\\EDD\\Estrutura_de_Dados_UCB\\Estrutura_de_Dados_UCB\\atividade3\\dados.csv", "r"); // Abre o arquivo "dados.csv" para leitura
    if (!arquivo) {
        perror("Error ao abrir o arquivo");
        return 1;
    }

    // Contar o número de linhas no arquivo
    int numLinhas = 0;
    char linha[1024]; // Tamanho máximo de uma linha no arquivo

    while (fgets(linha, sizeof(linha), arquivo)) {
        numLinhas++;
    }

    // Alocar dinamicamente um array de struct Ponto
    struct Ponto *pontos = (struct Ponto *)malloc(numLinhas * sizeof(struct Ponto));
    if (!pontos) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return 1;
    }

    // Voltar para o início do arquivo
    rewind(arquivo);

    // Ler os dados do arquivo e armazená-los no array
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Suponha que o arquivo CSV tenha duas colunas: x e y
        char *token = strtok(linha, ",");
        pontos[i].x = atof(token);
        token = strtok(NULL, ",");
        pontos[i].y = atof(token);
        i++;
    }

    fclose(arquivo);

    // Calcular a média de x e y
    double somaX = 0.0, somaY = 0.0;
    for (int j = 0; j < numLinhas; j++) {
        somaX += pontos[j].x;
        somaY += pontos[j].y;
    }

    double mediaX = somaX / numLinhas;
    double mediaY = somaY / numLinhas;

    // Calcular os coeficientes da regressão linear (a e b)
    double somaXY = 0.0, somaXQuadrado = 0.0;
    for (int j = 0; j < numLinhas; j++) {
        somaXY += (pontos[j].x - mediaX) * (pontos[j].y - mediaY);
        somaXQuadrado += (pontos[j].x - mediaX) * (pontos[j].x - mediaX);
    }

    double a = somaXY / somaXQuadrado;
    double b = mediaY - (a * mediaX);

    // Imprimir os resultados da regressão linear
    printf("Resultados da Regressao Linear:\n");
    printf("Equacao da Regressao Linear: y = %.2fx + %.2f\n", a, b);

    // Liberar a memória alocada
    free(pontos);

    return 0;
}
