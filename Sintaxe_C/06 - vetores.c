#include <stdio.h>

int main()
{
    int vet[5] = {10, 20, 30, 40, 50};

    printf("o valor da primeira posição do seu vetor é %d \n", vet[0]);

    int i;

    printf("seu vetor é:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Usuário imprimindo os elementos na minha matriz:

    int vetor[2] = {0, 0, 0};
    int z;
    for (z = 0; z < 3; z++)
    {
        printf("Insira o elemento da posição %d \n", z);
        scanf("%d", &vetor[z]);
    }
    printf("Esses são os elementos selecionados para o vetor: \n");
    for (z = 0; z < 3; z++)
    {
        printf("%d  ", vetor[z]);
    }
    printf("\n");
}
