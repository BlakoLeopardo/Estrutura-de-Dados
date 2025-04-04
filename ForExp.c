#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int i, j, k;
    system("cls"); // Limpa a tela

    // Dois grupos de 5 tabuadas cada: 1 a 5 e 6 a 10
    for (k = 0; k < 2; k++){
        printf("\n");
        // Cabeçalho: imprime o título de cada tabuada
        for (i = 0; i < 5; i++){
            printf("TABUADA DO %3d\t", k*5 + i + 1);
        }
        printf("\n");

        // Corpo: imprime as multiplicações de 1 a 9 para cada tabuada
        for (i = 1; i <= 9; i++){
            for(j = k*5 + 1; j <= k*5 + 5; j++){
                printf("%2d X %3d = %3d\t", j, i, j*i);
            }
            printf("\n");
        }
    }
    return 0;
}
