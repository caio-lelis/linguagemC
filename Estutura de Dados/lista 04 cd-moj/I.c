#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int position;
} Pair;

int compare(const void *a, const void *b)
{
    return ((Pair *)a)->value - ((Pair *)b)->value;
}

int binary_search(Pair *arr, int left, int right, int query)
{
    for (; left <= right;)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid].value == query)
            return arr[mid].position;
        if (arr[mid].value < query)
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

    Pair arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].position = i;
    }

    qsort(arr, n, sizeof(Pair), compare);

    for (i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);

        printf("%d\n", binary_search(arr, 0, n - 1, query));
    }

    return 0;
}
