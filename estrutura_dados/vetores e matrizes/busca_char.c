#include <stdio.h>

int busca(char vet[], int tamanho, char alvo){
     for(int i=0; i < tamanho ; i++){
        if(vet[i] == alvo){
            return i;
        }
     }
}

int main(){

    char letras[10] = \
    {'A' ,'B' ,'C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J'};
    char caracter_alvo;
    int posicao;
    printf("Digite um char para que seja buscado no vetor\n");
    scanf("%c\n",&caracter_alvo);
    posicao = busca(letras , 10 , caracter_alvo);
    if (posicao != -1)
        printf("Encontrado na posição: %d\n" , posicao);
    else
        printf("o caractere %c não foi encontrado" , &caracter_alvo);
    return 0;
}