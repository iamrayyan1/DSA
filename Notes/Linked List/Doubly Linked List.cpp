// Singly Linked List can only go forward
// Doubly Linked list can go both side, left and right
// It stores the address of next and previou Nodes

#include<iostream>
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



// INSERTION AND DELETION:



/*
INSERTION:
1. Start
2. End
3. Middle
*/


// Start: list already exist
Node InsertionStart(Node* Head){       // head is pointing to start of list
    Node *temp = new Node(5);
    temp->next = Head;
    Head->prev = temp;
    Head = temp;


// edge cases for above code: if list doesn't exist
    if(Head==NULL){
        Head = new Node(5);       // creating first node
    }
}


// Insertion at the end
Node InsertionEnd(Node* Head){
    Node* curr = Head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    Node *temp = new Node(5);
    curr->next = temp;
    temp->prev = curr;   

// edge cases for above code: if list doesn't exist
    if(Head==NULL){
        Head = new Node(5);       // creating first node
    }
}



// Proper block for insertion at start
int main(){
    Node *Head = NULL;

    // Insert at start

    // List doesnt exist
    if(Head==NULL){
        Head = new Node(5);       // creating first node
    }
    // Already exist
    else{
        Node *temp = new Node(5);
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
    }

    // print values
    Node *trav = Head;
    while(trav){
        cout << trav->value << " ";
        trav = trav->next;
    }

}




// converting an array into Doubly Linked List(creating list)

// above code for insertion at the end of the list was not efficent.
// we were traversing around the list each time to add element at the end
// a better approach would be to add an pointer variable at the end of the list to save Time.
// Each time we want to access last element of the list we can do it by using that pointer

int main(){
    int arr[] = {1,2,3,4,5};
    Node *head, *tail;
    tail = head = NULL;

    for(int i=0; i<5; i++){
        if(head==NULL){
            head = new Node(arr[i]);
            tail = head;
        }
        else{
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    // print values
    Node *trav = head;
    while(trav){
        cout << trav->value << " ";
        trav = trav->next;
    }
}



// creating Doubly Linked List using recursion

Node* createDLL(int arr[], int index, int size, Node* back){   // back is the address of prev block
    
    if(index==size){
        return NULL;
    }
    
    Node* temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = createDLL(arr, index+1, size, temp);
    return temp;
}

int main(){
    int arr[] = {1,2,3,4,5};
    createDLL(arr, 0, 5, NULL);
}



// Insert at any point
/*
Node *temp = new Node(5);
temp->next = curr->next;
temp->prev = curr;
curr->next = temp;
temp->next->prev = temp;
*/

// position will tell where you want to add the Node
// but this won't work for starting and end case so you have to deal with that
int main(){
    Node* head, *tail;
    int pos = 2;

    if(pos==0){  // add at the start

        // list exist
        if(head==NULL){
            head = new Node(5);
        }
        //exist
        else{
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else{    // insert at end or middle

        Node* curr = head;

        // jisko node ke baad insert kerwana hai waha tak jao
        while(--pos){
            curr = curr->next;
        }

        if(curr->next == NULL){   // if it is the last Node
            Node* temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }
        //insert at middle(imp)
        else{
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }   

    }

    // print
    Node *trav = head;
    while(trav){
        cout << trav->value << " ";
        trav = trav->next;
    }





// DELETION

// first check whether list exist or not

// deletion from start

    if(head!=NULL){

        // if only one node exist
        if(head->next==NULL){
            delete head;
            head = NULL;
        }
        else{
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
        }
    }


// delete at end

    if(head!=NULL){

        // if 1 node exist
        if(head->next==NULL){
            delete head;
            head = NULL;
        }
        else{
            Node *curr = head;
            // last node pae leke jao curr ko
            while(curr->next){
                curr = curr->next;
            }
            curr->prev->next = NULL;
            delete curr;
        }
    }



// delete at any position
/*
Node *curr = head;
while(--pos){
    curr = curr->next;
}
curr->prev->next = curr->next;
curr->next->prev = curr->prev;
delete curr;
*/


// proper code for all cases
    int pos = 2;

    if(pos==1){
        if(head!=NULL){
            // if only one node exist
            if(head->next==NULL){
                delete head;
                head = NULL;
            }
            else{
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
            }
        }
    }
    else{
        // first going to node that we want to delete
        Node *curr = head;
        while(--pos){
        curr = curr->next;
        }

        // delete last node
        if(curr->next==NULL){
            curr->prev->next = NULL;
            delete curr;
        }

        // delete Middle Node
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }


// if we are given to delete pos = 1 (start) we will use diff block
// also if we are told to delete pos = len of node (last element), we will use diff block


// Doubly Linked List application:
/*
1. Undo Redo operation
2. Spotify 
3. 
*/