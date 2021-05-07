#include <iostream>
#define endl "\n"
using namespace std;

int binarysearch(int *arr, int start, int end, int query)
{
    if (start <= end)
    {
        int mid = start + (end-start)/2;
        if (arr[mid]==query) return mid;
        else if(arr[mid]<query) return binarysearch(arr,start,mid-1,query);
        else return binarysearch(arr,mid+1,end,query);
    }
    else
        return -1;
}
int main()
{
    int arr[] = {20, 19, 19, 18, 14, 13, 12, 11, 10};
    int pos = binarysearch(arr, 0, 8, 13);
    if (pos == -1)
        cout << "not found" << endl;
    else
        cout << "Found at position: " << pos << endl;
}