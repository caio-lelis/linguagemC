#include <stdio.h>
#include <stdlib.h>

int AckermannRecursivo(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0 && m > 0) {
        return AckermannRecursivo(m - 1, 1);
    }
    if (m > 0 && n > 0) {
        return AckermannRecursivo(m - 1, AckermannRecursivo(m, n - 1));
    }
    return 0;
}

// int main() {
//     int valor1;
//     int valor2;
//     printf("Digite o valor de m: ");
//     scanf(" %d" , &valor1);
//     printf("Digite o valor de n:");
//     scanf(" %d", &valor2);
//     printf("%d\n", AckermannRecursivo(valor1, valor2));
//     return 0;
// }



