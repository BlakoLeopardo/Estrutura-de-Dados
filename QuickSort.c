#include <stdio.h>

// Função para trocar os valores apontados por 'a' e 'b'
void troca(int* a, int* b) {
    int teemo = *a;  // Armazena o valor de *a em uma variável auxiliar
    *a = *b;         // Atribui o valor de *b para *a
    *b = teemo;      // Atribui o valor armazenado em teemo para *b
}

// Função de partição (usando o método de Hoare)
int part(int arr[], int low, int high) {
    int p = arr[low];  // Escolhe o primeiro elemento como pivô
    int i = low;
    int j = high;

    // Enquanto os ponteiros não se cruzarem
    while (i < j) {
        // Incrementa 'i' enquanto o elemento for menor ou igual ao pivô
        while (i <= high - 1 && arr[i] <= p) {
            i++;
        }
        // Decrementa 'j' enquanto o elemento for maior que o pivô
        while (j >= low + 1 && arr[j] > p) {
            j--;
        }
        // Se 'i' ainda é menor que 'j', troca os elementos de arr[i] e arr[j]
        if (i < j) {
            troca(&arr[i], &arr[j]);
        }
    }
    // Após a partição, troca o pivô com o elemento em arr[j]
    troca(&arr[low], &arr[j]);
    return j; // Retorna a posição correta do pivô
}

// Função principal de ordenação QuickSort
void quick(int arr[], int low, int high) {
    if (low < high) {
        // Obtém a posição do pivô após a partição
        int pi = part(arr, low, high);
        // Aplica recursivamente o quicksort nas partições à esquerda e à direita do pivô
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

// Função principal do programa
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chama o quicksort no array completo
    quick(arr, 0, n - 1);

    // Imprime o array ordenado
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}