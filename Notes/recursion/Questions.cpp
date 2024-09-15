#include<iostream>
#include <vector>
using namespace std;

// Q1: Factorial

int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n * fact(n-1);
}

int main(){
    int n; 
    cout << "Find Factorial of: ";
    cin >> n;
    if(n<0){
        cout << "Factorial is not possible";
        return 0;
    }
    cout << fact(n);
}


// Q2: Find Sum of N number

int sum(int n){
    if(n==0){
        return 0;
    }
    return n + sum(n-1);

}

int main(){
    int n; 
    cout << "Find Sum of: ";
    cin >> n;
    cout << sum(n);
}



// Q3: Power of 2
int pow(int n){
    if(n==0){
        return 1;
    }
    return 2 * pow(n-1);
}

int main(){
    int n; 
    cout << "Find 2 power: ";
    cin >> n;
    cout << pow(n);
}
// to make it generalise power function meaing we can caluclate power of any number:
// you have to pass one more variable in function


// Q4: Sum of square of N number
int squareSum(int n){
    if(n==0){
        return 0;
    }
    return n*n + squareSum(n-1);
}

int main(){
    int n; 
    cout << "Find Sum of Square of: ";
    cin >> n;
    cout << squareSum(n);
}



// Q5: Fibonacci Series:
// 0 1 1 2 3 4 8 13 21 34 55 
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}


int main(){
    int n;
    cout << "Find N fibonacci number: ";
    cin >> n;
    fibonacci(n);
}

// solve one case only, you will find the sequence for all





// Q6: Nth stair
// no of ways we can reach nth stair
// look for patterns by manually calculating no of ways for 1,2,3,4 stairs 

int stairs(int n){
    if(n<=1){
        return n;
    }
    return stairs(n-1) + stairs(n-2);
}

int main(){
    int n;
    cout << "Find no of ways to reach N stairs: ";
    cin >> n;
    stairs(n);
}




// Q7: Find GCD of 2 Number

// Euclidean algorithm
int gcd(int a, int b){
   if(b==0){
    return a;
   }
   return gcd(b, a%b);
}