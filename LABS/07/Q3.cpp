#include<iostream>
using namespace std;


class Node{
    int score;
    string name;
    Node* next;

public:
    Node(int value, string n){
        name = n;
        score = value;
        next = NULL;
    }

    friend class LinkedList;
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;

    }

    void insertNode(int score, string name){
        Node* temp = new Node(score, name);
        if(head == NULL){
            head = temp;
        }
        else{
            Node* curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    int getMax(){
        Node* temp = head;
        int max = temp->score;
        while(temp){
            if(temp->score > max){
                max = temp->score;
            }
            temp = temp->next;
        }
        return max;
    }

    Node* countSort(int pos){
        Node* count[10] = {NULL};
        Node* countTails[10] = {NULL};

        // first for loop 
        Node *curr = head;
        while(curr){
            int digit = (curr->score/pos)%10;
            
            if(!count[digit]){
                count[digit] = curr;
                countTails[digit] = curr;
            }
            else{
                countTails[digit]->next = curr;
                countTails[digit] = curr;
            }
            curr = curr->next;
        }

        // Rebuild the list by concatenating all the buckets in order 
        Node* newHead = NULL;
        Node* newTail = NULL;

        for(int i=0; i<10; i++){
            if(count[i]){
                if(!newHead){
                    newHead = count[i];
                    newTail = countTails[i];
                }
                else{
                    newTail->next = count[i];
                    newTail = countTails[i];
                }
            }
        }

// terminatging the list
        if(newTail){
            newTail->next = NULL;
        }

        return newHead;



    }



    void radixSort(){
        if(!head || !head->next){
            return;
        }

        int max = getMax();

        for(int pos = 1; max/pos>0; pos*=10){
            head = countSort(pos);
        }

    }

    


    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->score << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList list;

    list.insertNode(90, "Ayan");
    list.insertNode(60, "Ali");
    list.insertNode(70, "Sara");
    list.insertNode(50, "Zara");
    list.insertNode(40, "Jeena");

    list.print();

    list.radixSort();

    list.print();


}