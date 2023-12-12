#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Result
{
    int frequency;
    int index;
    char symbol;
} Result;

void merge(Result *arr, int left, int mid, int right)
{
    Result *tempArr = malloc(sizeof(Result) * (right - left + 1));
    int tempIndex = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i].frequency < arr[j].frequency)
        {
            tempArr[tempIndex++] = arr[i++];
        }
        else
        {
            tempArr[tempIndex++] = arr[j++];
        }
    }

    while (i <= mid)
        tempArr[tempIndex++] = arr[i++];
    while (j <= right)
        tempArr[tempIndex++] = arr[j++];

    tempIndex = 0;
    for (i = left; i <= right; i++)
    {
        arr[i] = tempArr[tempIndex++];
    }

    free(tempArr);
}

void mergeSort(Result *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    char inputPhrase[100001];
    scanf("%s", inputPhrase);
    int currentIndex = 0;
    int outputIndex = 0;
    Result outputResult[strlen(inputPhrase)];
    outputResult[outputIndex].frequency = 0;

    for (int i = 0; i < strlen(inputPhrase); i++)
    {
        if (inputPhrase[currentIndex] != inputPhrase[i])
        {
            currentIndex = i;
            outputIndex++;
            outputResult[outputIndex].frequency = 0;
        }
        outputResult[outputIndex].frequency++;
        outputResult[outputIndex].index = currentIndex;
        outputResult[outputIndex].symbol = inputPhrase[currentIndex];
    }

    mergeSort(outputResult, 0, outputIndex);

    for (int i = outputIndex; i >= 0; i--)
    {
        printf(" %d %c %d\n", outputResult[i].frequency, outputResult[i].symbol, outputResult[i].index);
    }

    return 0;
}
