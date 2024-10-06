#include<iostream>
#include<vector>
using namespace std;

#include<queue>
// Print all element in queue

// Approach 1: Removing elements fron Queue

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop(); 
    }
}


// Approach 2: S.C = O(n). Without Removing elements from Queue by storing in another vector

void print(queue<int> q){
    vector<int> ans;
    while(!q.empty()){
        cout << q.front() << " ";
        ans.push_back(q.front());
        q.pop(); 
    }
    for(int i=0; i<ans.size(); i++){
        q.push(ans[i]);
    }    
}

// Approach 3: S.C = O(1). Without Removing elements from Queue. Without using extra space
void print(queue<int> q){
    int n = q.size();
    while(n--){
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}


#include<stack>
// Problem 2: Queue Reversal
// Queue ke elements ko stack mei daalo phir bahir nikal ke queue mei daalo -> O(n) SC and TC
void reverse(queue<int> q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}


// Problem 3: Reverse first K element of queue
// 1. Push first K elements of queue in stack
// 2. Store the size of queue
// 3. Push all element of stack into queue
// 4. push first n of queue at last

void reverseKelements(queue <int> q, int k){
    stack<int> st;

    // 1. Push first K elements of queue in stack
    while(k--){
        st.push(q.front());
        q.pop();
    }

    // 2. Store the size of queue after removing k elements
    int n = q.size();

    // 3. Push all element of stack into queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // 4. push first n of queue at last
    while(n--){
        q.push(q.front());
        q.pop();
    } 
}



// Problem 4: Time needed to buy tickets for kth person
// array of tickets i given if size n
// queue given of n people. Imaine it as queue of people outside ticket counter
// each elements of array shows how many ticket each person wants
// but only one ticket will given at a time and after that element will move at the end and the ticket count will be decrement by 1.
// also there will be time counter associated to a particular element that will increment everytime 1 ticket is given
// when the ticket count will become zero, element will be removed


// we will doing it using queue but we can also do this using array

// 1. Push all index in queue
// 2. time = 0;
// 3. bahir nikal ke ticket dedi. -> time++, ticket--
// 4. if aur ticket ki requirement hai then move it to the end of the queue
// 5. if requriement nahi hai then check if we are finding time for that person.
// if yes then return time or else move the element outside the queue(don't place it at the end)

int tickets(int tickets[], int n, int k){
    queue<int> q;
    for(int i=0; i<n; i++){
        q.push(i);
    }
    int time = 0;
    while(tickets[k]!=0){
        tickets[q.front()]--;
        // check if dobara line mei lage ga
        if(tickets[q.front()]){
            q.push(q.front());
        }
        q.pop();
        time++;
    }
    return time;
}
// T.C: time complexity of above code will be O(n^2)


// Approach 2: T.C = O(n)
// using maths to solve this problem
// time += min(ticket[k], ticket[i]);   // 0-k wale elements ke liye
// time += min(ticket[k]-1, ticket[i]);  // k ke baad wale elements ke liye







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



// there is also a dequeue datatype(double ended queue)