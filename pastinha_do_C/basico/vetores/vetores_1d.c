// Matrizes de uma dimensão

#include <stdio.h>
#include <stdlib.h>

int busca(char vet[], int tam, char target) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int vetor[10] = {0}; // Inicializa um vetor com 10 posições começando com o valor 0
    vetor[0] = 123456;
    vetor[5] = 15;

    for (int i = 0; i < 10; i++) {
        printf("%d \n", vetor[i]);
    }

    // Função busca:
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char char_buscar;
    int posicao;

    printf("Digite um caractere para buscar, por favor: ");
    scanf(" %c", &char_buscar);
    posicao = busca(letras, 10, char_buscar);

    if (posicao != -1)
        printf("Encontrado na posição: %d\n", posicao);
    else
        printf("Não encontrado\n");

    return 0;
}