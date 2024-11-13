
// Q2: Kth largest Element - for eg k = 3,  so 3rd largest element

// Method 1: Brute Force
// Sort the array in descending order and 2nd index would be the 3rd largest element

// Method 2: Use Max heap
// pop first 2 elements
// Then print the top of the heap (3rd element)

// Method 3: Use Min heap
// First fill first k element into the heap
// Then traverse through the remaining elements in the array
// compare with top element - agar top element se bara hou to push kerdo and top ko pop kerdo

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int> arr, int k)
{

    // min heap
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << k << "th largest element: " << kthLargest(arr, k) << endl;
    return 0;
}

// I used a priority_queue, which functions as a heap.
// Since the question specifically states "Implement a function that finds the k largest elements in an array using a min-heap."
