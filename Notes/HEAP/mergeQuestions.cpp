#include <iostream>
#include <queue>
using namespace std;

// Q1: Merge two binary Max Heap

// Method 1: Pop out all elements from both the heaps and store it into the priority queue O(nlogn)
// Method 2: Store all the elements in an array and then covert the array into a Heap using step down method  O(n)

void Heapify(vector<int> &ans, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && ans[left] > ans[largest])
    {
        largest = left;
    }

    if (right < n && ans[right] > ans[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(ans[largest], ans[index]);
        Heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b)
{
    vector<int> ans;

    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        ans.push_back(b[i]);
    }

    // convert vector into max heap;
    int n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(ans, i, n);
    }

    return ans;
}

// Q2: Is Binary Tree Heap (Max)

// CBT
// Every parent >= its child
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int count(Node *root)
{
    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

bool CBT(Node *root, int index, int total_nodes)
{

    if (!root)
    {
        return 1;
    }
    if (index >= total_nodes)
    {
        return 0;
    }
    return CBT(root->left, 2 * index + 1, total_nodes) && CBT(root->right, 2 * index + 2, total_nodes);
}

bool MaxHeap(Node *root)
{
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;

        if (!MaxHeap(root->left))
            return 0;
    }

    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;

        return MaxHeap(root->right);
    }

    return 1;
}

bool isHeap(struct Node *tree)
{
    // count nodes in the tree
    int num = count(tree);
    // CBT hai yah nahi
    bool ans = CBT(tree, 0, num);
    if (ans == 0)
        return 0;

    // Parent >= child
    return MaxHeap(tree);
}

// Q3: BST to Max Heap

/*
Conditions given in question:
    1. Parent > child
    2. Left Subtree < Right SubTree
Not necesaary ke CBT hou
*/

// Inorder traversal to extract value from bst
// Fill heap following Post Order traversal

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void postOrder(Node *root, vector<int> &ans, int &index)
{
    if (!root)
        return;

    postOrder(root->left, ans, index);
    postOrder(root->right, ans, index);
    root->data = ans[index];
    index++;
}

void convertToMaxHeap(Node *root)
{

    // Inorder Traversal
    vector<int> ans;
    inorder(root, ans);

    // Post order Traversal
    int index = 0;
    postOrder(root, ans, index);
}

// Q4: Merge K sorted Linked List

// Final linked list in sorted order

// Method 1: Brute Force - covered in linked list lecture
// Method 2: Merge Sort - covered in LL

// Method 3: Min Heap - Saare linked list ke saare nodes ko min heap mei daalo phir baahir nikal ke linked list bana lou

// Method 4: Min Heap -  Magar hur linked list mei se sirf first element lou initially(minimum element), phir jo smallest hou usko nikalo aur uske corresponding linked list ka next node lou

class LLNode
{
public:
    int data;
    LLNode *next;

    LLNode(int value)
    {
        data = value;
        next = NULL;
    }
};

class Compare
{
public:
    bool operator()(LLNode *a, LLNode *b)
    {
        return a->data > b->data;
    }
};
// a and b ka order sahi hai?
// Heap ke case mei reverse way mei kaam kerta hai

LLNode *mergeKsortedLL(LLNode *arr[], int K)
{
    // Min Heap
    priority_queue<LLNode *, vector<LLNode *>, Compare> p;

    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL) // Push only non null lists
            p.push(arr[i]);
    }

    LLNode *root = new LLNode(0); // dummy node
    LLNode *tail = root;

    LLNode *temp;

    while (!p.empty())
    {
        temp = p.top();
        p.pop();
        // Append the smallest node to the merged list
        tail->next = temp;
        tail = tail->next;

        // If there's a next node in this list, push it into the heap
        if (temp->next)
        {
            p.push(temp->next);
        }
    }

    return root->next; // Return the merged list without the dummy node
}

// Q5: Merge K sorted Array

// Method 1: Take a single array of size K*K, and then extract all the elements from all K arrays and fill them into the new array
// Then either apply merge sort or heap sort on the new array

// Method 2: Min Heap mei saare elements ko dala phir ek ek kerke bahir nikala

// Method 3: Min Heap - But this time only insert first element (minimum element) from each array.

#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // Min heap to store (value, row index, column index)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

    // Push the first element of each array into the heap
    for (int i = 0; i < K; i++)
    {
        if (!arr[i].empty())
        { // Check to avoid pushing from an empty array
            p.push({arr[i][0], {i, 0}});
        }
    }

    vector<int> ans; // Result vector to store the merged sorted elements

    // Process the heap until it's empty
    while (!p.empty())
    {
        // Get the smallest element from the heap
        auto current = p.top();
        p.pop();

        int value = current.first;
        int row = current.second.first;
        int col = current.second.second;

        // Add the smallest element to the result array
        ans.push_back(value);

        // If there is a next element in the same row, push it to the heap
        if (col + 1 < arr[row].size())
        {
            p.push({arr[row][col + 1], {row, col + 1}});
        }
    }

    return ans;
}
