#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int temp[high - low + 1];
    int pos = 0;
    while (i <= mid && j <= high)
        if (arr[i] < arr[j])
            temp[pos++] = arr[i++];
        else
            temp[pos++] = arr[j++];
    while (i <= mid)
        temp[pos++] = arr[i++];
    while (j <= high)
        temp[pos++] = arr[j++];
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}