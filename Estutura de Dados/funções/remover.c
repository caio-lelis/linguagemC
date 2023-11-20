#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p == NULL || p->prox == NULL)
    {
        return 0;
    }
    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
    return 1;
}

void remove_elemento(celula *le, int x)
{
    celula *temp = le;
    while (temp->prox != NULL && temp->prox->dado != x)
    {
        temp = temp->prox;
    }
    if (temp->prox != NULL)
    {
        celula *remover = temp->prox;
        temp->prox = remover->prox;
        free(remover);
    }
}

void remove_todos_elementos(celula *le, int x)
{
    celula *temp = le;
    while (temp->prox != NULL)
    {
        if (temp->prox->dado == x)
        {
            celula *remover = temp->prox;
            temp->prox = remover->prox;
            free(remover);
        }
        else
        {
            temp = temp->prox;
        }
    }
}