// time complexity is not equal to time taken by algorithm
// space complexity is space taken by program in computer ram
// one question can be solve by multiple approaches
// best approach is one that has lowest time and space complexity

// you cannot calculate in second since everytime it gives different answer, based on input given and type of device used and background processes
// therefore time complexity != time taken

// but how much each factor affects the time complexity needs to be evaluated

// Time Complexity: It is the total time taken by an algorithm to run as a function of length of the input
// The time complexity of the function func is determined by the loop that iterates through the array.

// we calculate in methematical function in terms of n
// for example n, n^2, n^3, log(n) or constant(doesn't depend)

// best case, worst case, average case
// but only worst case is ussually considered.

// Big(O) -> worst case. for eg: O(n), O(n^2)
// Ω -> best case. for eg: Ω(n), Ω(n^3)
// θ -> Average case. for eg: θ(log(n)), θ(2n)

#include <iostream>
using namespace std;

int main(){
    int n = 3;
    for(int i=0;i<n; i++){
        cout << i;
    }
}

// we just have to calculate the steps program do during one loop.
// add steps of all loop in terms of n
// then remove constants from the expression.
// for example: 4 + 3 + 3 + 3 ........ + 3 (till n)
// add all steps in terms of n: 3n + 1
// remove constants: O(n) is the time complexity.(worst case)

// RULES:
// 1. remove constants from the expression
// 2. If in expression n has multiple dependencies. for example n^3+n^2+n
// in this case only the larger term will be considered, rest will be ignored
// like ans for above example will be: O(n^3)

// complexity of linear search.
int main(){
    int n = 4;
    int arr[n];
    int x = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            cout << i + 1;
            break;
        }
    } 
}

// best case would be Ω(1). Since the best possible case is that we would find the desired number during first loop iteration
// Worst case is O(n)
// Average case is: n*(n+1)/2n -> θ(n)


// Best case is that we found the number in first iteration. (the element was in arr[0])
// Worst case is that we found the number in last iteration. (the element was in arr[n-1])
// Average case is that we found the number in middle of 1st and last iteration. (the element was in arr[0])
// Average can be calculate by adding all the steps of all the iteration and dividing it by n

// Some times all three cases have same time complexity. 
// For example in first example where we had to print a string n times. In that case, the loop will iterate over loop n time, not matter what
// but in this case, since we were finding a number from array then breaking the loop if found, so it can be varied from case to case


// sometime time complexity doesn't depend on the n
int main(){
    int n;
    cin >> n;

    for(int i=0; i<10; i++){
        cout << i;
    }
}
// like in above case program doesn't depend on n. No matter what n is, the loop will run 10 times
// therefore time complexity of this is: O(10). Constant is represented as 1 in time complexity.
// So all three worst, best and average case will be O(1)




// calculating sum of N

// one way would be directly using formula
int n = 100;
cout << n*(n+1)/2;

// no matter how big the n is, we will calculate this in 1 step. hence O(1) is the time cmp



// another question is where there is a loop inside a loop
for(int i = 0; i<n; i++){
    for(int j=0; j<n; j++){
        cout << i
    }
}
// time complexity of this would be n*n
// O(n^2) is the time complexity


// if the inner loop depends on the outer loop.
for(int i = 0; i<n; i++){
    for(int j=0; j<i; j++){
        cout << i
    }
}
// when we will count the steps it would be 1,2,3,4,5.........,n
// adding them would give this espressoin: n*(n+1)/2
// simplifying this would give: O(n^2)









// another example
for(int i = 0; i<n; i++){
    for(int j=0; j<i*i; j++){     //i^2
        cout << i
    }
}
// first step is to count the total iterations(steps)
// 1,4,9,16  -> 1^2, 2^2, 3^2, 4^2......., n^2
// adding these will give: n(n+1)(2n+1)
// after simplifying we will get: O(n^3)



// another example
for(int i = 0; i<n; i++){
    for(int j=0; j<m; j++){     
        cout << i
    }
}
// inner loop will run m times while outer loop will run n times.
// Total iterations will be n*m -> time complexity for this is: O(nm)



// .....
for(int i = 0; i<n; i++){
    for(int j=0; j<i*i; j++){     
        for(int k=0; k<n/2; k++){
            cout << "Print"
        }
    }
}
// rewatch this part(52 mins)
// ans for this is: O(n^4)




// .....
for(int i=0; i<n; i=i*2){
    cout << i;
}
// 1,2,4,8,16,32,64,128......,k+1
// in this case n=2^k         
// taking log on both sides. log(n)=log(2^k)
// k = log(n)/log(2) -> k = log base 2 (n)
// since it was k+1, therefore log base 2 (n) + 1
// time complexity is O(log base 2 (n))


// if it was:
for(int i=0; i<n; i=i*3){
    cout << i;
}
// 1,3,9,27,81,243......,k+1
// while n = 3^k
// time complexity will be O(log base 3 (n))


// if it was:
for(int i=0; i<n; i=i*4){
    cout << i;
}
// time complexity will be O(log base 4 (n))





// .....
for(int i = n/2; i<n; i++){        // n/2 times
    for(int j=0; j<n/2; j++){      // n/2 times
        for(int k=0; k<n; k++){    // n times
            cout << "Print"
        }
    }
}
// since the inners loops doesn't depend on outer loops hence we can calculate this directly by multiplying individual loop
// n/2 * n/2 * n  -> n^3/4
// ans = O(n^3)




// .....
for(int i = n/2; i<n; i++){        // n/2 times
    for(int j=0; j<n; 2*j){      // log base 2 (n) times
        for(int k=0; k<n; 2*k){    // log base 2 (n) times
            cout << "Print"
        }
    }
}
// since the inners loops doesn't depend on outer loops hence we can calculate this directly by multiplying individual loop
// n/2 * log base 2 (n) * log base 2 (n)
// ans = O(n(log base 2 (n))^2)


// .....
for(int i = 0; i<n; i++){
    for(int j=0; j<m; j+i){     
        cout << i
    }
}
// steps would be n, n/2, n/3, n/4......., n/n
// n(1+1/2+1/3+1/4+....n) -> this is the harmonic series
// it's sum will be: nlog base e (n)
// O(nlog base e (n))




// SPACE COMPLEXITY


// Space Complexity: It is the amount of space taken by an algorithm
// It is not calculated in gbs/mbs or kb
// rather it's calculate in terms of n(input)


// Auxillary Space: Space taken by program except the input already given
// Total Space Complexity: Space taken by program including the input already given

/*
Order of Complexity: (worst to best)
O(n!)
O(2^n)
O(n^4)
O(n^3)
O(n^2)
O(nlogn)
O(n)
O(n^1/2)
O(logn)
O(1)
*/

// TLE is the error that we get if we don't follow the required algorithm that have to be used