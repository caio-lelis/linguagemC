#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
    {
        Left[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int binarySearch(int *arr, int left, int right, int query)
{
    for (; left <= right;)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == query)
            return 1;
        else if (arr[mid] < query)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);

    int proibido[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &proibido[i]);
    }

    // Ordena o array de números proibidos
    mergeSort(proibido, 0, N - 1);

    int query;
    while (scanf("%d", &query) != EOF)
    {
        // Realiza busca binária para verificar se o número de consulta está presente no array ordenado
        if (binarySearch(proibido, 0, N - 1, query))
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }

    return 0;
}
