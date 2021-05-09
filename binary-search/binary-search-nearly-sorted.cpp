#include<iostream>
using namespace std;

int binarysearchNearlySorted(int* arr, int start, int end, int target ){
    int size = end;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target)return mid;
        else if(mid+1<size){
            if(arr[mid+1]==target)return mid+1;
        }
        else if(mid-1>=0){
            if(arr[mid-1]==target) return mid-1;
        }
        if(arr[mid]>target && mid-2>=0) end = mid - 2;
        if(arr[mid]<target && mid+2<=size) start = mid+2;
    }
    return -1;
}

int main(){
    int arr[] = {5,10,30,20,40};
    int a = binarysearchNearlySorted(arr,0,4,5);
    cout << a <<endl;
}