#include<iostream>
using namespace std;

int getMax(int arr[], int n){
	int max = arr[0];
	for(int i = 1; i<n; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

void ascendingCountSort(int arr[], int n, int pos){
	int output[n];
	int count[10] = {0};

	for(int i=0; i<n; i++){
		count[(arr[i]/pos)%10]++;
	}

	for(int i=1; i<10; i++){
		count[i] += count[i-1];
	}

	for(int i = n-1; i>=0; i--){
		output[count[(arr[i]/pos)%10] - 1] = arr[i];
		count[(arr[i]/pos)%10]--;
	}

	for(int i=0; i<n; i++){
		arr[i] = output[i];
	}
}


void descendingCountSort(int arr[], int n, int pos){
	int output[n];
	int count[10] = {0};

	for(int i=0; i<n; i++){
		count[(arr[i]/pos)%10]++;
	}

	for(int i=8; i>=0; i--){
		count[i] += count[i+1];
	}

	for(int i = 0; i<n; i++){
		output[count[(arr[i]/pos)%10] - 1] = arr[i];
		count[(arr[i]/pos)%10]--;
	}

	for(int i=0; i<n; i++){
		arr[i] = output[i];
	}
}

void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}

void radixSort(int arr[], int n, bool ascending = true){  // default true
	int max = getMax(arr, n);

	if(ascending){
		for(int pos = 1; max / pos > 0; pos *= 10){
			ascendingCountSort(arr, n, pos);
		}
		cout << "Sorted in Ascending Order: ";
		print(arr, n);
	} 
    else{
		for(int pos = 1; max / pos > 0; pos *= 10){
			descendingCountSort(arr, n, pos);
		}
		cout << "Sorted in Descending Order: ";
		print(arr, n);
	}
}



int main(){
	int arr[12] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};

	// Sorting in ascending order
	radixSort(arr, 12, true);

	// Sorting in descending order
	radixSort(arr, 12, false);

	return 0;
}