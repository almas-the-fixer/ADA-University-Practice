#include <stdio.h>

/* Textbook Implementation of Selection Sort */

/* Global Array */

int arr[] = {15, 40, 20, 10, 5, 4, 7, 9};

int main()
{
    int i, j, n = 8, minIndex, temp;

    printf("Initial Array:\n\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap once per pass
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    printf("Sorted Array:\n\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}