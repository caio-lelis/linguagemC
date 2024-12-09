# Recursividade

Uma função recursvia é uma função é uma função que resolve uma parte pequena de um problema, 
e que, para resolver o resto do problema, chama a si mesma.

### Exemplo fácil e prático

Um exemplo fácil de programar é o fatorial de um número. O fatorial de um número é o produto de todos os inteiros positivos menores ou iguais a ele.

Definição matemática:

Fatorial(x) = produto dos inteiros de 1 a x
ex Fatorial(5) = 5 * 4 * 3 * 2 * 1 = 120

Em outras palavras:

Se x = 1 então Fatorial(x) = 1
Senão, fatorial(x) = x * Fatorial(x-1)
