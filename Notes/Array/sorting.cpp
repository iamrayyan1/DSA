// arranging data in proper way

// there are many techniques of sorting
// selection sorting
// bubble sorting
// insertion sort
// merge sort

#include <iostream>
using namespace std;

// SELECTION SORTING


// remember we did a question where you have to find smallest element in the array
// Q1: Return Index of smallest element
int main(){
	int a[5] = {6,8,5,1,9};
	int min = a[0];          // or initilize to INT_MAX
	
	for(int i=1;i<5;i++){
		if(a[i] < min){
			min = a[i];
		}
	}
	cout << "Smallest Number inside array is: " << min << endl;
}


// it is similar to what we do in selection sort. Instead we will use two loops
// It is also similar to pattern printing we did in C
// One loop will run 0 to n-1 times while the other will run 0 to n times exclusive

int main(){
	int arr[6] = {10,4,1,3,2,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	//also can  add for loop to add elements inside array
	for(int i = 0; i < n-1; i++){
		int index = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		swap(arr[i],arr[index]);
	}
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}
// Though this is not the most optimized form.
// Time Complexoty: O(n^2)
// Space Complexity:
// - Auxillary: O(1)
// - Total: O(n)








// BUBBLE SORT:
int main(){
	int arr[1000];     //initializing first so it is count as constant in space comp
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	cout << "Enter the Element in the array";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=n-2; i>=0; i--){
		bool swapped = 0;
		for(int j=0; j<=i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = 1;
			}
		}
		if(swapped==0)
			break;
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}





// Insertion Sort:
 int main(){
	int arr[1000];
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	cout << "Enter the Element in the array";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	for(int i=1; i<n; i++){
		for(int j=i; j>0; j--){
			if(arr[j] < arr[j-1])
				swap(arr[j], arr[j-1]);
			else
				break;
		}
	}

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}	
 }

