// Q2: Write a recursive function to compute the factorial of a number. Demonstrate both tail and non-tail recursion in separate functions.
#include<iostream>
#include<vector>
using namespace std;


int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n * fact(n-1);
}

int tailFact(int n, int total) {
    if (n==0 || n==1){
        return total;
    }
    return tailFact(n - 1, n * total);
}

int main(){
    int n; 
    cout << "Find Factorial of: ";
    cin >> n;
    if(n<0){
        cout << "Factorial is not possible";
        return 0;
    }

    cout << fact(n) << endl;

    cout << tailFact(n, 1);
}

