// Matrizes 2 Dimensões
#include <stdio.h>
#include <stdlib.h>

int main(){
    // -> Declarando matriz que possui 3 linhas e quatro colunas
    int matriz_2d[3][4] = {0};
    matriz_2d[2][1] = 15; //Atribuindo o valor 15 p o terceiro elemento da segunda coluna
    matriz_2d[0][0] = 111111;
    
    for(int i = 0; i < 3 ; i++){
        for(int j = 0;  j < 4; j++){
            printf("%d\n" , matriz_2d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

