// code

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){

    int start = 0; int end = n-1; int mid;

    while(start<=end){

        mid = (start+end) / 2;   // this might give error of integer overflow
// since 2^31 is what integer can hold max so if for example both start and end have a value of 2^31, so adding them both will exceed the limit hence giving integer overflow error.
// instead use this formula: mid = start + (end - start)/2
        if(arr[mid] == key){
            return mid;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else
            end = end - 1;
    }

    return -1;

}


int main(){

	int arr[1000];
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	cout << "Enter the Elements in the array";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}  

    int key;
    cout << "What do you wanna find: ";
    cin >> key;

    // return index of array where element is found
    cout << binarySearch(arr,n,key) << endl;
    return 0;
    
}