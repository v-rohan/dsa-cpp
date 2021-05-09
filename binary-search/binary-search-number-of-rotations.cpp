#include <iostream>
using namespace std;

int findPos(int *arr, int start, int end, int size)
{
    while (start <= end)
    {
        if (arr[start] <= arr[end])
        {
            return start;
        }
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % size;
        int prev = (mid + size - 1) % size;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[start] < arr[mid])
            start = mid + 1;
        else if (arr[end] > arr[mid])
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int pos = findPos(arr, 0, 7, 8);
    cout << "clockwise : " << pos << endl;
    cout << "anti-clockwise : " << 8 - pos << endl;
}