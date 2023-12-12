#include <stdio.h>

void selectionsort(Item *v, int l, int r)
{
    if (l == r)
        return;
    int menor = l;

    for (int j = l + 1; j <= r; j++)
        if (less(v[j], v[menor]))
            menor = j;
}
exch(v[menor], v[l]);
selectionsort(v, l + 1, r);