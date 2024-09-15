#include<iostream>
#include<vector>
using namespace std;


// Q1: Reverse a linked list

// one way is to first store the linked list in array
// then add the elements in linked list in reverse order4

class Node{
    public:
        int value;
        Node *next;

        Node(int data){
            value = data;
            next = NULL;
        }
};


int main(){
    Node *Head;
    vector<int>ans;
    Node *temp = Head;        // initializing temp to starting position
    while(temp!=NULL){                  // moving from start to end
        ans.push_back(temp->value);
        temp = temp->next;
    }
    int i = ans.size()-1;      // setting i to last index of vector
    temp = Head;  // bringing back temp to starting position
    while(temp!=NULL){      // moving from start to end
        temp->value = ans[i];
        i--;
        temp = temp->next; 
    }          
}



// Variation: Reverse Nodes of the Linked List
// for this we would need curr, prev and future pointer
int main(){
    Node *Head;
    Node *curr = Head, *prev = NULL, *Fut = NULL;
    while(curr){
        Fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Fut;
    }
    Head = prev;       // updating head to start
}


// Variation: Reverse Nodes of Linked List using Recursion
Node* Reverse(Node *curr, Node* prev){
    if(curr==NULL)
        return prev;

    Node* fut = curr->next;
    curr->next = prev;
    return Reverse(fut, curr);
}

int main(){
    Node* head;
    head = Reverse(head, NULL);
}




// Q2: Middle of Linked List
// find middle node of linked list

// count number of nodes
// half the count and move utne places from start
Node* middle(Node* head){
    int count = 0;
    Node *temp = head;

    while(temp){      // moving from start to end to count the nodes
        count++;
        temp = temp->next;
    }
    count /= 2;
    temp = head;           // bringing temp back to start
    while(count--){        // move to the middle of list
        temp = temp->next;
    }
    return temp;   // returning the address of middle element
}
// In above code we had to traverse through array twice





// Concept of Slow and Fast Pointers

// Slow pointer moves slowly as compared to a fast pointer.
// A slow pointer moves one node per loop while a fast pointer moves 2 nodes per loop

Node* Middle(Node *head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}




// Q3: Remove Nth Node from End

// Since we can only go forward in singly linked list so we have to find what is the position of the node from the start
// next we will require two pointers, curr and prev. prev will be used to link prev element to the next elelemt

Node* Remove(Node* Head, int n){
    int count = 0;
    Node* temp = Head;
    while(temp){
        count++;
        temp = temp->next;
    }
    count -= n;  // to find the node that we have to delete from starting

    if(count == 0){  // this code will work if we have to delete first node
        temp = Head;
        Head = Head->next;
        delete temp;
    }

    Node *curr = Head;
    Node *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}
// This won't work properly if you have to delete first element from start(or last element from  end)
// But we can fix this by adding if condition




// Q4: Remove every K Node

// next we will require two pointers, curr and prev. prev will be used to link prev element to the next elelemt
// count variable will tell where you currently are

Node* kRemove(Node* head, int k){
    if(k==1){
        return NULL;
    }

    Node* curr = head, *prev = NULL;
    int count = 1;
    
    while(curr){
        // delete this node
        if(k==count){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        }
        // skip this node
        else{
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return head;
}

 


// Q5: Rotate the list(right side)
 

Node* rotate(Node* head, int k){

    if(head==NULL || head->next==NULL){
        return head;
    }

    int count = 0;   // counting total elements in the list
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }

    k = k % count;
    count -= k;   // which element will be last element in the updated list
    
    Node* curr = head, *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    Node *tail = curr;   // taking tail to last pos
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = head;
    head = curr;        // head pointing to updated first pos
    return head;
}

// there are many edge cases:
// List doesn't exist
// List only have one node
// You are given to rotate more than the size of list -> you can solve this by using % operator


// we can also rotate using an extra array



// Q6: Checking Palindrome: 

// one way is to traverse through the list and add all it's element in the array and then check on array whether it is palindrome or not 

// if you want to solve problem without taking an extra array
// first you will break the list into half then you will reverse the second half of list
// then compare both the parts to check whether it's palindrome or not

bool pal(Node* head){

    if(head->next==NULL){   // 1 node list will be a palindromme
        return 1;
    }

    int count = 0;   // counting total elements in the list
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }

    count /= 2;

    Node* curr = head, *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;   // end of first part

    // reversing second linked list
    Node* front = NULL;
    prev = NULL;
    while(curr){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    // comparing 
    Node* head1 = head;
    Node* head2 = prev;
    while(head1){
        if(head1->value!=head2->value){
            return 0;
        }
        else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return 1;
}