
#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
        int value;
        Node *next;
        Node *prev;

        Node(int data){
            value = data;
            next = NULL;
            prev = NULL;
        }
};


// Q1: Remove Duplicate element from the list(sorted form)

// one way is to copy unique elements in array then fill those unique elements back to list

Node *removeDuplicate(Node* head){
    vector<int> ans;
    ans.push_back(head->value);  // filling in the first node
    Node *curr = head->next;

    while(curr){
        if(ans[ans.size()-1] != curr->value){
            ans.push_back(curr->value);
            curr = curr->next;
        }
    }
    curr = head;    // bringing back curr to first node
    int index = 0;
    while(index<ans.size()){    // filling array values in list
        curr->value = ans[index];
        index++;
        curr = curr->next;
    }
    // ending the list
    int size = ans.size();  // checking size of new list
    curr = head;
    while(size--){  // traversing till last element
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}


// another way without using extra space is:
// take two pointers current and next
Node *duplicate(Node *head){
    Node *curr = head->next;
    Node* prev = head;

    while(curr){
        if(curr->value==prev->value){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}





// Q2: Merge two sorted list:

// we can easily solve this by taking extra place by comparing values of two list and then sorting them into a new list

// we can also solve this without taking extra memory

Node* sortTwoList(Node* head1, Node* head2){
    Node *head = new Node(0);       // added this condition two prevent null list case
    Node *tail = head;

    while(head1 && head2){
        if(head1->value <= head2->value){
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;        
        }
        else{
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL; 
        }
        
        if(head1){   // if head1 remains at the end
            tail->next = head1;
        }
        else{  // if head 2 does
            tail->next = head2;
        }
        
        tail = head;   // bringing tail to initial position
        head = head->next;   // moving head to 2nd position since first node contain extra value
        delete tail;  // deleting first node
        return head;  // returning head
    }
}


// Q3: Sort a list which contain 0,1,2

// one way is to traverse through list three times and add first 0, then 1 and then 2 in new list

// another way can be to by counting number of 0, 1 and 2 in the list
// then update node values

Node* sort(Node* head){
    Node* curr = head;
    int count0 = 0, count1 = 0, count2 = 0;

    while(curr){
        if(curr->value==0){
            count0++;
        }
        else if(curr->value==1){
            count1++;
        }
        else{
            count2++;
        }
        curr = curr->next;
    }

    curr = head;
    
    while(count0--){
        curr->value = 0;
        curr = curr->next;
    }
    while(count1--){
        curr->value = 1;
        curr = curr->next;
    }
    while(count2--){
        curr->value = 2;
        curr = curr->next;
    }
    return head;
}