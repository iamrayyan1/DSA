// print array using recursion

#include<iostream>
#include <vector>
using namespace std;

// print array using recursion

void print(int arr[], int n, int index){
    if(index==n){
        return;
    }
    cout << arr[index];
    print(arr, n, index+1);
}
// to print array in reverse place cout statement after the recursive call.

// by passing 2 args
void print(int arr[],int index){
    if(index==0){
        return;
    }
    print(arr, index-1);
    cout << arr[index];
}

int main(){
    int arr[] = {1,3,7,2,7};
    print(arr,5,0);
    print(arr, 4);
}




// Sum of all elements in array
int sum(int arr[], int n, int index){
    if(index==n){
        return 0;
    }
    return arr[index] + sum(arr, n, index+1); 
}

// by passing two args 
int sum(int arr[],int index){
    if(index==-1){
        return 0;
    }
    return arr[index] + sum(arr,index-1); 

}

int main(){
    int arr[] = {1,3,7,2,7};
    sum(arr,5,0);
    sum(arr, 4);
}




// Return Minimum Element
int minimum(int arr[], int n, int index){
    if(index == n-1){
        return arr[index];
    }
    return min(arr[index], minimum(arr, n, index+1));
}


int main(){
    int arr[] = {1,3,7,2,7};
    minimum(arr,5,0);
    minimum(arr, 4, 0);
}




