#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key, value;
} Item;

int partition(Item *v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
    {
        if (v[k].value > pivot.value || (v[k].value == pivot.value && v[k].key > pivot.key))
        {
            Item temp = v[k];
            v[k] = v[j];
            v[j] = temp;
            j++;
        }
    }
    Item temp = v[j];
    v[j] = v[r];
    v[r] = temp;
    return j;
}

void quicksort(Item *v, int l, int r)
{
    if (r <= l)
        return;

    int m = partition(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}

int main()
{
    long long x, y, z;
    scanf("%lld %lld %lld", &x, &y, &z);

    Item candidates[91], secondaries[901], thirds[9001], fourths[90001];
    int candidates_count = 0, secondaries_count = 0, thirds_count = 0, fourths_count = 0;

    long long valid = 0, invalid = 0, total_candidates = 0;
    for (int num, len; scanf("%d%n", &num, &len) == 1;)
    {
        if (num < 0)
        {
            invalid++;
            continue;
        }

        if (len == 3)
        {
            candidates[num - 10].key = num;
            candidates[num - 10].value++;
        }
        else if (len == 4)
        {
            secondaries[num - 100].key = num;
            secondaries[num - 100].value++;
        }
        else if (len == 5)
        {
            thirds[num - 1000].key = num;
            thirds[num - 1000].value++;
        }
        else
        {
            fourths[num - 10000].key = num;
            fourths[num - 10000].value++;
        }
        valid++;
        total_candidates++;
    }

    for (int i = 0; i < 91; i++)
        if (candidates[i].value)
            candidates[candidates_count++] = candidates[i];
    for (int i = 0; i < 901; i++)
        if (secondaries[i].value)
            secondaries[secondaries_count++] = secondaries[i];
    for (int i = 0; i < 9001; i++)
        if (thirds[i].value)
            thirds[thirds_count++] = thirds[i];
    for (int i = 0; i < 90001; i++)
        if (fourths[i].value)
            fourths[fourths_count++] = fourths[i];

    printf("%lld %lld\n", valid, invalid);

    quicksort(candidates, 0, candidates_count - 1);
    quicksort(secondaries, 0, secondaries_count - 1);
    quicksort(thirds, 0, thirds_count - 1);
    quicksort(fourths, 0, fourths_count - 1);

    if (candidates_count > 0 && (double)candidates[0].value / total_candidates >= .51)
        printf("%d\n", candidates[0].key);
    else
        printf("Second round\n");

    for (int i = 0; i < secondaries_count; i++)
        printf("%d%c", secondaries[i].key, " \n"[i == secondaries_count - 1]);
    for (int i = 0; i < thirds_count; i++)
        printf("%d%c", thirds[i].key, " \n"[i == thirds_count - 1]);
    for (int i = 0; i < fourths_count; i++)
        printf("%d%c", fourths[i].key, " \n"[i == fourths_count - 1]);

    return 0;
}
