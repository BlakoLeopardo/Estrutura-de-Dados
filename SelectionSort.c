#include <stdio.h>

// Função que implementa o algoritmo de Selection Sort
// Ela recebe um array 'arr' e seu tamanho 'n'
void selectionSort(int arr[], int n) {
    // Laço para cada posição do array, exceto a última
    for (int i = 0; i < n - 1; i++) {
        // Assume que o menor elemento está na posição i
        int min_idx = i;
        
        // Laço para encontrar o menor elemento no restante do array (da posição i+1 até o fim)
        for (int j = i + 1; j < n; j++) {
            // Se encontrar um elemento menor que o atual menor...
            if (arr[j] < arr[min_idx]) {
                // Atualiza o índice do menor elemento
                min_idx = j;
            }
        }
        
        // Após encontrar o menor elemento no segmento, faz a troca entre a posição atual e a posição do menor elemento
        int temp = arr[i];       // Armazena o valor atual em uma variável temporária
        arr[i] = arr[min_idx];     // Coloca o menor elemento na posição atual
        arr[min_idx] = temp;       // Coloca o valor que estava na posição atual na posição onde o menor elemento estava
    }
}

// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    // Percorre o array e imprime cada elemento, seguido de um espaço para separação
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    // Quebra de linha ao final da impressão para melhor formatação na saída
    printf("\n");
}

int main() {
    // Declaração e inicialização do array com os números a serem ordenados
    int arr[] = {64, 25, 12, 22, 11};
    // Calcula o número de elementos no array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Impressão do array original
    printf("Original Array: ");
    printArray(arr, n);

    // CHAMADA DA FUNÇÃO selectionSort para ordenar o array
    selectionSort(arr, n);

    // Impressão do array já ordenado
    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}