#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int binarySearch(int *array, int left, int right, int query)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == query)
            return 1;
        else if (array[mid] < query)
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

    int prohibited[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &prohibited[i]);
    }

    // Ordena o array de números proibidos
    mergeSort(prohibited, 0, N - 1);

    int consulta;
    while (scanf("%d", &consulta) != EOF)
    {
        // Realiza busca binária para verificar se o número de consulta está presente no array ordenado
        if (binarySearch(prohibited, 0, N - 1, consulta))
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
