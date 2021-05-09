#include<iostream>
using namespace std;

int binarySearchCeil(int* arr, int start, int end, int target){
    int res = -1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(arr[mid]==target){res = mid; break;}
        else if(arr[mid]>target){
            res = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return res;
}

int main(){
    int arr[]={1,2,3,4,8,10,12,19};
    int pos = binarySearchCeil(arr,0,7,3);
    cout << pos << endl;
}
