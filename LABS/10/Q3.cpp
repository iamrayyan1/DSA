// Q4: Merge K sorted Linked List

// Final linked list in sorted order

// Method 1: Brute Force - covered in linked list lecture
// Method 2: Merge Sort - covered in LL

// Method 3: Min Heap - Saare linked list ke saare nodes ko min heap mei daalo phir baahir nikal ke linked list bana lou

// Method 4: Min Heap -  Magar hur linked list mei se sirf first element lou initially(minimum element), phir jo smallest hou usko nikalo aur uske corresponding linked list ka next node lou
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        if (arr[i] != NULL)
            p.push(arr[i]);
    }

    LLNode *root = new LLNode(0); // dummy node
    LLNode *tail = root;

    LLNode *temp;

    while (!p.empty())
    {
        temp = p.top();
        p.pop();
        tail->next = temp;
        tail = tail->next;

        if (temp->next)
        {
            p.push(temp->next);
        }
    }

    return root->next; // Return the merged list without the dummy node
}

int main() // used gpt to create Linked List
{
    const int K = 3;
    LLNode *arr[K];

    // Creating three sorted linked lists
    arr[0] = new LLNode(1);
    arr[0]->next = new LLNode(4);
    arr[0]->next->next = new LLNode(5);

    arr[1] = new LLNode(1);
    arr[1]->next = new LLNode(3);
    arr[1]->next->next = new LLNode(4);

    arr[2] = new LLNode(2);
    arr[2]->next = new LLNode(6);

    LLNode *mergedHead = mergeKsortedLL(arr, K);

    LLNode *temp = mergedHead;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
