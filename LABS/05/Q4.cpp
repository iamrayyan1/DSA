// Q4: Binary Search

#include<iostream>
#include<vector>
using namespace std;

bool  binarySearch(int arr[], int start, int end, int x){
    if(start>end){
        return 0;
    }

    int mid = (start+end)/2;
    
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]<x){
        return binarySearch(arr, mid+1, end, x);
    }
    else
        return binarySearch(arr, start, mid-1, x);
}

int main(){
    int arr[] = {11,22,33,44,55};
    int target = 44;

    
    bool flag = binarySearch(arr, 0, 4, target);

    if(flag == true){
        cout << "Found";
    }
    else
        cout << "Not Found";
}