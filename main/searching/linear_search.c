#include <stdio.h>

/* global array */

int arr[] = {1, 3, 6, 8, 2, 4, 10, 25, 30};

int n = sizeof(arr) / sizeof(arr[0]);

// Linear Search Function

int linearSearch(int arr[], int key)
{
    int i, result;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            result = i;
            return result;
        }
        else{
            return -1;
        }
    }
}

int main()
{

    int key, key_idx;

    printf("Heres what we have in out Array: ==> \t");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    printf("Enter the Key you wanna search in the static array: ");
    scanf("%d", &key);

    key_idx = linearSearch(arr, key);

    if (key_idx != -1)
    {
        printf("The Key you Searched for (%d) is Present on (%d) index of the array!\nn", key, key_idx);
    }
    else{
        printf("Key You Searched is NOT found in the array!!\n");
    }
    
    return 0;
}