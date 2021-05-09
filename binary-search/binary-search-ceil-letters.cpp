#include<iostream>
using namespace std;

int binarySearchCeil(char* arr, int start, int end, int target){
    int res = -1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(arr[mid]<=target){start = mid+1;}
        else if(arr[mid]>target){
            res = mid;
            end = mid-1;
        }            
    }
    return res;
}

int main(){
    char arr[]={'a','b','c','e','i','z'};
    int pos = binarySearchCeil(arr,0,5,'e');
    cout << pos << endl;
}
