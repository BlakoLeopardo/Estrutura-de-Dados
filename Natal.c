#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    char sd, se;
    system("cls");
    printf("\nSinal interno direito : ");
    sd = getche();
    printf("\nSinal interno esquerdo : ");
    se = getche();

    printf("\n\n");

    // Cada segmento da árvore (4 segmentos)
    for (int i = 0; i < 4; i++)
    {
        // Cada segmento possui 4 linhas
        for (int k = 1; k < 5; k++)
        {
            // Imprime 40 espaços para centralizar a linha
            for (int s = 0; s < 40; s++)
                printf(" ");
            // Imprime a borda esquerda
            printf("/");
            // Imprime o padrão usando o caractere 'se'
            for (int n = 1; n < 2*i + k; n++)
                printf("%c", se);
            // Imprime o padrão usando o caractere 'sd'
            for (int n = 1; n < 2*i + k; n++)
                printf("%c", sd);
            // Imprime a borda direita e quebra de linha
            printf("\\\n");
        }
    }

    // Desenha o tronco
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 38; j++)
            printf(" ");
        printf("| |\n"); 
    }
    printf("\n");
    for (int j = 0; j < 35; j++) printf(" ");
    printf("FELIZ NATAL\n");
    for (int j = 0; j < 31; j++) printf(" ");
    printf("E UM PROSPERO 2026!\n");
    system("PAUSE");

    return 0;
}