#include <iostream>
using namespace std;

int binarySearchBitonicMax(int *arr, int start, int end)
{
    int size = end;
    while (start <= end)
    {
        /* code */
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < size)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid])
                start = mid + 1;
            else if (arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid])
                end = mid - 1;
        }
        else
            break;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 8, 12, 4, 2};
    cout << binarySearchBitonicMax(arr, 0, 5) << endl;
    return 0;
}
