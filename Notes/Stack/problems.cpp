#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// Problem 1: Reverse array using stack

// push elements of array in stack and then pop them out

void reverse(int s[], int n){
    stack<char> st;

    for(int i=0; i<n; i++){
        st.push(s[i]);
    }

    int i = 0;
    while(!st.empty()){
        s[i] = st.top();
        st.pop();
        i++;
    }

}
// T.C and S.C = O(n)



// Problem 2: Insert at bottom

// will use temp stack (we could also take temp array)

void insertAtBottom(stack<int> st, int x){
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}



// Problem 3: Make array Beautiful

// if negative and non negative elements are adjacent in an array. Remove it 

// if they are not add them in the neighbour stack
// we will take an neighbour stack to check neighbour element(top element of stack)
// at last the elements present in stack are the part of beautiful array


void beautiful(vector<int> arr){
    stack<int> s;

    for(int i=0; i<arr.size(); i++){

        // stack can be empty -> no need to check
        if(s.empty()){
            s.push(arr[i]);
        }

        // Non negative number
        else if(arr[i]>=0){
            if(s.top()>=0){
                s.push(arr[i]);
            }
            else{
                s.pop();
            }
        }

        // negative number
        else{
            if(s.top()<0){
                s.push(arr[i]);
            }
            else{
                s.pop();
            }
        }
    }

    vector<int>ans(s.size());
    int i = s.size()-1;
    while(!s.empty()){
        ans[i] = s.top();
        i--;
        s.pop();
    }  
}

// we can do questions like this using stack where we require previous history




// Problem 4: String Manipulation(similar to last problem)

// agar adjacent mei same string hai toh hata dou  -> check previous history from stack
// else add them in stack
// in end return the size of stack

int stringManipulation(vector<string> v){
    stack<string> s;
    for(int i = 0; i<v.size(); i++){
        if(s.empty()){
            s.push(v[i]);
        }
        else if(s.top()==v[i]){
            s.pop();
        }
        else{
            s.push(v[i]);
        }
    }
    return s.size();
}



// Problem 5: Parenthesis is valid or not
// a string of parentheses given both close and open
// in this also we checking history of ( (open parenthesis)

// when we get an open parenthese "(" we will add it in stack to keep record
// whenever we will get ) (close parentheses) we have to check whether there is a pair present in the stack or not
// in last if !st.empty() meaning "(" are left in stack then return 0
// or if you didn't find the pair for a ")" return 0
// if all parentheses have found thier pairs return 1

bool check(string str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){

        // opening
        if(str[i]=='('){
            s.push(str[i]);
        }
        //closing
        else{
            // if stack empty
            if(s.empty()){
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    return s.empty();        // checking if any "(" are left or not
}

// T.C: O(n) , S.C: O(n)


// we can also solve this problem by O(1) without using stack
// by just making a int variable of opening bracket
// iterate over string
// increment if you find '('
// decrement when ')' comes
// return 0 if pair is not present
// return 0 if in end open != 0
// return 1 if open == 0



// Problem 6: Minimum bracket to add to make parentheses valid
// similar logic 
// add counter variable and increment it instead of returning zero

int makeValid(string str){
    stack<char> s;
    int count = 0;
    for(int i=0; i<str.size(); i++){

        // opening
        if(str[i]=='('){
            s.push(str[i]);
        }
        //closing
        else{
            // if stack empty
            if(s.empty()){
                count++;
            }
            else{
                s.pop();
            }
        }
    }
    count += s.size();  // adding no of "(" left in stack
    return count;       
}
// we can also solve this problem without using stack.



// Problem 7: Valid Parentheses
// three types of brackets given this time -> {}, [], ()

// we have to see our previous element


bool check(string str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){

        // opening
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }
        //closing
        else{
            // if stack empty
            if(s.empty()){
                return 0;
            }
            else if(str[i]==')'){
                if(s.top()!='('){
                    return 0;
                }
                else{
                    s.pop();
                }
            }
            else if(str[i]=='}'){
                if(s.top()!='{'){
                    return 0;
                }
                else{
                    s.pop();
                }
            }
            else{
                if(s.top()!='['){
                    return 0;
                }
                else{
                    s.pop();
                }
            }
        }
    }
    return s.empty();        // checking if any "(, {, [" are left or not
}




// Problem 8: Background string compare

// two strings given, we have to compare if they are equal or not
// # means backspace
// if # comes, remove the previous element and then atlast compare both the stacks and if they are same return 1 else return 0

 


// Problem 9: Print bracket numbers
vector<int> brackets(string str){
    int count = 0;
    stack<int> s;    // pushing count of "(" occurence instead of actual character
    vector<int> ans;

    for(int i=0; i<s.size(); i++){
        // opening
        if(str[i]=='('){
            count++;
            s.push(count);
            ans.push_back(count);
        }
        // closing
        else if(str[i]==')'){
            ans.push_back(s.top());
            s.pop();
        }
    }
    return ans;
}



// Problem 10: print minimum element in stack when performing pop operation

// while pushing elements in ans stack compare previous and current values of stack and push the minimum one

stack<int> _push(int arr[], int n){
    stack<int> st;
    for(int i=0; i<n; i++){
        if(i==0){
            st.push(arr[i]);
        }
        else{
            st.push(min(arr[i], st.top()));   // minimum value ko hi push ker rahe
        }
    }
    return st;
}

void _getMinAtPop(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
    }
}