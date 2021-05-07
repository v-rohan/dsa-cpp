#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;

int binarysearch_first(int* arr, int start, int end, int searchItem){
    int firstpos= end+1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==searchItem){
            if(mid<firstpos)firstpos=mid;
            end = mid-1;
        }
        else if(arr[mid]>searchItem){
            end = mid-1;
        }
        else start=mid+1;
    }
    return firstpos;
}

int binarysearch_last(int* arr, int start, int end, int searchItem){
    int firstpos= INT8_MIN;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==searchItem){
            if(mid>firstpos)firstpos=mid;
            start = mid+1;
        }
        else if(arr[mid]>searchItem){
            end = mid-1;
        }
        else start=mid+1;
    }
    return firstpos;
}

int main()
{
    int arr[] = {20, 19, 19, 18, 14, 13, 13, 13, 10};
    sort(arr,arr+9);
    int pos = binarysearch_first(arr, 0, 8, 13);
    if (pos == 9)
        cout << "not found" << endl;
    else{
        cout << "Found first at position: " << pos << endl;
        pos = binarysearch_last(arr,0,8,13);
        cout << "Found last at position: " << pos << endl;
        }
}