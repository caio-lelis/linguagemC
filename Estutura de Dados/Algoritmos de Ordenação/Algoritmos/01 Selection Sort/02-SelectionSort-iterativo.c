#include <stdio.h>

void selectionsort(Item *v, int l, int r)
{
    for (int i = l, i < r, i++)
    {
        int menor = i;

        for (int i + 1; j <= r; j++)
            if (less(v[j], v[menor]))
                menor = j;
    }
}
exch(v[menor], v[l]);

// Função de teste para o Selection

int main(void)
{

    Item vetor[1000];
    for (int i = 0; i < 1000; i++)
        vetor[i] = rand();

    selectionsort(v, 0, 999);
    return 0;
}