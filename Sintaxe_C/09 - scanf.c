#include <stdio.h>

int main()
{

    float var;

    printf("Digite um valor com casa decimal:\n");
    scanf("%f", &var);
    printf("O valor inserido: %.2f \n", var);

    char variavel[10];
    printf("Digite um dado \n");
    scanf("%s", variavel);
    printf("o valor digitado foi %s. \n", variavel);

    /*
     %d -> inteiro
     %f -> dados com casas decimais
     %s -> dados de texto
     %c -> uma única letra
    */
}