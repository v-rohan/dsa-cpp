#include <stdio.h>
#include <stdlib.h>
int c = 0;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
        c++;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
        c++;
    }
    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
    Output:
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printf("\nSorted array is :\n");
    printArray(arr, n);
    printf("\nNo of Comparisons is : %d \n", c);
    printf("\n");
}
