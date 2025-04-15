#include <stdio.h>

// Função que implementa o algoritmo Insertion Sort
// O array "arr" é ordenado em ordem crescente e "n" é o número de elementos do array
void insertionSort(int arr[], int n)
{
    // Começamos a iteração a partir do segundo elemento (índice 1)
    // pois o primeiro elemento já é considerado ordenado
    for (int i = 1; i < n; ++i) {
        // Armazena o elemento atual como "key" (a chave que será inserida na posição correta)
        int key = arr[i];
        // Define o índice "j" como o elemento imediatamente anterior à "key"
        int j = i - 1;

        // Enquanto houver elementos à esquerda de "key" e o elemento à esquerda for maior que a "key",
        // movemos o elemento para uma posição à direita.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Move o elemento atual para a posição à direita
            j = j - 1;            // Decrementa "j" para continuar comparando com os elementos anteriores
        }
        // Após encontrar a posição correta, insere a "key" na posição correta
        arr[j + 1] = key;
    }
}

// Função para imprimir os elementos do array
void printArray(int arr[], int n)
{
    // Percorre o array e imprime cada elemento seguido de um espaço
    for (int i = 0; i < n; ++i)
        printf("%d\t", arr[i]);
    // Imprime uma quebra de linha após a impressão dos elementos
    printf("\n");
}

// Função principal
int main()
{
    // Declaração e inicialização de um array desordenado
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // Calcula o número de elementos do array dividindo o tamanho total pelo tamanho de um elemento
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função que ordena o array utilizando o Insertion Sort
    insertionSort(arr, n);
    
    // Imprime uma mensagem indicando que o array foi ordenado
    printf("Array ordenado:\n");
    
    // Chama a função para imprimir o array ordenado
    printArray(arr, n);

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}