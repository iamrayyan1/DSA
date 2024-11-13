/*
Array given
1. Convert into Max Heap
2. Remove/Extract Top(root) element - it will be the maximum element of the array
3. Apply Heapify to maintain Max Heap property
4. Repeat the process 2-3 until Heap is empty
Array is sorted in Descending order
But this method requires extra array space where we will be storing the sorted elements.

Instead we can store the top element(sorted element) at the end of the current array to save space
Then Apply Heapify from first to size-1 elements
update size
Array is sorted in Ascending order
*/

#include <iostream>
using namespace std;

void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    // step down
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void sortArray(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}

void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
    printHeap(arr, 10);
}