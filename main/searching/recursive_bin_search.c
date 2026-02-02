#include<stdio.h>
/* INCOMPLETE */
/* Trying to Implement Recursive binary search on a Static Array */

/* Global Array as usual */

int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int n = sizeof(arr) / sizeof(arr[0]);

int recursiveBinSearch(int arr[], int key){
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = ((low + high) / 2);

    if (arr[mid] == key)
    {
        return mid;
    }
    
}