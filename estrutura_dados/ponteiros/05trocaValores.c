#include <stdio.h>

void trocaValores(float *tmp1 , float *tmp2){
    float temp = *tmp1;
    *tmp1 = *tmp2;
    *tmp2 = temp;
}

int main(){

    float num1 , num2;
    num1 = 2.1;
    num2 = 1.2;
    printf("Valores originais: a= %.2f b= %.2f\n", num1 , num2);

    trocaValores(&num1 , &num2);

    printf("Resultado dos valores trocados : a= %.2f , b= %.2f\n", num1 , num2);
}