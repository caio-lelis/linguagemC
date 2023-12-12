## O que iremos estudar: 

- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort -> relaciona-se ao Insertion Sort


- Quick Sort
- Merge Sort


## O que vamos ordenar?

- Arquivos de itens -> Chaves (Kesys)

## Objetivo do algoritmo de Ordenação:

- Rearranjar os itens de forma que as cheves respeitem a ordem definida.


## O arquivo cabe na memória?

- Se sim -> ordenação interna
- Se não -> ordenação externa

## Vetores ou Listas encadeadas?

Existem algoritmos que são melhores se trabalharmos com vetores e outros com listas encadeadas. Existem também algoritmos que se dão bem com ambos.

# Convenções 

- typedef int Item;

- #define key(A) (A)
- #define less(A, B) (key(A) < key(B))
- #define exch(A, B) { Item t = A; A = B; B = t; } 
- #define cmpexch(A, B) { if (less(B, A)) exch(A, B); }


## Características dos algoritmos de ordenação:

- Estáveis: Garante que itens com chaves idênticas permaneçam na mesma ordem relativa após a ordenação.

- In-place: Requer uma quantidade constante de memória adicional para rearranjar os itens.

- Complexidade

- Adaptabilidade: Se o vetor já está ordenado, o algoritmo não precisa fazer nenhuma troca.