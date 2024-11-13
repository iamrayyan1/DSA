#include <iostream>
#include <queue>
using namespace std;

// Question 1: Height of a Heap(Longest path from root to leaf node)

// Method 1: build tree and find height - O(n)
// Method 2: Use maths to find height.  Log(2)N = Height where N is no of nodes

int heapHeight(int N, int arr[])
{
    if (N == 1) // edge case
        return 1;

    int height = 0;
    while (N > 1)
    {
        height++;
        N /= 2;
    }

    return height;
}

// Question 2: Minimum cost of Ropes

// select 2 smallest ropes
// use min heap - priority queue

int minCost(int arr[], int n)
{

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    int cost = 0;
    while (p.size() > 1)
    {
        int rope = p.top(); // smallest ko nikala
        p.pop();
        rope += p.top(); // 2nd smallest ko nikala
        p.pop();
        cost += rope;
        p.push(rope); // dono ka sum queue mei add kerdia
    }

    return cost;
}

// Q3: Magician and Chocolates

// Search for maximum element
// solve this using max heap

int max(int A, vector<int> &B)
{

    // MAx Heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }

    int maxChoc = 0;

    while (A && (!p.empty()))
    {
        maxChoc += p.top();

        if (p.top() / 2)
        {
            p.push(p.top() / 2);
        }

        p.pop();
        A--;
    }

    return maxChoc;
}

// Q4: Last Stone Weight

// Select two heaviest stones

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> p;

    for (int i = 0; i < stones.size(); i++)
    {
        p.push(stones[i]);
    }

    while (p.size() > 1)
    {
        int weight = p.top();
        p.pop();
        weight -= p.top();
        p.pop();

        if (weight)
        {
            p.push(weight);
        }

        return p.empty() ? 0 : p.top(); // agar empty hou toh return 1 else return top element
    }
}

// Q5: Profit Maximization

// using max heap

int profit(vector<int> &A, int B)
{
    int sum = 0;
    priority_queue<int> p;

    for (int i = 0; i < A.size(); i++)
    {
        p.push(A[i]);
    }

    // sell the ticket to B people
    while (B && !p.empty())
    {
        sum += p.top();

        if (p.top() - 1)
        {
            p.push(p.top() - 1);
        }

        p.pop();
        B--; // ticket sold
    }

    return sum;
}