#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000001
#define MAX_LENGTH 82

typedef struct
{
    char jp[MAX_LENGTH];
    char br[MAX_LENGTH];
} Item;

int less(const char *a, const char *b)
{
    return strcmp(a, b) < 0;
}

void swap(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item *arr, int left, int right)
{
    Item pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (less(arr[j].jp, pivot.jp))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(Item *arr, int left, int right)
{
    if (left < right)
    {
        int partitionIndex = partition(arr, left, right);

        quicksort(arr, left, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, right);
    }
}

int binarySearch(Item *arr, int left, int right, const char *key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (strcmp(arr[mid].jp, key) == 0)
        {
            return mid;
        }
        else if (less(arr[mid].jp, key))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void traduction()
{
    int x, y;
    scanf("%d %d", &x, &y);
    getchar();

    Item v[MAX_SIZE];

    for (int i = 0; i < x; i++)
    {
        fgets(v[i].jp, MAX_LENGTH, stdin);
        v[i].jp[strcspn(v[i].jp, "\n")] = '\0';
        fgets(v[i].br, MAX_LENGTH, stdin);
        v[i].br[strcspn(v[i].br, "\n")] = '\0';
    }

    quicksort(v, 0, x - 1);

    while (y--)
    {
        char line[MAX_LENGTH * 2];
        fgets(line, sizeof(line), stdin);

        char *token = strtok(line, " \n");
        while (token != NULL)
        {
            int idx = binarySearch(v, 0, x - 1, token);
            printf("%s", (idx != -1 ? v[idx].br : token));
            token = strtok(NULL, " \n");
            printf("%c", (token == NULL ? '\n' : ' '));
        }
    }
}

int main()
{
    int z;
    scanf("%d", &z);
    getchar();

    while (z--)
    {
        traduction();
        printf("\n");
    }

    return 0;
}
