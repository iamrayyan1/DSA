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
        next = nullptr;
        prev = nullptr;
    }
    friend class DLL;
};

class DLL{
private:
    Node *Head;

public:
    DLL(){
        Head = nullptr;
    }

    void insertNode(int arr[], int size){
        Node* tail = nullptr;

        for(int i=0; i<size; i++){
            if(Head == nullptr){
                Head = new Node(arr[i]);
                tail = Head;
            }
            else{
                Node *temp = new Node(arr[i]);
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }
    }

    void swapNodes(Node* node1, Node* node2){
        if (node1 == node2)
            return;

        Node* prev1 = node1->prev;
        Node* next1 = node1->next;
        Node* prev2 = node2->prev;
        Node* next2 = node2->next;

        if (prev1)
            prev1->next = node2;
        else
            Head = node2; // Update head if node1 was the head

        if (next1)
            next1->prev = node2;

        node2->prev = prev1;
        node2->next = next1;

        if (prev2)
            prev2->next = node1;

        if (next2)
            next2->prev = node1;

        node1->prev = prev2;
        node1->next = next2;
    }

    void sort(){
        if (!Head)
            return;

        bool swapped;
        Node* current;
        Node* lastSorted = nullptr;

        do {
            swapped = false;
            current = Head;

            while (current->next != lastSorted){
                if (current->value > current->next->value){
                    swapNodes(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            lastSorted = current; // Mark the last sorted node

        } while (swapped);
    }

    void removeDuplicates(){
        if (!Head)
            return;

        Node* current = Head;

        while (current->next != nullptr){
            if (current->value == current->next->value){
                Node* next_next = current->next->next;
                delete current->next;
                current->next = next_next;

                if (next_next != nullptr)
                    next_next->prev = current;
            } else {
                current = current->next;
            }
        }
    }

    void printList(){
        Node* curr = Head;
        while (curr != nullptr){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main(){
    DLL list;
    int arr[] = {20, 30, 5, 3, 15};
    int size = sizeof(arr)/sizeof(arr[0]);

    list.insertNode(arr, size); 

    cout << "Original List: ";
    list.printList();       

    // Sorting the list
    list.sort();

    cout << "Sorted List: ";
    list.printList();     

    // Removing duplicates (if needed)
    list.removeDuplicates();

    cout << "List after removing duplicates: ";
    list.printList();

    return 0;
}
