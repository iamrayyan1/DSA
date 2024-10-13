#include<iostream>
using namespace std;

// linear Search
int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            cout << "Found " << endl;
            return i;
        }
    }
    return -1;
}


// binary Search
int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;

    int mid = start+(end-start)/2;

    while(start<=end){
        if(arr[mid] == key){
            cout << "Found " << key << " at " << mid << endl;
            return mid; 
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}


int interpolationSearch(int arr[], int n, int key){
    int start = 0;
    int end = n - 1;

    if(n == 0) 
        return -1;

    while(start <= end && arr[start] <= key && arr[end] >= key){
        if(arr[end] == arr[start]){
            if (arr[start] == key){
                return start;  
            }
            return -1; 
        }

        int pos = start + ((key - arr[start]) * (end - start) / (arr[end] - arr[start]));

        if(arr[pos] == key){
            cout << "Found at index " << pos << endl;  
            return pos;  
        }
        else if(arr[pos] < key){
            start = pos + 1;  
        }
        else{
            end = pos - 1;  
        }
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

    cout << binarySearch(arr,n,key) << endl;
    cout << linearSearch(arr, n, key) << endl;
    cout << interpolationSearch(arr, n, key);
    return 0;
    
}
