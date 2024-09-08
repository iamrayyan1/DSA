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
    SLL(){
        head = NULL;
    }

    // Insertion at start
    void insertStart(int value){
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
    }

    // Insertion at end
    void insertEnd(int value){
        if(head == NULL){
            head = new Node(value);
        }
        else{
            Node* curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node(value);
        }
    }

    // Insertion at any position
    void insertMiddle(int pos, int value){
        if (pos == 1){
            insertStart(value);
            return;
        }
        
        Node* curr = head;
        for(int i = 1; i < pos - 1 && curr != NULL; ++i){
            curr = curr->next;
        }
        if(curr == NULL){
            cout << "Position out of range!" << endl;
            return;
        }

        Node* temp = new Node(value);
        temp->next = curr->next;
        curr->next = temp;
    }

    // Delete node from start
    void deleteStart(){
        if(head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete node from end
    void deleteEnd(){
        if(head == NULL){
            cout << "List is empty!" << endl;
            return;
        }

        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    // Delete a particular node
    void deleteMid(int pos){
        if(pos == 1){
            deleteStart();
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        for(int i = 1; i < pos && curr != NULL; ++i){
            prev = curr;
            curr = curr->next;
        }

        if(curr == NULL){
            cout << "Position out of range!" << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // Count number of nodes
    int countNode(){
        int count = 0;
        Node* curr = head;

        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }

    // Print the list
    void printList(){
        Node* curr = head;
        while(curr){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    SLL list;
    
    list.insertStart(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertMiddle(2, 25);
    list.printList();
    
    cout << "Deleting start node:" << endl;
    list.deleteStart();
    list.printList();
    
    cout << "Deleting end node:" << endl;
    list.deleteEnd();
    list.printList();

    cout << "Deleting middle node at position 2:" << endl;
    list.deleteMid(2);
    list.printList();
    
    list.insertStart(10);
    list.insertEnd(20);
    cout << "Number of nodes: " << list.countNode() << endl;

}
