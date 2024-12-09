#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//Declara um vetor de inteiros com 10 elementos, inicializados em 0.
	int vetor[10] = {0};
	vetor[1] = 123456;
	vetor[2] = 99999;
	for(int i = 0; i < 10; i++){
		printf("%d\n",vetor[i]);
	}
}
