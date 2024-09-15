#include<iostream>
#include<vector>
using namespace std; 

// Linked list is somewhat similar array
// Array is stored in continous memory location
// Linked list is made up of many Nodes(index)
// But it is not stored continously rather it is scattered around in memory in disorderly form.
// Node contain two variables, data and a pointer variable
// pointer inside node is pointing to the next node. Last node pointer have null value

// Node class representation
class Node{
public:
    int data;
    Node *next;     // next pointer pointing to Node type value

    Node() {}

    Node(int value){
        data = value;
        next = nullptr;
    }
};

// How to create a Node
int main(){
    Node a1;
    a1.data = 4;
    a1.next = nullptr;   

    // but nodes are almost always created dynamically
    Node *head;
    head = new Node();
    head->data = 4;
    head->next = nullptr;

    // initializing using constructors
    Node *head1;
    head1 = new Node(4);


/*
operations:
1. Insertion
2. Deletion
3. Search
4. Update
*/


// INSERTION:  

// at start

    Node *temp;
    temp = new Node(28);
    temp->next = head;   // insert the address to 2 variable(that was previosly first) inside next pointer of node
    head = temp;  // update the head value since the starting location of linked list has changed
    // above case was if the linked list already exist

    // if no node was present than:
    if(head==nullptr){
        head = new Node();
    }
    else{
        // above written block will be used here
        temp = new Node(28);
        temp->next = head; 
        head = temp;
    }






// proper code
    Node *Head = nullptr;
    int arr[5] = {1,2,3,4,5};
    // Insert the Node at beginning and copying the above array elements in list

    for(int i=0; i<5; i++){
    
    // Linked list doesn't exist
        if(Head==nullptr){
            Head = new Node(arr[i]);
        }
    // Linked list already exist
        else{
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    // print the values
    Node *temp = Head;
    while(temp!=nullptr){
        cout << temp->data << " ";
    }
    // output : 5 4 3 2 1




// insertion at the end: 

    // making another pointer "tail" that points at the end
    // head pointer points at start of list and tail pointing at the end of list

    Node *Head, *Tail;
    Tail = Head = nullptr;

    int arr[] = {2,4,6,8,10};
    // adding element to end

    for(int i=0; i<5; i++){

    // list doesn't exist
        if(Head==nullptr){
            Head = new Node(arr[i]);
            Tail = Head;
        }    

    // list exists
        else{
            Tail->next = new Node(arr[i]);    
            Tail = Tail->next;
        }
    }

    // print values
    Node *temp;
    temp = Head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }


}

// TC = O(n)
// SC = O(1)



// using recursion to create Linked List


// using recursion to add note at the end

// Node* is return type since we will be returning addresses
Node* createLinkedList(int arr[], int index, int size){
    if(index==size){
        return nullptr;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index+1, size);
    return temp;
}

int main(){
    Node *Head;
    Head = nullptr;

    int arr[] = {1,2,3,4,5};

    Head = createLinkedList(arr, 0, 4);
}

// T.C = O(n)
// S.C = O(n)



// using recursion to add node at the starting
Node* createLinkedList(int arr[], int index, int size, Node *prev){
    if(index==size){
        return prev;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = prev;
    return createLinkedList(arr, index+1, size, temp);
}

int main(){
    Node *Head;
    Head = nullptr;

    int arr[] = {1,2,3,4,5};

    Head = createLinkedList(arr, 0, 4, nullptr);
}




// insert node at the middle of the list(any position)

int main(){
    Node *Head = nullptr;
    int arr[] = {2,4,6,8,10};

    int x = 3;  // at what index you want to insert the value
    int value = 30;

    Node *temp = Head;
    x--;

    while(x--){
        temp = temp->next;
    };

    Node *temp2 = new Node(value);
    temp2->next = temp->next;
    temp->next = temp2;

    // printing
    temp = Head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }






// VIDEO 2: Delete a Node



// Delete first node:

    // head pointer might have null value(list doesnt exist)
    if(Head!=nullptr){

// first transfering the head pointer to second node since we are deleting the first node
    Node *temp = Head;
    Head = Head->next; 
    delete temp;  // delete variable jisko temp point ker raha hai

    }


// delete last node:
    if(Head!=NULL){
        if(Head->next==NULL){
            Node *temp = Head;
            Head = NULL;
            delete temp;
        }
        else{
            Node *curr = Head;
            Node *prev = NULL;
            while(curr->next!=NULL){
                prev = curr;   // keeping track of 2nd last element too
                curr = curr->next;
            }
            // now you have to make second last node's(now last) next pointer to null 
            prev->next = curr->next;
            delete curr;
        }
    }
    // edge caseS:
    // 1. list should exist  -> add if loop
    // 2. list only contains 1 node(code will not work for this case)
    // these two cases are handled above



// delete a particular node:
    int x = 3; // which node you wanna delete
    if(x==1){
        Node *temp = Head;
        Head = Head->next; 
        delete temp; 
    }
    // create a temp pointer that will travel to that node(you have to move 2 step to reach 3rd node)
    // but you also need prev pointer to join 2nd and 4th node
    Node *curr = Head;
    Node *prev = NULL;
    x--;
    while(x--){
        prev = curr;
        curr = curr->next;   // current ko aagey le jao
    }
    prev->next = curr->next;
    delete curr;

    // edge cases:
    // 1. If you are asked to delete first node;  
    // this would work if you want to delete last element
}


// delete a particular code using recursion 
Node* deleteNode(Node* curr, int x){
    if(x==1){
        Node *temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next, x-1);
    return curr;
}



// delete without Head pointer -> deleting the next node after copying the data into the prev node
/*
Node* temp = curr->next;
curr->data = temp->data;
curr->next = temp->next;
delete temp;
*/

// T.C to delete 1st node: O(1)
// T.C to delete particular node if ref is given: O(1) 
// T.C to delete last element: O(n)



// Singly Linked List can go only forward since we only know address of next element
// With Doubly linked list we can move on both sides since we have both the addresses
