#include <stdio.h>

/* Implementing Bubble Sort */

// /* Swap Function to swap 2 numbers*/
// void swap(int a, int b){

// }

/* Swap func will have to need pointers im not using them to keep it simple... */

/* Using Globally defined static unsorted array...*/

int arr[8] = {10, 5, 4, 8, 9, 5, 7, 1};

int main()
{
    int i, j, temp;

    printf("\n\n-------Initial Array-------");

    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Sorting using Bubble sort */
    for (i = 0; i < 8 - 1; i++)
    {
        for (j = 0; j < 8 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n\n-------Sorted Array:-------");

    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
