#include <stdio.h>

int main() {
    int numero = 11111;
    int *ptr; // ponteiro para um inteiro

    ptr = &numero; // ptr agora aponta para o endereço de numero

    printf("numero: %d\n", numero);
    printf("Endereço do número: %p\n", ptr);
    printf("Valor do número: %d\n", *ptr);

    return 0;
}
