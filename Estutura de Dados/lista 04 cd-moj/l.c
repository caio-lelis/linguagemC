#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    char word[16];
} Instruction;

// Função de comparação para o qsort
int compare(const void *a, const void *b)
{
    return ((Instruction *)a)->code - ((Instruction *)b)->code;
}

// Função de busca binária
char *binarySearch(Instruction *instructions, int n, int query)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (instructions[mid].code == query)
            return instructions[mid].word;
        else if (instructions[mid].code < query)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return "undefined";
}

int main()
{
    int N;
    scanf("%d", &N);

    Instruction instructions[N];

    // Leitura das instruções e códigos
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &instructions[i].code, instructions[i].word);
    }

    // Ordenação das instruções usando qsort
    qsort(instructions, N, sizeof(Instruction), compare);

    int consulta;
    while (scanf("%d", &consulta) != EOF)
    {
        // Realiza a busca binária para encontrar a palavra-chave correspondente ao código
        printf("%s\n", binarySearch(instructions, N, consulta));
    }

    return 0;
}
