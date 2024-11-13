#include <iostream>
#include <queue>
using namespace std;

// Q1: Kth smallest Element  - for eg k=4 so 4th smallest

// Method 1: Brute Force
// Sort the array in ascending order and 3rd index would be the 4th smallest element

// Method 2: Use Min heap
// pop first 3 elements
// Then print the top of the heap (4th element)

// Method 3: Use max heap
// compare with top element - agar top element se chota hou to push kerdo and top ko pop kerdo

int kthSmallest(int arr[], int l, int r, int k)
{ // l=starting index, r=ending index

    // max heap
    priority_queue<int> p;

    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

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

int kthLargest(int arr[], int l, int r, int k)
{ // l=starting index, r=ending index

    // min heap
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

// Q3: Sum of element between K1 and K2 element

// Method 1: Sort the array and find sum of elements between k1 to k2 element
// Method 2: Max Heap -
// Create two heaps, one of k1 and other k2

int sumBetweenTwoKth(int A[], int N, int K1, int K2)
{
    priority_queue<int> p1;
    priority_queue<int> p2;

    // insert k1 elements to p1
    for (int i = 0; i < K1; i++)
    {
        p1.push(A[i]);
    }

    // insert k2-1 element into p2
    for (int i = 0; i < K2 - 1; i++)
    {
        p1.push(A[i]);
    }

    // Find k1 smallest element in array
    for (int i = K1; i <= N; i++)
    {
        if (A[i] < p1.top())
        {
            p1.pop();
            p1.push(A[i]);
        }
    }

    // Find K2-1 smallest element in an array
    for (int i = K2 - 1; i <= N; i++)
    {
        if (A[i] < p2.top())
        {
            p2.pop();
            p2.push(A[i]);
        }
    }

    int sum1 = 0, sum2 = 0;

    // Sum of first max heap
    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    // Sum of second max heap
    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}