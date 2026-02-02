#include <stdio.h>

int arr[] = {15, 20, 30, 10, 5, 6, 1, 0, 40};

int main()
{
    int i, j, n, key;

    n = sizeof(arr) / sizeof(arr[0]);

    printf("-------Implementing Insertion Sort-------\n\n");
    printf("Initial Array: ==> \t");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];  // shift right
            j--;
        }
        arr[j + 1] = key;         // insert key
    }

    printf("Sorted Array: ==> \t");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
