#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenaRecursivo(int *v, int n, int i)
{
    while (i < n - 1)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (v[j] < v[min])
                min = j;
        }

        swap(&v[i], &v[min]);

        i++; // Increment i for the next iteration
    }
}

void ordena(int *v, int n)
{
    if (n <= 1)
        return;

    ordenaRecursivo(v, n, 0);
}
