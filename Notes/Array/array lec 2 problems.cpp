#include <iostream>
using namespace std;

// Q1: Search Element in a array

int arr[] = {10,20,7,11,8,4};
int find;
int index = -1;      // initializing index to -1
cout << "What are you looking for: " << endl;
cin >> find;

for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
	if(arr[i] == find){
		index = i;    // storing index of element where the element is found
		break;      // once the element will be found, we will break the loop
	}
}

cout << index;


// creating search function
int search(int arr[], int N; int X){
	for(int i=0; i<N; i++){
		if(arr[i]==X){
			return i;
		}
	}
	return -1;
}



// Q2: Reversing Array
// there is couple of ways to solve this  problem

// creating a new array of the same size and transfering values from one arrray into another
int arr[6] = {6,11,7,4,8,9};
int temp[6];

int i = 5, j = 0;   // j(temp arr) will start from zero index and i(arr) will start from size-1 
while(i>=0){
	temp[j] = arr[i];
	i--;
	j++;
}


// another method is to swap the values within the array with the help of temp variable
// initially first index of arr will set as i and last index as j
// break condition will be until i<j
int arr[6] = {1,2,3,4,5,6};
int i=0, j=5;
while(i<j){
	swap(arr[i], arr[j])   //using biult-in function to swap
	i++;
	j--;
}




// Q3: Finding Second Maximum
// first find the maximum than the second maximum
int arr[7] = {1,2,3,4,5,6,7};
int secondMax = INT_MIN;
int max = arr[0];
for(int i=1; i<7; i++){
	if(arr[i] > ans){
		ans = arr[i]
	}
}
for(int i=0; i<7; i++){
	if(arr[i]!=ans){
		secondMax = max(secondMax, arr[i])    //in biult function that return the maximum value between two values
	}
}




// Q4: Finding Missing Number 
// N elements from 1 to N
// Array of size n - 1
// each array element is unique
// only one element will be missing

// we can solve this by finding sum of n elements
// than finding sum elements inside array
// than subtracting both results to get the missing number

int n;
cout << "Enter the value of N" << endl;
cin >> n;
int arr[n-1];

// Fill in the array
for(int i = 0; i<n-1; i++){
	sum += arr[i]        // sum of elements inside array
}
ans = n*(n+1)/2;       //sum N numbers
cout << ans - sum;



// Q5: Fibonacci Series       0,1,1,2,3,5,8,13,21
// first two elements of the series is fixed that is 0 and 1
// rest can be found by this formula:
// arr[i] = arr[i-1] + arr[i-2];
int arr[100];
int n;
cout << "Enter the nth term" << endl;
cin >> n;

arr[0] = 0;       // initializing first two elements
arr[1] = 1;

for(int i = 2; i < n; i++){
	arr[i] = arr[i-1] + arr[i-2];
}
cout << arr[n-1] << endl;




// Q6: Rotate array by 1 clockwise
// you can solve this creating another array temp
// and transfer array elements like this: arr[i] = arr[i+1]
// but do this until the last index - 1
// because last index of temp will be replaced by arr[0]

// another way to solve this is by working on the same array itself(not creating temp array)
// to do this you would need a temp variable to temporary store the value store the value to retain the array's previous value 

// we can also make a slight change by storing the last index element of array inside temp
// and then going backwards 
int arr[5] = {2,3,11,5,8};
int temp = arr[n - 1];

for(i=n-2; i>=0; i--){     // starting from arr[n-2] 
	arr[i+1] = arr[i]
}
arr[0] = temp;


// slight changes in code for making it do anti-clockwise rotation




// passing array to function
void func(int a[], int n){           // a[] this will name empty, while n contains size of array
	for(int i=0;i<n;i++){				// a[] this is not array rather it's a pointer variable that just carries the address of array
		cout << a[i];               // whole array is passed completely, any changes made inside function will cause change in array permenantly
	}     
}


int main(){
	int arr[5] = {1,2,4,6,5};
	func(arr,5);                       // (arr name, size of array)       

}











