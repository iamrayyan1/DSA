#include<iostream>
#include<vector>
using namespace std;


// best way to find TC is by drawing recursive tree

void print(int n){
    if(n==0)
        return;
    cout << n;
    print(n-1);
}

// TC = O(1+n) -> O(n)
// SC = O(n+1) -> O(n)   


// more ways are doing using substituting method



void print(int arr[], int index){
    if(index==1){
        return;
    }
    cout << arr[index];
    print(arr, index-1);
}

// TC = O(n)
// SC = O(n)



int sum(vector<int>arr, int index, int n){
    if(index==n){
        return 0;
    }
    return arr[index] + sum(arr, index+1, n);
}

// TC = O(n)
// SC = O(n^2)



bool  binarySearch(int arr[], int start, int end, int x){
    if(start>end){
        return 0;
    }

    int mid = (start+end)/2;
    
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]>x){
        return binarySearch(arr, mid+1, end, x);
    }
    else
        return binarySearch(arr, start, mid-1, x);
}
// TC = O(logn)
// SC = O(logn)




// IMP
int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
}

// TC = O(n^2)


