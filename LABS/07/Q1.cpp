#include<iostream>
using namespace std;

class Node{
    int value;
    Node* next;
    Node* prev;

public:
    Node(int data){
        value = data;
        next = NULL;
        prev = NULL;
    }
    friend class LinkedList;
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;

    }

    void insertNode(int arr[], int size){
        Node* tail = NULL;

        for(int i=0; i<size; i++){
            if(head == NULL){
                head = new Node(arr[i]);
                tail = head;
            }
            else{
                Node* temp = new Node(arr[i]);
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }
    }

    void swapNodes(Node* node1, Node* node2){
        Node* prev1 = node1->prev;
        Node* next1 = node1->next;
        Node* prev2 = node2->prev;
        Node* next2 = node2->next;

        if(prev1){
            prev1->next = node2;
        }
        else{
            head = node2;
        }

        if(next1){
            next1->prev = node2;
        }

        if(prev2){
            prev2->next = node1;
        }
        else{
            head = node1;
        }

        if(next2){
            next2->prev = node1;
        }

        // Swap node1 and node2 pointers
        node1->prev = prev2;
        node1->next = next2;
        node2->prev = prev1;
        node2->next = next1;
    }


    Node* partition(Node* low, Node* high){
        int pivot = high->value;  
        Node* i = low->prev;      

        for(Node* j = low; j != high; j = j->next){
            if(j->value <= pivot){
                if(i == NULL){
                    i = low; 
                }
                else{
                    i = i->next; 
                }
                swapNodes(i, j);
            }
        }

        if(i == NULL){
            i = low;
        }
        else{
            i = i->next;
        }

        swapNodes(i, high);
        return i; 
    }



    void quickSort(Node* low, Node* high){

        if (high != NULL && low != high && low != high->next){
            Node* pivot = partition(low, high);

            quickSort(low, pivot->prev);
            quickSort(pivot->next, high);
        }
    }

    void quickSortHelper(){
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        Node* tail = curr;

        quickSort(head, tail);
    }




    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList list;
    int arr[7] = {10, 7, 8, 9, 1, 5, 3};

    list.insertNode(arr, 7);
    cout << "Original list: ";
    list.print();

    list.quickSortHelper();

    cout << "Sorted list: ";
    list.print();

    return 0;
}