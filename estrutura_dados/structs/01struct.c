#include <stdio.h>

int main(){

    struct Livro {
        int id_livro;
        char nome_livro[50];
        char descricao_livro[50];
        char autor_livro[50];

    };

    struct Livro livro1 = {123, "livro qualquer", "descricao qualquer", "autor_qualquer"};

    printf("id do livro: %d \n", livro1.id_livro);
    printf("nome do livro: %s \n", livro1.nome_livro);
    printf("descricao do livro: %s \n", livro1.descricao_livro);
    printf("autor do livro: %s \n", livro1.autor_livro);

}