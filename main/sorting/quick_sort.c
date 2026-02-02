#include <stdio.h>

/* Sir ka Likhaya hua code me kuch errors thhe to ye GPT ka Version hai 😭*/

int arr[] = {1, 5, 8, 3, 7, 5, 9, 10, 43, 30};

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1)
    {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;

        if (i >= j) break;

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // place pivot in correct position
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        QuickSort(arr, low, mid - 1);
        QuickSort(arr, mid + 1, high);
    }
}

int main()
{
    int n = sizeof(arr) / sizeof(arr[0]); // Yaha pe simply tum array ka size gin ke rakh sakte ho lekin ye thoda fancy or accha method hai

    printf("Initial Array: ==> \t");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    QuickSort(arr, 0, n - 1);

    printf("Sorted Array:  ==> \t");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
