#include <stdio.h>

/* Implementing Selection Sort on a static array */

int arr[] = {15, 40, 20, 10, 5, 4, 7, 9};

void main()
{
    int i, j, n, temp, minIndex;

    // n = sizeof(arr) / sizeof(arr[0]); // Just to get array size
    n = 8; // you can ignore the above line for simplicity and wese bhi exam me jo check karne aate hai vo mostly output se matlab or faltu me tumse puch lenge sizeof() kya karta hai.. isiliye static array k liye hardcode kr do element gin ke array ke andar...

    printf("-------**Selection Sort**-------\n\n\n");

    printf("Initial Array:\n\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Apply Selection Sort */

    /* ye mera implementation hai */
    /* acc to gpt ye chal jayega or sort kar dega lekin textbook selection sort nahi hai uske liye tb_selection_sort.c file me dekh lo please 😭*/

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("\n\n\nSorted Array: \n\n\n");
    /* Print Result */
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}