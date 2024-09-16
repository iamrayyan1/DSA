// Q3: Reverse the singly linked list
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


    Node* Reverse(Node *curr, Node* prev){
        if(curr==NULL)
            return prev;

        Node* fut = curr->next;
        curr->next = prev;
        return Reverse(fut, curr);
    }

    void reverseList(){
        head = Reverse(head, NULL);
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



int main() {
    SLL list;
 
    int arr[] = {1, 2, 3, 4, 5};
    list.insertStart(arr, 5);

    cout << "Original list: ";
    list.printList();

    list.reverseList();

    cout << "Reversed list: ";
    list.printList();

    return 0;
}