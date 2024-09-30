
// insertion -> push
// delete -> pop


// push and pop is always from the top
// you can only access the top most data

// Stack is a linear data structure, in which insertion and deletion only allowed at the end/ top of the stack

// when we define a stack as an abstract data type, then we are only instrested in knowing the stack operation from user POV
// we are not interested in implementation part.
// This simply mean, we are not interested in knowing the details, we are only interested in what type of operation we can perform


/*
OPERATIONS:
1. Push -> inserts the element at top
2. Pop -> delete the element from top
3. peak -> gives the top most element present in stack
4. isSize -> tells us the size of stack(total elements in stack)
5. isEmpty -> bool type (tells if stack is empty or not)
*/


// Stack is LIFO (LAST IN FIRST OUT)
// Last data inserted will be the first to be deleted

// Real World example is a pile of plates


// We can implement it using array and Linked List


// OPERATION ON STACK USING ARRAY:

// size is defined 

// array: 2,3,1,5,6

// top pointer -> pointing on the most recent/last element

// In push operation top pointer will move forward
// In pop, pointer will move backward

// if we try to push elements beyond the given size of stack then stack overflows
// if we try to perform pop operation when stack is empty then stack underflows


#include<iostream>
#include<vector>
using namespace std;


// Implement it with array
class Stack{
private:
    int *arr;   // DMA
    int size;
    int top;

public:
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }

    void push(int value){
        if(top==size-1){
            cout << "Stack Overflow";
            return;
        }
        else{
            top++;
            arr[top] = value;
            cout << "Pushed " << value << "into the stack\n";
        }
    }

    void pop(){
        if(top==-1){
            cout << "Stack Underflow";
            return;
        }
        else    
            top--;
            cout << "Popped " << arr[top+1] << "from the stack\n";
            

    }

    int peak(){
        if(top==-1){
            cout << "Stack Underflow";
            return -1;
        }
        else    
            return arr[top];
    }

    bool isEmpty(){
        return top==-1;    // if empty return 1
    }

    int isSize(){
        return top+1;
    }

};


int main(){

    Stack s(5);

    s.push(5);
    s.push(8);
    s.push(6);

    s.pop();
    s.pop();
    s.pop();
    // s.pop();    this would give error since stack is empty

    s.push(5);
    s.push(8);
    s.push(6);

    cout << s.peak() << endl;
    
    s.push(5);
    cout << s.peak() << endl;

    cout << s.isEmpty() << endl;
    cout << s.isSize(); 
    
    // good way to call isPeak
    int value = s.peak();
    if(s.isSize()==0)
        cout << value;   // only print if
}




// IMPLEMENTING STACK USING LINKED LIST

// additional head pointer

// no size restriction

// will use doubly linked list for ease

// or with singly linked list we will insert in the starting rather than ending
// then we won't require head pointer too

// one variable containing size of linked list

class Node{
private:
    int data;
    Node* next;

public:
    Node(int value){
        data = value;
        next = NULL;
    }

    friend class Stack; 
};


class Stack{
private:
    Node* top;
    int size;
public:
    Stack(){
        top = NULL;
        size = 0;        // since size is not a restriction in Linked List
    }

    void push(int value){
        Node *temp = new Node(value);
        if(temp==NULL){
            cout << "Stack Overflow";
        }
        else{
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed" << value << " into the stack";
        }
    }
    // stack will only overflow when heap memory is full

    void pop(){
        if(top==NULL){
            cout << "Stack Underflow";
            return;
        }
        else{
            Node* temp = top;
            cout << "Pushed" << top->data << " into the stack";
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peak(){
        if(top==NULL){
            cout << "Stack is empty";
            return -1;
        }
        else{
            return top->data;
        }
    }

    bool isEmpty(){
        return top==NULL;   // returns 1 if empty
    }

    int isSize(){
        return size;
    }

};


int main(){
    Stack S;
    S.push(6);
    S.push(16);
    S.push(62);

    S.pop();

    cout << S.isSize() << endl;

    cout << S.isEmpty() << endl;

    cout << S.peak() << endl;   // handle edge case using isSize
}



// Stack STL

#include<stack>

int main(){
    stack<int> S;
    S.push(6);
    S.push(16);
    S.push(26);
    cout << S.size() << endl;

    S.pop();
    cout << S.top() << endl;
    cout << S.empty() << endl;
}


// Stack was needed because   
