#include <stdio.h>

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto)
{
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j] < pivo)
        {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Quantidade inválida de elementos.\n");
        return 1;
    }

    int numeros[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numeros[i]);
    }

    quicksort(numeros, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d", numeros[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
