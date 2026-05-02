#include <stdio.h>

/*
 * Simple merge sort without pointers or helpers; uses only
 * plain arrays and indices.  The temporary buffer in merge
 * has a fixed maximum size to avoid dynamic allocation.
 */

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100];              /* big enough for example data */

    /* merge the two halves into temp[] */
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    /* copy sorted data back into original array */
    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;   /* midpoint */
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int array[] = {10, 34, 54, 32, 1, 5, 3, 9, 66};
    int n = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
