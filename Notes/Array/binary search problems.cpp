// Q1: FIrst and Last position of eleement in sorted array

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n,int target){
    int start = 0; int end = n-1;
    int first=-1, last=-1, mid;

    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]==target){      // code to find first position of element in the array
            first = mid; 
            end = mid - 1;
        }
        else if(target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    start = 0, end = n-1;
    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]==target){      // code to find last position of element in the array
            end = mid; 
            start = mid + 1;
        }
        else if(target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return first, last;

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




// Q2: A target value will be given and you have to find at which index it should lie. (whether it is present in the srr ay or not)

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n,int target){
    int start = 0; int end = n-1;
    int mid;
    int index = n; // next to last position

    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid]==target){
            index = mid;
            break;
            // could also directly return mid;
        }
        else if(target>arr[mid]){
            start = mid + 1;
        }
        else{
            index = mid;
            end = mid - 1;
        }
    }
    return index;
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



// Q3: Finding sqrt of given number. Sqrt(x)

#include<iostream>
using namespace std;

int  sqrt(int x){
    int start = 0, end = x, mid, ans;


    if(x<=1)    // to handle if x = 0 or 1;
        return x;

    while(start<=end){

        mid = start + (end-start)/2;
        
        if(mid*mid == x){      // mid*mid can give integer overflow error
            ans = mid;         // to solve this use mid==x/mid instead
            break;
            // return mid;
        }
        else if(mid*mid > x){
            start = mid + 1;
        }
        else{
            ans = mid;
            end = mid - 1;
        }
    
    }
    return ans;
}


int main(){ 

    int x;
    cout << "What do you wanna find: ";
    cin >> x;

    cout << "Sqare root of " << x << "is " << sqrt(x) << endl;
    return 0;
    
}




// Q4: Peak Index in Mountain Array:

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n){
    int start = 0; int end = n-1;
    int mid, index;

    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){ //Peak Element
            index = mid;
            break;
            // could also directly return mid;
        }
        else if(arr[mid]>arr[mid-1]){  // Right Side Move
            start = mid + 1;
        }
        else{                        // Left side move
            end = mid - 1;
        }
    }
    return index;
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
    // return index of array where peak element is found
    cout << binarySearch(arr,n) << endl;
    return 0;
    
}



// Q5: Find min element in rotated array

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n){
    int start = 0; int end = n-1; int mid;
    int ans = arr[0];

    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]>=arr[0]){      // Left side sorted array
            start = mid + 1;
        }
        else{                      // Right side sorted array   
            end = mid - 1;
            ans = arr[mid];
        }
    }
    return ans;
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
    // return index of array where peak element is found
    cout << binarySearch(arr,n) << endl;
    return 0;
    
}


// Q6: Finding target element inside rotated array:

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n , int target){
    int start = 0; int end = n-1; int mid;
    

    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]==target){      // Found the element
            return mid;
        }
        else if(arr[mid]>target){                      // Left side sorted array   
            if(arr[0]<target && arr[mid]>target){
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        else{                                        // Right side sorted array
            if(arr[mid]<target && arr[end]>target){
                start = mid + 1;
            }
            else
                end = mid - 1;
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
    int target;
    cin >> target; 
    // return index of array where peak element is found
    cout << binarySearch(arr,n, target) << endl;
    return 0;
    
}




// Q7: Kth missing positive integer. // rewatch



// More videos on binary search lec 25/26







