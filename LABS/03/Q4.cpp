#include<iostream>
using namespace std;



class Node{
private:
    int value;
    Node* next;
    Node* prev;
public:
    Node(int data){
        value = data;
        next = NULL;
        prev = NULL;
    }
    friend class DLL;
};

class DLL{
private:
    Node *Head;

public:
    DLL(){
        Head = NULL;
    }

    // Insertion at the start
    void insertionStart(int value){
        // if list doesnt exist
        if(Head==NULL){
            Head = new Node(value);  
        }
        // Already exist
        else{
            Node *temp = new Node(value);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
    }


    // Insertion at the end
    void insertionEnd(int value){
        // edge cases: if list doesn't exist
        if(Head==NULL){
            Head = new Node(value);       // creating first node
        }
        else{
            Node* curr = Head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            Node *temp = new Node(value);
            curr->next = temp;
            temp->prev = curr;   
        }
    }  // we can also solve this easily using tail pointer


    void insertionMiddle(int pos, int value){
        if(pos==0){  // add at the start
            // list exist
            if(Head==NULL){
                Head = new Node(5);
            }
            //exist
            else{
                Node *temp = new Node(5);
                temp->next = Head;
                Head->prev = temp;
                Head = temp;
            }
        }
        else{    // insert at end or middle

            Node* curr = Head;

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
    }

    void deleteEnd(){
        if(Head!=NULL){

            // if 1 node exist
            if(Head->next==NULL){
                delete Head;
                Head = NULL;
            }
            else{
                Node *curr = Head;
                // last node pae leke jao curr ko
                while(curr->next){
                    curr = curr->next;
                }
                curr->prev->next = NULL;
                delete curr;
            }
        }
    }

    // delete start
    void deleteStart(){
        if(Head!=NULL){
            // if only one node exist
            if(Head->next==NULL){
                delete Head;
                Head = NULL;
            }
            else{
                Node *temp = Head;
                Head = Head->next;
                Head->prev = NULL;
            }
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


    // proper code
    void deleteMid(int pos){


        if(pos==1){
            if(Head!=NULL)
                // if only one node exist
                if(Head->next==NULL){
                    delete Head;
                    Head = NULL;
                }
                else{
                    Node *temp = Head;
                    Head = Head->next;
                    Head->prev = NULL;
                }
        }
        else{
            // first going to node that we want to delete
            Node *curr = Head;
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
    }

    void printList(){
        Node* curr = Head;
        while (curr != NULL){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


int main(){
    DLL list;

    list.insertionStart(10);
    list.insertionEnd(20);
    list.insertionEnd(30);
    list.insertionMiddle(2, 25);

    cout << "List after insertions: " << endl;
    list.printList();

    list.deleteStart();  
    list.deleteEnd();   
    list.deleteMid(2);  

    cout << "List after deletions: " << endl;
    list.printList();
}
