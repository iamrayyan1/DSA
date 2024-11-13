// Heap is a complete Binary Tree
// All levels are completely filled except the last level
// At last level, Nodes should be filled from left side

/*
Types of Heap:
    Max Heap
    Min Heap

Max Heap is CBT and parent node should be greater than equal to child node
Min Heap is CBT and parent node should be less than or equal to child node

for all nodes it should be valid
*/

// The maximum element in a tree would be the root node in the case of Max Heap
// The minimum element in a tree would be the root node in the case of Min Heap.
// We can also find second max element using max heap
// and second min element using min heap

/*
Build Max Heap:
    Implementing using Array
    - Find the node where the new node will be inserted O(n)
    - Maintain the heap property. Comparing with the parent nodes
*/

/*
How to find index of nodes:
 - If Parent child = i
    Then:
    Left child = 2i+1
    Right Child = 2i+2
 - If child index = i
    Then:
    Parent = (i-1)/2
*/

#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;       // total elements in heap
    int total_size; // limit

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insertion
    void insert(int value)
    {
        // space not available
        if (size == total_size)
        {
            cout << "Heap Underflow" << endl;
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        // comparison with parent node
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap" << endl;
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    // Deletion of root node
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1];

        if (size == 0)
            return;

        Heapify(0);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MaxHeap H1(10);
    H1.insert(4);
    H1.insert(14);
    H1.insert(44);
    H1.insert(24);
    H1.insert(1);
    H1.insert(18);
    H1.insert(9);
    H1.insert(44);
    H1.print();
    H1.Delete();
    H1.Delete();
    H1.Delete();
    H1.print();
}
