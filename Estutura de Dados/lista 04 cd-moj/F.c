#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int tamanho;
    char caractere;
    int posicao;
} Sequencia;

void merge(Sequencia *sequencias, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Sequencia L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = sequencias[left + i];
    for (j = 0; j < n2; j++)
        R[j] = sequencias[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].tamanho >= R[j].tamanho)
        {
            sequencias[k] = L[i];
            i++;
        }
        else
        {
            sequencias[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        sequencias[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        sequencias[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Sequencia *sequencias, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(sequencias, left, mid);
        mergeSort(sequencias, mid + 1, right);

        merge(sequencias, left, mid, right);
    }
}

void contarSequencias(char *entrada)
{
    int tamanho = strlen(entrada);
    Sequencia sequencias[tamanho];
    int count = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (i == 0 || entrada[i] != entrada[i - 1])
        {
            sequencias[count].caractere = entrada[i];
            sequencias[count].posicao = i;
            sequencias[count].tamanho = 1;
            count++;
        }
        else
        {
            sequencias[count - 1].tamanho++;
        }
    }

    mergeSort(sequencias, 0, count - 1);

    for (int i = 0; i < count; i++)
    {
        printf("%d %c %d\n", sequencias[i].tamanho, sequencias[i].caractere, sequencias[i].posicao);
    }
}

int main()
{
    char entrada[100001];
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // Remover o caractere de nova linha

    contarSequencias(entrada);

    return 0;
}
