#include <stdbool.h>  // Biblioteca para uso do tipo booleano (bool, true, false)
#include <stdio.h>    // Biblioteca para funções de entrada/saída, como printf

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
            // Se o elemento atual for maior que o próximo, troca os dois
            if (arr[j] > arr[j + 1]) {
                troca(&arr[j], &arr[j + 1]); // Chama a função troca passando os endereços dos elementos
                swapped = true;             // Indica que ocorreu uma troca
            }
        }
        // Se nenhuma troca ocorreu na passagem, o array está ordenado e sai do loop
        if (!swapped)
            break;
    }
}

// Função para imprimir os elementos do array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Imprime cada elemento seguido de um espaço
    }
    printf("\n"); // Imprime uma nova linha ao final para melhor formatação
}

// Função principal
int main() {
    // Declaração e inicialização do array com os valores a serem ordenados
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calcula o número de elementos do array dividindo o tamanho total do array pelo tamanho de um elemento
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função bubbleSort para ordenar o array
    bubbleSort(arr, n);

    // Imprime uma mensagem indicando que o array foi ordenado
    printf("Array ordenado:\n");

    // Chama a função printArray para exibir os elementos ordenados
    printArray(arr, n);

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}