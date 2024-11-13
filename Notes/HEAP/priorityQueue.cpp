/*
A **priority queue** is a special type of data structure in which elements are stored based on their priority.
Unlike a regular queue where elements are processed in a first-in, first-out (FIFO) order, a priority queue processes elements in order of their priority.
The highest-priority elements are processed before the lower-priority ones, regardless of their insertion order.

### Key Characteristics of a Priority Queue:
1. **Priority-Based Processing**: Each element has a priority associated with it, and the element with the highest priority is removed first.
2. **Dynamic Nature**: Elements can be added or removed at any time, and the priority queue adjusts itself to maintain the correct ordering.
3. **Flexible Ordering**: Priority queues can be implemented as either **max-heaps** (where the highest-priority element is the largest value) or
**min-heaps** (where the highest-priority element is the smallest value).

### Common Operations in a Priority Queue:
1. **Insertion (`push` or `enqueue`)**: Adds an element to the priority queue.
2. **Deletion (`pop` or `dequeue`)**: Removes the highest-priority element.
3. **Peek (`top` or `peek`)**: Retrieves the highest-priority element without removing it.

### How Priority Queues Are Implemented
Priority queues are commonly implemented using a **binary heap** (a complete binary tree). This ensures efficient insertion and removal of the highest-priority element.
Binary heaps provide:
- **`O(log n)`** time complexity for insertion and removal operations.
- **`O(1)`** time complexity for retrieving the highest-priority element.

### Types of Priority Queues
1. **Max-Priority Queue**: The element with the highest value has the highest priority.
For example, in a task scheduling system where higher numbers represent higher priorities, the task with the largest value is processed first.
2. **Min-Priority Queue**: The element with the lowest value has the highest priority.
This is useful in scenarios like Dijkstra's shortest path algorithm, where nodes with the smallest distances are prioritized.

### Real-World Applications of Priority Queues
1. **Task Scheduling**: Operating systems use priority queues to manage tasks, where higher-priority tasks are executed before lower-priority ones.
2. **Pathfinding Algorithms**: Algorithms like Dijkstra's shortest path algorithm use priority queues to prioritize nodes with the shortest distance.
3. **Huffman Coding**: Used in data compression, priority queues help build Huffman trees by prioritizing nodes with the lowest frequency.

### Example Code (C++)

Here's how you might use a priority queue in C++ using the STL `priority_queue` library:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxPQ;  // Max-priority queue (default behavior)
    priority_queue<int, vector<int>, greater<int>> minPQ; // Min-priority queue

    // Inserting elements into max-priority queue
    maxPQ.push(10);
    maxPQ.push(30);
    maxPQ.push(20);

    cout << "Max-Priority Queue (highest priority element first):" << endl;
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";  // Display highest-priority element
        maxPQ.pop();                 // Remove highest-priority element
    }

    cout << "\nMin-Priority Queue (lowest priority element first):" << endl;
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);

    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";  // Display highest-priority element in min-heap
        minPQ.pop();                 // Remove highest-priority element
    }

    return 0;
}
```

### Explanation
In the example:
- `maxPQ` is a max-priority queue (the default in C++'s STL `priority_queue`).
- `minPQ` is a min-priority queue, created by specifying `greater<int>` as the comparison function.

### Summary
Priority queues are versatile data structures that manage elements based on priority rather than insertion order.
Their efficiency and adaptability make them essential in many computer science and real-world applications.
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> maxPQ;                            // Max-priority queue (default behavior)
    priority_queue<int, vector<int>, greater<int>> minPQ; // Min-priority queue

    // Inserting elements into max-priority queue
    maxPQ.push(10);
    maxPQ.push(30);
    maxPQ.push(20);

    cout << "Max-Priority Queue (highest priority element first):" << endl;
    while (!maxPQ.empty())
    {
        cout << maxPQ.top() << " "; // Display highest-priority element
        maxPQ.pop();                // Remove highest-priority element
    }

    cout << "\nMin-Priority Queue (lowest priority element first):" << endl;
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);

    while (!minPQ.empty())
    {
        cout << minPQ.top() << " "; // Display highest-priority element in min-heap
        minPQ.pop();                // Remove highest-priority element
    }

    return 0;
}