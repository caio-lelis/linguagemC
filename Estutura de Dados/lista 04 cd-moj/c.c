#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int numbers[50000];
    int input, count = 0;

    // Lendo os números da entrada
    while (scanf("%d", &input) != EOF)
    {
        numbers[count++] = input;
    }

    insertionSort(numbers, count);

    // Imprimindo os números ordenados
    for (int i = 0; i < count; i++)
    {
        printf("%d", numbers[i]);
        if (i != count - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
