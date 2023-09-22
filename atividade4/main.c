#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s [números]\n", argv[0]);
        return 1;
    }

    int num_args = argc - 1;
    int *numbers = (int *)malloc(num_args * sizeof(int));

    for (int i = 1; i <= num_args; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    bubbleSort(numbers, num_args);

    printf("Saída: ");
    for (int i = 0; i < num_args; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

    return 0;
}
