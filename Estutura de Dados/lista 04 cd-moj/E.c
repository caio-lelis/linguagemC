#include <stdio.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenaRecursivo(int *v, int n, int i)
{
    if (i >= n - 1)
        return;

    int min_idx = i;
    for (int j = i + 1; j < n; ++j)
    {
        if (v[j] < v[min_idx])
            min_idx = j;
    }

    troca(&v[i], &v[min_idx]);

    ordenaRecursivo(v, n, i + 1);
}

void ordena(int *v, int n)
{
    if (n <= 1)
        return;

    ordenaRecursivo(v, n, 0);
}
