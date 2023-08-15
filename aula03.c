#include <stdio.h> // Biblioteca usada frequentemente para lidar com operações de entrada e saída.

// Função principal do programa
int main()
{

    int dado;
    int idade;
    printf("insira a sua idade:\n");
    scanf("%d", &idade); // &idade é o endereço de memória da variável idade (ponteiro); %d é o tipo de dado inteiro.
    if (idade >= 18)
    {
        printf("voce e maior de idade.\n");
        printf("pode entrar na balada \n");
    }
    else

        printf("voce n é maior de idade \n");
    printf("Digite um valor entre 1 e 10 \n");
    scanf("%d", &dado);

    if (dado >= 1 && dado <= 10)
    {
        printf("valor correto! \n");
    }
    else
    {
        printf("valor não está dentro do range");
    }
}