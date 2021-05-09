#include<iostream>
using namespace std;

int binarySearhFloor(int* arr, int start, int end, int target){
    int res = -1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(arr[mid]==target){res = mid; break;}
        else if(arr[mid]<target){
            res = mid;
            start = mid+1;
        }
        else
            end = mid-1;
    }
    return res;
}

int main(){
    int arr[]={1,2,3,4,8,10,12,19};
    int pos = binarySearhFloor(arr,0,7,11);
    cout << pos << endl;
}
