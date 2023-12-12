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

int partition(Item *array, int size)
{
    int left = -1, right = size - 1;
    Item pivot = array[right];

    for (;;)
    {
        for (; less(array[++left], pivot);)
            ;
        for (; less(pivot, array[--right]) && right > left;)
            ;

        if (left >= right)
            break;
        exch(array[left], array[right]);
    }
    exch(array[left], array[size - 1]);
    return left;
}

void quicksort(Item *array, int size)
{
    if (size < 2)
        return;

    cmpexch(array[(size - 1) / 2], array[size - 1]);
    cmpexch(array[0], array[(size - 1) / 2]);
    cmpexch(array[size - 1], array[(size - 1) / 2]);

    int middle = partition(array, size);
    quicksort(array, middle);
    quicksort(array + middle + 1, size - middle - 1);
}

void merge(Item *firstArray, int sizeFirst, Item *secondArray, int sizeSecond)
{
    Item *temp = (Item *)malloc((sizeFirst + sizeSecond) * sizeof(Item));
    int i = 0, j = 0, k = 0;
    for (; i < sizeFirst && j < sizeSecond; k++)
    {
        if (key(firstArray[i]) <= key(secondArray[j]))
            temp[k] = firstArray[i++];
        else
            temp[k] = secondArray[j++];
    }

    while (i < sizeFirst)
        temp[k++] = firstArray[i++];
    while (j < sizeSecond)
        temp[k++] = secondArray[j++];

    for (k = 0, i = 0; i < (sizeFirst + sizeSecond); i++, k++)
        firstArray[i] = temp[k];

    free(temp);
}

int remove_duplicates(Item *array, int n)
{
    int size = 1;
    for (int i = 1; i < n; i++)
        if (array[i] != array[size - 1])
            array[size++] = array[i];
    return size;
}

int main()
{
    int n;
    scanf(" %d", &n);
    int *array = (int *)malloc(sizeof(int) * (2 * n));
    for (int i = 0; i < n; i++)
        scanf(" %d", array + i);

    quicksort(array, n);

    int size = remove_duplicates(array, n);
    if (size % 2)
        array[size++] = 1000000000;

    int sizeCrazy = 0;
    for (int i = 0; i < size - 1; i += 2)
        array[size + sizeCrazy++] = array[i] + array[i + 1];

    merge(array, size, array + size, sizeCrazy);
    size = remove_duplicates(array, size + sizeCrazy);
    for (int i = 0; i < size; i += 4)
        printf("%d\n", array[i]);
    printf("Elementos: %d\n", size);

    free(array);

    return 0;
}
