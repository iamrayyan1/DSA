#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



// Problem 5: Implement Queue using Stack 
/*
1. Push
2. Pop
3. Peek
4. Empty
All operations will have TC of O(1) on average
*/
// will use two stacks

// use stack 1 for pushing
// use stack 2 for popping
// agar stack 2 khali hogaya toh for popping transfer elements from stack 1 to stack 2 then pop

class Queue{
    stack<int> st1;
    stack<int> st2;

    public:
        bool empty(){
            return st1.empty() && st2.empty();
        }
        
        void push(int x){
            st1.push(x);
        }

        int pop(){
            if(empty()){
                return 0;
            }
            else if(!st2.empty()){
                int element = st2.top();
                st2.pop();
                return element;
            }
            else{
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                int element = st2.top();
                st2.pop();
                return element;
            }
        }

        int peek(){   // always check top of stack 2 (similar logic as pop)
            if(empty()){
                return 0;
            }
            if(!st2.empty()){
                return st2.top();
            }
            else{
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                return st2.top();
            }
        }

};



// Problem 6: Implement Stack using Queue
/*
1. Push
2. Pop
3. Top
4. Empty
*/
// we will use two queues

// for Push -> jis queue mei elements hou wahi pae push kero
// for pop -> jo queue empty hai usmei saare elements ko le jao except the last one phir jis queue ke andr element the wahi pop kero last element ko
// push aur pop wahi hoga jaha originally element hoge

class Stack{
    queue<int> q1;
    queue<int> q2;

    public:
        bool empty(){
            return q1.empty() && q2.empty();
        }

        void push(int x){
            if(empty()){
                q1.push(x);   // kisi ko bhi choose ker sakte
            }
            else if(q1.empty()){
                q2.push(x);
            }
            else{
                q1.push(x);
            }
        }

        int pop(){
            if(empty()){
                return 0;
            }
            else if(q1.empty()){
                while(q2.size()>1){
                    q1.push(q2.front());
                    q2.pop();
                }
                int element = q2.front();
                q2.pop();
                return element;
            }
            else{
                while(q1.size()>1){
                    q2.push(q2.front());
                    q1.pop();
                }
                int element = q1.front();
                q1.pop();
                return element;
            }
        }

        int top(){
            // stack khali hou
            if(empty()){
                return 0;
            }
            else if(q1.empty()){
                return q2.back();   // last element
            }
            else{
                return q1.back();
            }
        }
};
