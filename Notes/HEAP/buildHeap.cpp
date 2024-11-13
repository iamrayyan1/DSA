// Optimized method to biuld heap in O(n) time

// step up - comparing to parent (ooper)
// step down  - comparing to children (neeche)  - Heapify

//  if child = i then, parent = (i-1)/2
// if parent = i then, left child = 2i+1 and right child = 2i+2

// start from n/2-1 and go backwards and compare with child nodes (step down)

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
}