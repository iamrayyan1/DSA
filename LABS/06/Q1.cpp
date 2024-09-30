#include<iostream>
#include<vector>
using namespace std;


class Stack{
private:
    int *arr;   
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
            cout << "Pushed " << value << " into the stack\n";
        }
    }

    void pop(){
        if(top==-1){
            cout << "Stack Underflow";
            return;
        }
        else    
            top--;
            cout << "Popped " << arr[top+1] << " from the stack\n";
    }

    int peek(){
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

    void printStack() {
        if (isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    ~Stack() {
        delete[] arr;
    }

};


void evenOdd(Stack &original, Stack &even, Stack &odd) {
    while (!original.isEmpty()) {
        int value = original.peek();
        original.pop();

        if (value % 2 == 0) {
            even.push(value);
        } else {
            odd.push(value);
        }
    }
}

int main(){
    Stack S(6);
    Stack Even(6);
    Stack Odd(6);
    
    S.push(5);
    S.push(10);
    S.push(16);
    S.push(25);
    S.push(51);
    S.push(15);

    S.printStack();

    evenOdd(S, Even, Odd);

    Even.printStack();
    Odd.printStack();

}
