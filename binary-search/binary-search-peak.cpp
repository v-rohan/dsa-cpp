#include <iostream>
using namespace std;
int binarySearchPeak(int *arr, int start, int end)
{
    int size = end;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < size)
        {
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;
            else if (arr[mid] < arr[mid + 1])
                start = mid + 1;
            else if (arr[mid] < arr[mid - 1])
                end = mid - 1;
        }
        else if (mid==0 && arr[mid]>arr[1])return 0;
        else if (mid==size && arr[mid]>arr[size-1]) return size;
        else break;
    }
    return -1;
}
int main()
{
    int arr[] = {30, 20, 15, 5};
    cout << binarySearchPeak(arr, 0, 4) << endl;
}