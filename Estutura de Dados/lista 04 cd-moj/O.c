#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(x) (x)
#define less(a, b) (a < b)
#define exch(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpexch(a, b) \
    if (less(b, a))   \
    exch(a, b)

int partition(Item *arr, int tam)
{
    int esq = -1, dir = tam - 1;
    Item pivo = arr[dir];

    while (1)
    {
        while (less(arr[++esq], pivo))
            ;
        while (less(pivo, arr[--dir]) && dir > esq)
            ;

        if (esq >= dir)
            break;
        exch(arr[esq], arr[dir]);
    }
    exch(arr[esq], arr[tam - 1]);
    return esq;
}

void quicksort(Item *arr, int tam)
{
    if (tam < 2)
        return;

    cmpexch(arr[(tam - 1) / 2], arr[tam - 1]);
    cmpexch(arr[0], arr[(tam - 1) / 2]);
    cmpexch(arr[tam - 1], arr[(tam - 1) / 2]);

    int meio = partition(arr, tam);
    quicksort(arr, meio);
    quicksort(arr + meio + 1, tam - meio - 1);
}

void merge(Item *arr1, int tamArr1, Item *arr2, int tamArr2)
{
    Item *temp = (Item *)malloc((tamArr1 + tamArr2) * sizeof(Item));
    int i = 0, j = 0, k = 0;
    while (i < tamArr1 && j < tamArr2)
    {
        if (key(arr1[i]) <= key(arr2[j]))
            temp[k++] = arr1[i++];
        else
            temp[k++] = arr2[j++];
    }

    while (i < tamArr1)
        temp[k++] = arr1[i++];
    while (j < tamArr2)
        temp[k++] = arr2[j++];

    for (k = 0, i = 0; i < (tamArr1 + tamArr2); i++, k++)
        arr1[i] = temp[k];

    free(temp);
}

int remove_duplicates(Item *arr, int n)
{
    int tam = 1;
    int i = 1;
    while (i < n)
    {
        if (arr[i] != arr[tam - 1])
            arr[tam++] = arr[i];
        i++;
    }
    return tam;
}

int main()
{
    int n;
    scanf(" %d", &n);
    int *arr = (int *)malloc(sizeof(int) * (2 * n));
    int i = 0;
    while (i < n)
    {
        scanf(" %d", arr + i);
        i++;
    }

    quicksort(arr, n);

    int tam = remove_duplicates(arr, n);
    if (tam % 2)
        arr[tam++] = 1000000000;

    int tamLouco = 0;
    i = 0;
    while (i < tam - 1)
    {
        arr[tam + tamLouco++] = arr[i] + arr[i + 1];
        i += 2;
    }

    merge(arr, tam, arr + tam, tamLouco);
    tam = remove_duplicates(arr, tam + tamLouco);
    i = 0;
    while (i < tam)
    {
        printf("%d\n", arr[i]);
        i += 4;
    }
    printf("Elementos: %d\n", tam);

    free(arr);

    return 0;
}
