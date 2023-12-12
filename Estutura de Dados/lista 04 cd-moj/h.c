#include <stdio.h>

int buscaBinaria(int v[], int n, int x)
{
    int esquerda = 0, direita = n; // Inicializa os ponteiros esquerda e direita

    // Enquanto o espaço de busca não estiver esgotado
    while (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2; // Calcula o índice do meio

        // Se o elemento no índice do meio for menor que o alvo, descarte a metade esquerda
        if (v[meio] < x)
        {
            esquerda = meio + 1;
        }
        // Caso contrário, descarte a metade direita
        else
        {
            direita = meio;
        }
    }

    // Retorna o ponteiro esquerdo que aponta para a posição onde o alvo deveria estar
    return esquerda;
}

int main()
{
    int N, Q, J;            // Declara variáveis para o número de elementos (N), número de consultas (Q) e o elemento a ser buscado (J)
    scanf("%d %d", &N, &Q); // Lê N e Q da entrada

    int v[N]; // Declara um array v de tamanho N

    // Lê os N elementos do array da entrada
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }

    // Para cada consulta
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &J); // Lê o elemento a ser buscado da entrada

        // Realiza uma busca binária por J no array v
        int resultado = buscaBinaria(v, N, J);

        // Imprime o resultado da busca binária
        printf("%d\n", resultado);
    }

    return 0; // Fim do programa
}
