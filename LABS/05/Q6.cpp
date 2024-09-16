// Q6: Fibonacci Series:
// 1 1 2 3 4 8 13 21 34 55 
#include<iostream>
#include<vector>
using namespace std;

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
    cout << fibonacci(n);
}