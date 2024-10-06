// waiting list
// line




/*
Operation on Queue:
1- Push
2- Pop
3- Front   (starting value)
4- isFull
5- isEmpty
*/

// First in First out  (FIFO)
// or first come first serve


// we would need front and rear pointer that will keep track of first and last element of queue

// Implementation using Arrays
#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == size-1;
    }

    void push(int x){      // at the end
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
        else if(isFull()){
            cout << "Queue Overflow." << endl;
            return;
        }
        else{
            rear += 1;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
    }

    void pop(){       // from the start
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return;
        }
        else{
            if(front==rear){
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = rear = -1;
            }
            else{
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front += 1;
            }
        }
    }

    int start(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

};


int main(){
    Queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.pop();
    q.pop();
    
    int x = q.start();
    if(!q.isEmpty()){
        cout << x << " ";
    }
}



// This method is not too efficent while Implementing using array
// since when we pop the elements, spaces at the start of the array gets empty
// so we can implement circular queue using array.
// if the rear = size - 1(queue is full from the end) and if there are empty spaces at the start of the array due to pop operations then when we will apply push function it will be stored in the starting
// treating the array like a circle

// we will use %(mod) to move rear and front around the array in circle

// Circular Queue

class Queue{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (rear+1)%size == front;    //
    }

    void push(int x){      // at the end
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
        else if(isFull()){
            cout << "Queue Overflow." << endl;
            return;
        }
        else{
            rear = (rear+1)%size;    //
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
    }

    void pop(){       // from the start
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return;
        }
        else{
            if(front==rear){
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = rear = -1;
            }
            else{
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = (front+1)%size;   //
            }
        }
    }

    int start(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

};




// Implementing using Linked List 

class Node{
    public:
        int data;
        Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:
        Queue(){
            front = rear = NULL;
        }

        bool isEmpty(){
            return front==NULL;
        }
        
        void push(int x){
            if(isEmpty()){
                cout << "Pushed " << x << " into the Queue" << endl;
                front = new Node(x);
                rear = front;
                return;
            }
            else{
                rear->next = new Node(x);
                if(rear->next==NULL){
                    cout << "Queue Overflow\n";
                    return;
                }
                cout << "Pushed " << x << " into the Queue" << endl;
                rear = rear->next;
            }
        }

        void pop(){
            if(isEmpty()){
                cout << "Queue Underflow " << endl;
                return;
            }
            else{
                cout << "Popped " << front->data << " out of the Queue" << endl;
                Node *temp = front;
                front = front->next;
                delete temp;
            }
        }

        int start(){
            if(isEmpty()){
                cout << "Queue Underflow " << endl;
                return -1;
            }
            else{
                return front->data;
            }     
        }
// if question has told us the fix size of the queue then just make a int count varaible and increment and decrement it whenever performing push and pop function 

};


int main(){
    Queue q;
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(52);
    q.push(151);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.start();

}


// Queue STL
/*
Operations:
1. Push
2. Pop 
3. Size
4. Front
5. isEmpty
*/

#include<queue>

int main(){
    queue<int> q;
    q.push(5);
    q.push(8);
    q.push(30);
    cout << q.size();
    cout << q.front();
}