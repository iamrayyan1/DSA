#include<iostream>
using namespace std;

int main(){
	int arr[100];  // to declare datatype name[size]

	/*
	ways of declaring and initializing
	1- int a[5] = {6,8,5,1,9}    // indexing starts from 0 to size-1
	2- int name[] = {3,8,2,9}    // not specifying size
	3- Take input from the user
	4- int a[5] = {8, 4}    // rest of the spaces will be initialize by garbage values
	5- int a[5] = {0}       // all value will be initialize by 0
	
	*/
	
	
	for(int i=0; i<100; i++){
		cout << "a" << i + 1;
		cin >> a[i];            // Taking input from the user
	}
	
	
	// printing the array
	for (int i=0; i<5;i++){
		cout << arr[i] << endl;
	}
	
	
	// continous memory location(address)
	// each byte have a address
	// array stores elements in continous memory location
	// address of an array is the address of first element(arr[0])
	// size of an int is 4 byte
	
	// address of a particular index can be found using the address of zero index
	address = arr + index * size_of_data_type;   // arr gives the address of zeroth index
	
	// printing character type
	char name[5] = {'a', 'c', 'd', 'o', 'i'};    // size of a character is one type
	address = name + index;
	
	
	// find minimum element from the array
	int a[5] = {6,8,5,1,9};
	int min = arr[0];          // or initilize to INT_MAX
	
	for(int i=1;i<5;i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	cout << "Smallest Number inside array is: " << min << endl;
	
	// similar code for maximum element  
	
	
	
	// it stores same type of data type
	// It stores at continous location
	
	
	// size of funtion can be used to print the size of arr, elements.
	int a;
	cout << sizeof(a);
	int arr[5] = {1,2,3,4,5}
	cout << sizeof(arr);   // gives size of array in terms of bytes
	cout << sizeof(arr) / size0f(arr[0]);     // gives number of elements inside array
}



