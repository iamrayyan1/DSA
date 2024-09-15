// main use of pointers



// memory manaement

// allocating memory during the run time  

// memory are divided into two parts stack(static) and heap(dynamic)
// stack is small while heap is large

// all functions and main is stored in stack, functions are loaded when they are called and released when they end

// 'new' kewyord is used to store things in heap
// new returns the address of the location where memory is allocated in heap
// syntax: int *ptr = new int    -> address is stored in pointer variable 

// to allocate memory to array
// int *p1 = new int[20]    -> it will return the address of zero index of array

// these pointers that stores the addresses are stored in stack

// heap memory is not removed even when code ends unlike stacks that release the memory as soon as functions and variables are used

// hence we manually have to remove dynamic allocated memory
// to release memory use 'delete' keyword
// delete ptr;       -> syntax: delete pointerName
// to delete array: delete[] p1

// we can access these variables using pointers


#include<iostream>
#include <vector>
using namespace std;

int main(){
    
    // allocate memory for variable
    int *ptr = new int;
    cout << ptr;   // prints address

    // accessing memory
    *ptr = 5;
    cout << *ptr;   // prints 5

    float *ptr2 = new float;
    *ptr2 = 3.6;
    cout << *ptr2;


    int n;
    cout << "Enter the size of Array";
    cin >> n;

    int *p = new int[n];   // allocating memory for array

    // adding values in array 
    for(int i=0; i<n; i++){
        p[i] = i+1;
    }

    // printing array
    for(int i=0; i<n; i++){
        cout << p[i];
    }

    // delete keyword
    delete ptr;
    delete ptr2;
    delete[] p;            
}