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



// BUBBLE SORT
    void bubbleSort(){
        if(!head || !head->next){
            return;
        }
        bool swapped;

        do{
            swapped = false;
            Node* curr = head; 
            
            while(curr && curr->next){
                if(curr->value > curr->next->value){
                    swapNodes(curr, curr->next);
                    swapped = 1;
                }
                curr = curr->next;
            }


        }while(swapped);
    }



// SELECTION SORT
    void selectionSort(){
        if(!head || !head->next){
            return;
        }

        Node* curr = head;
        while(curr){
            Node* min = curr;
            Node* temp = curr->next;

            while(temp){
                if(temp->value < min->value){
                    min = temp;
                }

                temp = temp->next;
            }

            if(curr!=min){
                swapNodes(min, curr);
            }
            curr = curr->next;
        }
    }


// INSERTION SORT
    void insertionSort(){
        if(!head || !head->next){
            return;
        }
        Node* temp = head->next;
        while(temp){
            Node* curr = temp;
            while (curr->prev && curr->value < curr->prev->value){
                swapNodes(curr, curr->prev);  
        }
            temp = temp->next;
        }    
    }



// QUICK SORT
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



    // MERGE SORT

    // Split the linked list into two halves
    void split(Node* source, Node** front, Node** back) {
        Node* slow = source;
        Node* fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next; 
                fast = fast->next; 
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL; 
        if (*back != NULL) {
            (*back)->prev = NULL; 
        }
    }

    // Merge two sorted linked lists
    Node* merge(Node* front, Node* back) {
        if (front == NULL) return back;
        if (back == NULL) return front;

        Node* result = NULL;

        if (front->value <= back->value) {
            result = front;
            result->next = merge(front->next, back);
            if (result->next) result->next->prev = result;
            result->prev = NULL;
        } else {
            result = back;
            result->next = merge(front, back->next);
            if (result->next) result->next->prev = result; 
            result->prev = NULL;
        }
        return result;
    }

    Node* mergeSort(Node* node) {
        if (node == NULL || node->next == NULL) {
            return node; 
        }

        Node* front;
        Node* back;

        // Split the list into two halves
        split(node, &front, &back);

        // Recursively sort the two halves
        front = mergeSort(front);
        back = mergeSort(back);

        // Merge the sorted halves
        return merge(front, back);
    }

    // Helper function to start merge sort
    void mergeSortHelper() {
        head = mergeSort(head);
    }




// Radix Sort

    int getMax(){
        Node* temp = head;
        int max = temp->value;
        while(temp){
            if(temp->value > max){
                max = temp->value;
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
            int digit = (curr->value/pos)%10;
            
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
                    newTail = count[i];
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
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};







