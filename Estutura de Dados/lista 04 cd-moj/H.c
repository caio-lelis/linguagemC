#include <stdio.h>

int binarySearch(int array[], int size, int target)
{
    int left = 0, right = size;

    for (; left < right;)
    {
        int middle = left + (right - left) / 2;

        if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }

    return left;
}

int main()
{
    int elements, queries, queryValue;
    scanf("%d %d", &elements, &queries);

    int data[elements];

    for (int i = 0; i < elements; i++)
    {
        scanf("%d", &data[i]);
    }

    for (int i = 0; i < queries; i++)
    {
        scanf("%d", &queryValue);
        int result = binarySearch(data, elements, queryValue);
        printf("%d\n", result);
    }

    return 0;
}
