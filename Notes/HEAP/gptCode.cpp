#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap
{
private:
    vector<int> heap;

    // Helper function to get the parent index
    int getParent(int i)
    {
        return (i - 1) / 2;
    }

    // Helper function to get the left child index
    int getLeftChild(int i)
    {
        return 2 * i + 1;
    }

    // Helper function to get the right child index
    int getRightChild(int i)
    {
        return 2 * i + 2;
    }

    // Function to maintain the min-heap property by "bubbling up" the inserted element
    void heapifyUp(int index)
    {
        while (index != 0 && heap[getParent(index)] > heap[index])
        {
            swap(heap[index], heap[getParent(index)]);
            index = getParent(index);
        }
    }

    // Function to maintain the min-heap property by "bubbling down" the root element
    void heapifyDown(int index)
    {
        int smallest = index;
        int left = getLeftChild(index);
        int right = getRightChild(index);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Function to insert an element into the heap
    void insert(int value)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    // Function to remove and return the root element (minimum element in min-heap)
    int extractMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    // Function to get the minimum element (root) without removing it
    int getMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Function to print the heap
    void printHeap()
    {
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinaryHeap minHeap;

    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(10);

    cout << "Heap elements after insertion: ";
    minHeap.printHeap();

    cout << "Minimum element: " << minHeap.getMin() << endl;

    cout << "Extracted minimum element: " << minHeap.extractMin() << endl;

    cout << "Heap elements after extraction: ";
    minHeap.printHeap();

    return 0;
}
