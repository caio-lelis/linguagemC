#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int element;
    int pos;
} Pair;

int compare(const void *a, const void *b)
{
    return ((Pair *)a)->element - ((Pair *)b)->element;
}

int binary_search(Pair *array, int left, int right, int query)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[mid].element == query)
            return array[mid].pos;
        if (array[mid].element < query)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, q, i;
    scanf("%d %d", &n, &q);

    Pair array[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i].element);
        array[i].pos = i;
    }

    qsort(array, n, sizeof(Pair), compare);

    for (i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);

        printf("%d\n", binary_search(array, 0, n - 1, query));
    }

    return 0;
}
