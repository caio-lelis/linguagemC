#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    char keyword[16];
} Result;

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    return ((Result *)a)->code - ((Result *)b)->code;
}

// Binary search function
char *binarySearch(Result *Results, int size, int query)
{
    for (int left = 0, right = size - 1; left <= right;)
    {
        int mid = left + (right - left) / 2;

        if (Results[mid].code == query)
            return Results[mid].keyword;
        else if (Results[mid].code < query)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return "undefined";
}

int main()
{
    int numResults;
    scanf("%d", &numResults);

    Result Results[numResults];

    // Reading Results and codes
    for (int i = 0; i < numResults; i++)
    {
        scanf("%d %s", &Results[i].code, Results[i].keyword);
    }

    // Sorting Results using qsort
    qsort(Results, numResults, sizeof(Result), compare);

    int queryCode;
    while (scanf("%d", &queryCode) != EOF)
    {
        // Performs binary search to find the keyword corresponding to the code
        printf("%s\n", binarySearch(Results, numResults, queryCode));
    }

    return 0;
}
