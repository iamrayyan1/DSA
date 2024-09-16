// Q1: Sort an array

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    
    vector<int>temp(end-start+1);                         // size of vector = end-start+1
    
    int left = start, right = mid+1, index = 0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index] = arr[left];
            index++, left++; 
        }
        else{
            temp[index] = arr[right];
            index++, right++;
        }
    }
    // agar left array mei element bache hai toh
    while(left<=mid){
        temp[index] = arr[left];
        index++, left++;
    }
    // agar right array mei element bache hai toh
    while(right<=end){
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;
    // put these temp vector values in original array
    while(start<=end){
        arr[start] = temp[index];
        start++, index++;
    }

}



void mergeSort(int arr[], int start, int end){

    if(start==end){
        return;
    }

    int mid = start+(end-start)/2;

    mergeSort(arr, start, mid);    // left part
    mergeSort(arr, mid+1, end);    // right part

    // reverse working
    merge(arr, start, mid, end);   // function that will sort and merge the two divided arrays
}


int main(){
    int arr[] = {14, 66, 8, 10, 88, 44};

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0 , 5);

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
}