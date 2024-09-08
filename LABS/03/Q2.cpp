#include<iostream>
using namespace std;

class Node{
private:
    int value;
    Node* next;
public:
    Node(int data){
        value = data;
        next = NULL;
    }
    friend class SLL;
};


class SLL{
private:
    Node *head;

public:
    SLL() {
        head = NULL;
    }

    // Inserting Nodes from array
    void insertStart(int arr[], int n){
        for(int i = 0; i < n; i++){
            Node* temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }

    // Reverse the linked list
    void reverseList(){
        Node* curr = head;
        Node* prev = NULL;
        Node* fut = NULL;

        while(curr != NULL){
            fut = curr->next; 
            curr->next = prev; 
            prev = curr;       
            curr = fut;
        }
        head = prev;
    }

    // Print the list
    void printList(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    SLL list;
    int arr[] = {1, 2, 3, 4, 5};

    list.insertStart(arr, 5); 
    cout << "Original List: ";
    list.printList();       

    list.reverseList();      
    cout << "Reversed List: ";
    list.printList();     

    return 0;
}
