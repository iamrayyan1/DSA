// Q3a
#include<iostream>
using namespace std;

class Ticket{
    int *arr;
    int passenger;
    int size = 10;
    int front;
    int rear;

public:
    Ticket(){
        arr = new int[size];
        passenger = 0;
        front = -1;
        rear = -1;
    }

    ~Ticket(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == size-1;
    }

    void push(){
        if(isEmpty()){
            front = rear = 0;
            passenger++;
            arr[0] = passenger;
        }
        else if(isFull()){
            cout << "Queue overflow" << endl;
        }
        else{
            rear++;
            passenger++;
            arr[rear] = passenger;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue underflow" << endl;
        }
        else{
            if(front==rear){
                front = rear = -1;
            }
            else{
                front++;
                passenger--;
            }
        }
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
};


int main() {
    Ticket q;
    for(int i = 0; i < 10; i++){
        q.push();
    }
    cout<<q.peek()<<endl;
    for(int i = 0; i < 5; i++){
        q.pop();
    }
    cout<<q.peek()<<endl;
    for(int i = 0; i < 5; i++){
        q.push();
    }
    cout<<q.peek()<<endl;
    return 0;
}


// b:
// To solve this issue we can implement circular queue allowing full use of available space and preventing wastage of memory.

#include <iostream>
using namespace std;

class Ticket{
    int *arr;
    int passenger;
    int size;
    int front;
    int rear;

public:
    Ticket(){
        size = 10;
        arr = new int[size];
        passenger = 0;
        front = -1;
        rear = -1;
    }

    ~Ticket(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void push(){
        if (isEmpty()){
            front = rear = 0;
            passenger++;
            arr[rear] = passenger;
        }
        else if (isFull()){
            cout << "Queue overflow" << endl;
        }
        else{
            rear = (rear + 1) % size;
            passenger++;
            arr[rear] = passenger;
        }
    }

    void pop(){
        if (isEmpty()){
            cout << "Queue underflow" << endl;
        }
        else{
            if (front == rear){
                front = rear = -1; 
            }
            else{
                front = (front + 1) % size;
            }
        }
    }

    int peek(){
        if (isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    void print(){
        if (!isEmpty()){
            cout << "Queue: ";
            int i = front;
            while(true){
                cout << arr[i] << " ";
                if (i == rear) 
                    break; 
                i = (i + 1) % size;  
            }
            cout << endl;
        }
        else{
            cout << "Queue is empty." << endl;
        }
    }
};

int main() {
    Ticket q;
    for (int i = 0; i < 10; i++){
        q.push();
    }
    q.print();
    for(int i = 0; i < 5; i++){
        q.pop();
    }
    q.print(); 
    for(int i = 0; i < 5; i++){
        q.push();
    }
    q.print(); 
    return 0;
}



// part c

class Node{
private:
    int data;
    Node *next;     
public:
    Node(int value){
        data = value;
        next = nullptr;
    }
    friend class TicketSLL;
};

class TicketSLL{
    int passenger;
    int size;
    int queueSize;
    Node* front;
    Node* rear;

public:
    TicketSLL(){
        size = 10;
        passenger = 0;
        queueSize = 0;
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        return front == NULL;
    }
    bool isFull(){
        return queueSize == size;
    }

    void push(){
        if(isFull()){
            cout << "Queue Overflow" << endl;
        }
        passenger++;
        Node* x = new Node(passenger);
        if(isEmpty()){
            front = x;
            rear = x;
        }
        else{
            rear->next = x;
            rear = x;
        }
        cout << "Passenger: " << x->data << " added to the queue" << endl;
        queueSize++;
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return;
        }
        else{
            Node *temp = front;
            front = front->next;
            if(!front){
                rear = NULL;
            }
            cout << "Passenger: " << temp->data << " removed from the queue" << endl;
            delete temp;
            queueSize--;
        }
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        } 
        return front->data;
    }

    void print(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        else{
            Node* curr = front;
            cout << "Passengers in Queue: " << endl;
            while(curr){
                cout << "Passenger no. " << curr->data << endl;
                curr = curr->next;
            }
        }
    }

};

int main(){
    TicketSLL q;
    for(int i=0; i<10; i++){
        q.push();
    }
    q.print();
    for(int i=0; i<5; i++){
        q.pop();
    }
    q.print();
    for(int i=0; i<5; i++){
        q.push();
    }
    q.print();
}