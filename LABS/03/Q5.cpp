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

    void insertNode(int arr[]){
        Node* tail = NULL;

        for(int i=0; i<5; i++){
            if(Head==NULL){
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

    void sort(){
        bool swapped;
        Node* curr;
        Node* lastSorted = NULL;

        do{
            swapped = false;
            curr = Head;

            while (curr->next != lastSorted){
                if (curr->value > curr->next->value){
                    int temp = curr->value;
                    curr->value = curr->next->value;
                    curr->next->value = temp;

                    swapped = true;
                }
                curr = curr->next;
            }
            lastSorted = curr;
        } while (swapped);
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
    int arr[] = {20, 30, 5, 3, 15};

    list.insertNode(arr); 

    cout << "Original List: ";
    list.printList();       

    list.sort();

    cout << "Sorted List: ";
    list.printList();     

    return 0;
}
