#include <stdio.h>
#include <stdlib.h>
int comparisions = 0;
int swaps = 0;
void swap(int *a, int *b)
{
    swaps++;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int arr[], int left, int right)
{
    int pivot = arr[(left + right) / 2];
    while (left <= right)
    {
        comparisions++;
        // Find eleemnt on left that should be on the right
        while (arr[left] < pivot)
        {
            // comparisions++;
            left++;
        }
        // Find eleemnt on right that should be on the right
        while (arr[right] > pivot)
        {
            // comparisions++;
            right--;
        }
        // Swap elements and move left and right indices
        if (left <= right)
        {
            comparisions++;
            if (left < right)
            {
                swap(&arr[left], &arr[right]);
            }
            left++;
            right--;
        }
    }
    return left;
}
void quickSort(int arr[], int left, int right)
{
    int index = partition(arr, left, right);
    comparisions += 2;
    if (left < index - 1)
    {
        // Sort Left half
        quickSort(arr, left, index - 1);
    }
    if (index < right)
    {
        // Sort right half
        quickSort(arr, index, right);
    }
}
void printArray(int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, \t", arr[i]);
    }
    printf(" ]");
    printf("\n");
}
int main()
{
    int n, i;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    printArray(arr, n);
    printf("No of comparisions: %d\n", comparisions);
    printf("No of swaps: %d\n", swaps);
    return 0;
}