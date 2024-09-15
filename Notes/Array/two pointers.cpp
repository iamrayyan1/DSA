// Q1: Segregate 0 and 1

// 1,0,1,0,1,0 convert this into: 0,0,0,1,1,1

// this can be solve by sorting(selection,insertion,bubble) -> time comp would be O(n^2)

// Another method would using vector library's sort function. -> T.C would be O(N*log(n))

// another way is:

// make two variables count0 and count1.
// increment these variables values when they found 0 and 1 respectively

#include<iostream>
using namespace std;

int main(){
    int count0 = 0;
    int count1 = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count0++;
        }
        else
            count1++;
    }
    for(int i=0; i<count0; i++){
        arr[i] = 0;
    }
    for(int i=count0; i<n; i++){
        arr[i] = 1;
    }
}

// T.C of above code is O(3n)-> O(n)


// In this approach you are running loops multiple times. 

// Using two pointers you can get results only by going over the array once
// we will create two pointer variables, one pointing at start and the other at the end
// stopping condition would be while(start<end) 
int main(){
    int arr[100];
    int n;
    int start =0, end = n-1;;
    while(start<end){
        if(arr[start]==0){
            start++;
        }
        else{
            if(arr[end]==0){
                swap(arr[start], arr[end]);
                start++, end--;
            }
            else
                end--;
        }
    }
}   
// T.C of this is: O(n)




// Two Sum: Any two elements in the array that sum up to given target

// you can solve this by using loop inside a loop.
// T.C of this would be O(n^2)
int main(){
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                return i,j;
            }
        }
    }
}


// this is not the best approach
// another method can be by applying binary search
// this can only be applied in sorted array
int main(){
    for(int i=0; i<n-1; i++){   
        int x = target - arr[i];
        int start = i+1;
        int end = n-1;

        // apply binary search here
    }
}
// T.C for this code will be O(N.log(n))





// another method is by using two pointers
// start will go -> always , and end will go <- always
// this can only be applied in sorted array
int main(){
    int start=0, end = n-1;
    while(start<end){
        if(arr[start]+arr[end]== target){
            return 1;
        }
        else if(arr[start]+arr[end]<target)
            start++;
        else
            end--;
    }
    return 0;
}
// T.C= O(n)






//Q3: Pair with given difference. Similar to above question but instead of adding, we will subtract two elements to get ans

// we can do this using i, j loops

// Another method would two pointers or binary search but both would only be applicable if array is sorted


// Binary Search
// A-B = 45
// A = 45 + B
int main(){





}
// T.C would be O(Nlog(n))


// Two Pointer
// but this time it would diffrent from 2 sum approach
// this time we will place start variable at arr[0] and end variable at arr[1]
// at this time start and end variable can move both sides -> only
// stopping condition would be while(end<n)
int main(){
    int start =0, end = 1;
    while(end<n){
        if(arr[end]-arr[start]==target)
            return 1;
        else if(arr[end]-arr[start]<target){
            end++;
        }   
        else
            start++;
    }
    return 0;
}
// T.C = O(n)




// Suffix Preffix, KADANE'S ALgorithm

