#include <stdio.h>

int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int n = sizeof(arr) / sizeof(arr[0]);

int recursiveBinSearch(int beg, int end, int key)
{
    if (beg > end)
        return -1;

    int mid = beg + (end - beg) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBinSearch(mid + 1, end, key);
    else
        return recursiveBinSearch(beg, mid - 1, key);
}

int main()
{
    int key, result;

    printf("----------Implementing Recursive Binary Search----------\n\n");
    printf("Array that we are using: =>\t");

    for (int i = 0; i < n; i++)
        printf("%d | \t", arr[i]);

    printf("\n\nEnter The Key to Search in this array: => ");
    scanf("%d", &key);

    result = recursiveBinSearch(0, n - 1, key);

    if (result != -1)
        printf("Element Found at %d index of array!\n", result);
    else
        printf("Element you searched for is not present in this array!!\n");

    return 0;
}
