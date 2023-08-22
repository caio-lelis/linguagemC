#include <stdio.h>

int main()
{

    char texto[10];

    printf("Digite um texto:\n");
    fgets(texto, 10, stdin);

    printf("você digitou: %s. \n", texto);

    char textinho[10];
    printf("Digite outro texto: \n");
    gets(textinho);
    printf("você digitou: %s \n", textinho);
}