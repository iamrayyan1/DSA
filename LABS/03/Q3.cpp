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

    // Inserting Nodes from array
    void insertStart(int arr[], int n){
        for(int i = 0; i < n; i++){
            Node* temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }

   
    void evenOdd(){
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;

        while (curr != NULL){
            int value = curr->value;

            if (value % 2 == 0){
                if (evenStart == NULL){
                    evenStart = curr;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            }
            else{
                if (oddStart == NULL){
                    oddStart = curr;
                    oddEnd = oddStart;
                } 
                else{
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }

        if (evenStart == NULL){
            head = oddStart;
            return;
        }
        if (oddStart == NULL) {
            head = evenStart;
            return;
        }

        evenEnd->next = oddStart;
        oddEnd->next = NULL;

        head = evenStart;
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

    list.evenOdd();

    cout << "Reversed List: ";
    list.printList();     

}
