#include<iostream>
using namespace std;


// linearSearch

int linearSearch(int arr[], int index, int n, int key){
    if(index == n){
        return -1;
    }

    if(arr[index]==key){
        cout << "Found at index " << index << endl;  
        return index;
    }
    else{
        return linearSearch(arr, index+1, n, key);
    }
}


int binarySearch(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key){
        cout << "Found at index " << mid << endl;  
        return mid;        
    }
    else if(arr[mid]<key){
        return binarySearch(arr, mid+1, end, key);
    }
    else{
        return binarySearch(arr, start, mid-1, key);
    }
}

