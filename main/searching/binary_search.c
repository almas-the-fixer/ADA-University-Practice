#include <stdio.h>

/* Implementing Binary Search */

/* Global Array as Usual */

/* Array MUST BE SORTED!! */

int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int n = sizeof(arr) / sizeof(arr[0]);

// NOT PERFECT BUT WORKS!!
int binarySearch(int arr[], int key)
{
    int low, high;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int key, result;

    printf("--------Implementing Binary Search-------\n\n\n");

    printf("-----The Array we Have-----\n\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    printf("Enter the Key You Wanna Search: ");
    scanf("%d", &key);

    result = binarySearch(arr, key);

    if (result != -1)
    {
        printf("The Key you Searched is Present at %d index of array!!\n\n", result);
    }
    else
    {
        printf("The Key you entered is NOT present in this array!\n\n");
    }
}