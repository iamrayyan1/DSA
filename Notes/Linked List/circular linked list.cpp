// first and last node are connected
// it can exist as both singly linked list and doubly linked list

// creation of list is same as the other list
// only additional step would be to join the last and first position

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int value;
        Node *next;

        Node(int data){
            value = data;
            next = NULL;
        }
};

// Q1: Detect loop in linkedlist

// Method 1: storing addresses of each node in an vector and checking if the addresses is repeated or not

bool check(vector<Node*> &visited, Node* curr){
    for(int i=0; i<visited.size(); i++){
        if(visited[i]==curr)
            return 1;
    }
}

bool loop(Node* head){
    Node *curr = head;

    vector<Node*> visited;

    while(curr!=NULL){
        
        if(check(visited, curr)){     // if it gives true value this mean loop is detected
                return 1;
        }
        visited.push_back(curr);
        curr->next;
    }
    return 0;
}


// but above method can give TLE error

// Unordered Map: we can name the index of an array/list anything (key)


// Method 2: Naming each index of array
// if the element doesnt exist in the array it will return 0

bool loop(Node* head){
    Node *curr = head;

    unordered_map<Node*, bool> visited;

    while(curr!=NULL){
        
        if(visited[curr]==1){     // if it gives true value this mean loop is detected
                return 1;
        }
        visited[curr] = 1;
        curr->next;
    }
    return 0;
}

// but above code is using extra space



// Method 3: We can also solve this by slow and fast pointers 

// In this, we will declare two pointers one is a slow pointer which moves 1 node
// at a time and another is a fast pointer which moves two nodes at a time.
// - Eventually, the two pointers would point to the same node hence intersecting
// and proving the list is circular.
// - If it is not then the fast pointer will reach null proving that it is not a circular list


bool loop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;

}




// Q2: Find Length of a loop:

bool loop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            break;
    }

    if(fast==NULL || fast->next==NULL){
        return 0;
    }

    int count = 0;
    slow = fast->next;

    while(slow!=fast){
        count++;
        slow = slow->next;
    }
    return  count;

}