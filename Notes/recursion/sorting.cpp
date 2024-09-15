#include<iostream>
#include<vector>
using namespace std;


// merge sort (divide & merge)

void merge(int arr[], int start, int mid, int end){
    vector<int>temp(end-start+1);                         // size of vector = end-start+1
    int left = start, right = mid+1, index = 0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index] == arr[left];
            index++, left++; 
        }
        else{
            temp[index] == arr[right];
            index++, right++;
        }
    }
    // agar left array mei element bache hai toh
    while(left<=mid){
        temp[index] = arr[left];
        index++, left++;
    }
    // agar right array mei element bache hai toh
    while(right<=end){
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;
    // put these temp vector values in original array
    while(start<=end){
        arr[start] = temp[index];
        start++, index++;
    }

}
 

void mergeSort(int arr[], int start, int end){

    if(start==end){
        return;
    }

    int mid = start+(end-start)/2;

    mergeSort(arr, start, mid);    // left part
    mergeSort(arr, mid+1, end);    // right part

    // reverse working
    merge(arr, start, mid, end);   // function that will sort and merge the two divided arrays
}


// TC = O(n*logn)
// SC = O(n)


// to find SC you can draw stack


// splitting problem into sub-problems


// Quick Sort   -> restudy

/* 
1. find Pivot element and us ko correct position mei dalo
2. pivot ke left mei chote or equal hoge, aur bade right side
3. Same steps to be repeated on left and right side
*/
int partition(int arr[], int start, int end){
    int pos = start;
    for(int i=start; i<=end; i++){
        if(arr[i]<=arr[end]){
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos - 1;
}

void quickSort(int arr[], int start, int end){

    if(start<=end){
        return;
    }

    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot-1);   // left
    quickSort(arr, pivot+1, end);     // right

}

int main(){
    int arr[] = {10,3,4,1,5,6,3,2,11,9};
    quickSort(arr, 0 ,9);
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
}

// TC = O(nlogn)



// chat gpt answer for quick sort

/*
Quicksort is a popular sorting algorithm that follows the divide-and-conquer paradigm. It's efficient for large datasets and generally performs well with an average time complexity of \(O(n \log n)\).

Here’s the algorithm for Quicksort:

### Algorithm

1. **Choose a Pivot**: Select an element from the array as the pivot. The pivot can be chosen in different ways:
   - First element
   - Last element
   - Middle element
   - Random element

2. **Partition the Array**: Reorder the array so that:
   - All elements less than the pivot are on its left.
   - All elements greater than the pivot are on its right.
   - The pivot is now in its final position.

3. **Recursively Apply Quicksort**:
   - Recursively apply the above steps to the sub-arrays formed by dividing the array at the pivot.

4. **Base Case**: If the array has one or zero elements, it is already sorted.

### Example
Let’s sort an array: `[3, 6, 8, 10, 1, 2, 1]`

1. **Choose a Pivot**:
   - Suppose we choose the last element `1` as the pivot.

2. **Partitioning**:
   - Rearrange the array so that all elements less than `1` are on its left, and all greater elements are on its right. After partitioning, the array might look like this: `[0, 1, 1, 10, 8, 6, 3]` with `1` in its correct position.

3. **Recursive Quicksort**:
   - Apply Quicksort to the left and right sub-arrays: `[3, 6, 8, 10]` and `[2, 1]`.

4. **Base Case**:
   - Continue recursively until each sub-array has only one element, at which point the recursion stops.

### Pseudocode

Here’s how the Quicksort algorithm looks in pseudocode:

```plaintext
function quicksort(array, low, high) is
    if low < high then
        pivot_index := partition(array, low, high)
        quicksort(array, low, pivot_index - 1)  // Recursively sort the left sub-array
        quicksort(array, pivot_index + 1, high) // Recursively sort the right sub-array

function partition(array, low, high) is
    pivot := array[high]   // Choose the last element as pivot
    i := low - 1           // Index of smaller element
    
    for j := low to high - 1 do
        if array[j] <= pivot then
            i := i + 1
            swap array[i] with array[j]
    
    swap array[i + 1] with array[high]  // Place pivot in its correct position
    return i + 1    // Return the pivot index
```

### CPPP Implementation

Here's how you could implement Quicksort in CPP:

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that places the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the correct place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);

    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}


# Example usage
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quicksort(arr, 0, n - 1)
print("Sorted array:", arr)
```

### Time Complexity

- **Best Case**: \(O(n \log n)\) – Occurs when the pivot divides the array into two equal halves.
- **Average Case**: \(O(n \log n)\) – On average, the pivot will be reasonably close to the middle.
- **Worst Case**: \(O(n^2)\) – Occurs when the pivot is the smallest or largest element repeatedly, leading to highly unbalanced partitions.

### Space Complexity
- **In-place Version**: \(O(\log n)\) due to the recursive stack space.

### Conclusion
Quicksort is efficient for large datasets and widely used in practice, despite its worst-case time complexity. Choosing a good pivot (like a random element) can help avoid the worst-case scenario.
*/




