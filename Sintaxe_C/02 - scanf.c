#include <stdio.h> // Biblioteca usada frequentemente para lidar com operações de entrada e saída.

// Função principal do programa
int main()
{

    int idade;
    printf("insira a sua idade:\n");
    scanf("%d", &idade); // &idade é o endereço de memória da variável idade (ponteiro); %d é o tipo de dado inteiro.
    printf("no ano que vem você terá : %d. \n", idade + 1);
}