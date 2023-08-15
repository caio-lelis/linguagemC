#include <stdio.h>
/*
struct novoTipo
{
    int numeroInteiro;
    float numeroDecimal;
};
*/

struct produto
{
    int codigo;
    float valorProduto;
};

int main()
{

    struct produto havaiana;
    printf("insira o código do produto: \n");
    scanf("%d", &havaiana.codigo);

    printf("insira o valor do produto: \n");
    scanf("%f", &havaiana.valorProduto);

    printf("\n");
    printf("O seu produto tem os seguintes dados: \n");
    printf("Código: %d \n", havaiana.codigo);
    printf("Valor: R$ %2.f \n", havaiana.valorProduto);

    /*struct novoTipo numeros;
    numeros.numeroDecimal = 7.25;
    numeros.numeroInteiro = 93;
    printf("%d %.2f", numeros.numeroDecimal, numeros.numeroInteiro);
    printf("\n");*/
}