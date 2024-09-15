// A function which calls itself again and again
// Until a specific condition is met

// Like INCEPTION

// there should be stopping condition(when a required condition is met) that will stop the loop
// stopping condition is also called base case

// for recursion, you have to figure out two things, one when to call function and second when to stop

// Birthday countdown example

#include<iostream>
#include <vector>
using namespace std;

int countdown(int n){
    if(n==0){
        cout << "Happy Birthday";
        return;
    }
    // while(n>0){     // this while loop is not neccessary
    cout << n << " days left for birthday";
    n--;
    countdown(n);
   // } 
}

int main(){
    int days;
    cout << "Enter the days left in birthday";
    cin >> days;
    countdown(days);
}
// Iterative approach == Recursive appraoch.



// If base case is not added we will face stack overflow(stacks runs out of memory)
 
 


// Recursive tree can be used to visualize.(VERY HELPFUL)

// Representing recursive function in a mathematical value

// break problem into smaller parts and look for patterns



// printing values from n to 1

void print(int n){
    //Base case
    if(n==1){
        cout << 1;
        return;
    }
    cout << n << endl;
    print(n-1);
}
void printEven(int n){
    if(n==2){
        cout << 2 << endl;
        return;
    }
    cout << n << endl;
    print(n-2);
}


int main(){
    int n = 5;
    print(n);
    n = 10;
    printEven(n);
}










// DOING RECURSION WITH 4 METHODS


// Q1: Print 1 to N.

// method 1:
void print(int num, int n){
    if(num == n){
        cout << num;
        return;
    }
    cout << num << endl;
    print(num+1, n);
}

// method 2: Reverse Approach
void print(int num){
    if(num == 1){
        cout << 1;
        return;
    }
    print(num-1);
    cout << num << endl;
}



int main(){
    int n = 5;
    print(1,n);   // method 1
    print(n);     // method 2
}



// Q2: Print 1 to N (Even Numbers)

// method 1:
void even(int num, int n){
    if(num > n){
        return;
    }
    cout << num << endl;
    even(num+2, n);
}

// method 2:
void even(int num){
    if(num == 2){
        cout << num;
        return;
    }
    even(num-2);
    cout << num << endl;
}


int main(){
    int n = 10;
    if(n%2==1){
        n--;
    }
    even(2,n);   // method 1
    even(n);     // method 2
}