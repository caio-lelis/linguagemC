## Selection sort

## Características:

- In-place
- Não é estável
- Complexidade: O(n²)
- Adaptabilidade: Não é adaptável

0 | 1 |2 |3 |4 |5   
30|45 |60|10|5 |92


void selectionsort(Item *v, int l, int r){
    if (l == r) return;
    int menor = l;

    for (int j = l+1; j <=r; j++)
        if (less(v[j], v[menor]))
            menor = j;

}   
exch(v[menor], v[l]);
selectionsort(v, l+1, r);

### recursivamente faríamos:

- selectionsort(v,0,5); -> 0 | 1 |2 |3 |4 |5
                         5 |45 |60|10|30|92

- selectionsort(v,1,5); -> 0 | 1 |2 |3 |4 |5
                         5 |10 |60|45|30|92

- selectionsort(v,2,5); -> 0 | 1 |2 |3 |4 |5
                        5  | 10|30|45|60|92

- selectionsort(v,3,5); -> 0 | 1 |2 |3 |4 |5
                        5  | 10|30|45|60|92

- selectionsort(v,4,5); -> 0 | 1 |2 |3 |4 |5
                        5  | 10|30|45|60|92

- selectionsort(v,5,5); -> 0 | 1 |2 |3 |4 |5
                        5  | 10|30|45|60|92