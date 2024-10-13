// arranging data in proper way

// there are many techniques of sorting
// selection sorting
// bubble sorting
// insertion sort
// merge sort

#include <iostream>
#include<vector>
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





// Radix Sort


int getMax(int arr[], int n){
	int max = arr[0];
	for(int i = 1; i<n; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

void countSort(int arr[], int n, int pos){
	int output[n];
	int count[10] = {0};

	for(int i=0; i<n; i++){
		count[(arr[i]/pos)%10]++;
	}

	for(int i=1; i<10; i++){
		count[i] += count[i-1];
	}

	for(int i = n-1; i>=0; i++){
		output[count[(arr[i]/pos)%10] - 1] = arr[i];
		count[(arr[i]/pos)%10]--;
	}

	for(int i=0; i<n; i++){
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int n){
	int max = getMax(arr, n);

	for(int pos = 1; max/pos>0; pos*=10){
		countSort(arr, n, pos);
	}
}

int main(){
	int arr[6] = {1,24,5,56,76,8};

	radixSort(arr, 6);

	for(int i=0; i<6; i++){
		cout << arr[i] << " ";
	}
}




// shell sort
void shellSort(vector<int> &arr)
{

    int gap = arr.size() / 2;

    while (gap > 0)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
        gap /= 2;
    }
}


// comb sort
void combSort(vector<int> &arr)
{
    float sf = 1.3;
    int gap = arr.size();
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        gap = gap / sf;
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < arr.size(); i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}



// merge sort

void merge(int arr[], int start, int mid, int end){
	vector<int> temp;
	int i = start;
	int j = end;
	int index = 0;

	while(i<=mid && j<=end){
		
		if(arr[i]<arr[j]){
			temp[index] = arr[i];
			i++, index++;
		}
		else{
			temp[index] = arr[j];
			j++, index++;
		}
	}

	while(i<=mid){
		temp[index] = arr[i];
		i++, index++;
	}

	while(j<=end){
		temp[index] = arr[j];
		j++, index++;		
	}

	index = 0;

	while(start<=end){
		arr[start] = temp[index];
		start++, index++;
	}
}

void mergeSort(int arr[], int start, int end){
	if(start==end){
		return;
	}

	int mid = (start+end)/2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);

	merge(arr, start, mid, end);

}

int main(){
	int arr[6] = {1,24,5,56,76,8};

	mergeSort(arr, 0, 5);

	for(int i=0; i<6; i++){
		cout << arr[i] << " ";
	}
}



// Quick Sort
// first element as pivot
int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = high;

	while(i<j){

		do{
			i++;
		}while(arr[i]<=pivot);

		do{
			j--;
		}while(arr[j]>pivot);

		if(i<j)
			swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);
	return j;
}


void quickSort(int arr[], int low, int high){

	if(low>=high){
        return;
    }

	int pivot = partition(arr, low, high);

	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
}

int main(){
	int arr[6] = {1,24,5,56,76,8};

	quickSort(arr, 0, 5);

	for(int i=0; i<6; i++){
		cout << arr[i] << " ";
	}
}



// Partitioning function using the last element as pivot
int partitioning(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low;      
    int j = high - 1;  

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]); 
            i++;
            j--;
        }
    }
    swap(arr[i], arr[high]); 
    return i;
}



// mid as pivot
int partitioning(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int pivot = arr[mid]; 
    int i = low;     
    int j = high;     

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}