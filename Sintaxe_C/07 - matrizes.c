#include <stdio.h>

int main()
{
    int matriz[2][3] = {{1, 1, 1}, {8, 8, 8}};
    int linha;
    int coluna;

    for (linha = 0; linha < 2; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("%d", matriz[linha][coluna]);
        }
        printf("\n");
    }
}