#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para trocar os valores de duas variáveis inteiras
void troca(int* xp, int* yp) {
    int temp = *xp;   // Armazena o valor apontado por xp em uma variável temporária
    *xp = *yp;        // Atribui o valor apontado por yp para o endereço apontado por xp
    *yp = temp;       // Atribui o valor armazenado em temp para o endereço apontado por yp
}

// Função que implementa o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;  // Variável para verificar se ocorreu alguma troca na passagem atual

    // Loop externo: controla o número de passagens pelo array
    for (i = 0; i < n - 1; i++) {
        swapped = false; // Inicializa swapped como false para cada nova passagem

        // Loop interno: percorre o array comparando elementos adjacentes
        // A condição "n - i - 1" evita verificar os últimos i elementos que já estão ordenados
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Se o elemento atual for maior que o próximo
                troca(&arr[j], &arr[j + 1]); // Troca os dois elementos
                swapped = true;             // Indica que ocorreu uma troca
            }
        }
        // Se nenhuma troca ocorreu, o array já está ordenado e o laço pode ser interrompido
        if (!swapped)
            break;
    }
}

// Função para imprimir os elementos do array, pulando a linha a cada 10 números
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Imprime cada elemento seguido de um espaço
        // A cada 10 números, insere uma quebra de linha
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    // Caso a última linha não tenha completado 10 números, garante a quebra de linha
    if (size % 10 != 0)
        printf("\n");
}

int main(void) {
    // Abre o arquivo "BubbleSort.txt" para leitura
    FILE *arquivo = fopen("BubbleSort.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Inicialização para leitura dinâmica dos números
    int capacity = 10;           // Capacidade inicial do array
    int count = 0;               // Contador de elementos lidos
    int *arr = malloc(capacity * sizeof(int)); // Aloca memória para o array
    if (arr == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return EXIT_FAILURE;
    }

    // Lê os números do arquivo
    int num;
    // Enquanto conseguir ler um número (formato "%d")
    while (fscanf(arquivo, "%d", &num) == 1) {
        // Se o número de elementos atingir a capacidade atual, realoca com o dobro do espaço
        if (count >= capacity) {
            capacity *= 2;
            int *temp = realloc(arr, capacity * sizeof(int));
            if (temp == NULL) {
                perror("Erro ao realocar memória");
                free(arr);
                fclose(arquivo);
                return EXIT_FAILURE;
            }
            arr = temp;
        }
        arr[count++] = num;  // Armazena o número lido e incrementa o contador
    }

    fclose(arquivo);  // Fecha o arquivo após a leitura

    // Ordena o array lido com Bubble Sort
    bubbleSort(arr, count);

    // Imprime o array ordenado com quebras de linha a cada 10 números
    printf("Array ordenado:\n");
    printArray(arr, count);

    // Libera a memória alocada dinamicamente
    free(arr);

    return EXIT_SUCCESS;
}