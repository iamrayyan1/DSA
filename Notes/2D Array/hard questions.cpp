//Q1: How to store 2 number in 1 position

// for example 2 2 2 2 2 2: can be stored as 602(2 repeated 6 times)
// ans = number + occurence*100
// later the number and it's occurence can be found by:
// Number = 602%100 = 2 (number = ans%100)
// Occurence = 602/100 = 6 (occurence = ans/100)


// modulus fnction is very powerful


// Q1: Finding Missing and Repeating Number

// So there is a array of N size.
// it stores number starting from 1 to N. But one number between them is missing and one number has been repeated twice.


// Normal approach would be:
// Go through each number and to check if it's coming again or not. This would require two loop. -> T.C = O(n^2)
// To find missing number we will move from 1 to N and would see which number os missing -> T.C = O(n^2)


// Another method would be first to sort the array using vectors. T.C of this would be O(Nlog(N))
// Then go through the array and find both the things


// There is one more better method
// Create a new array that will count how many times each number comes, to check if any of them are repeated or not
// 2 stored suggest that index number is repeated
// 0 suggest that index is missing.

vector<int>count(N,0);
for(int i=0;i<N;i++){
    count[arr[i]-1]++;    // going to array and picking the value stored in arr[i](for example 4) decreasing it by 1(3) and incrementing the value of count[3]
}
    // missing 
for(int i=0; i<n; i++){
    if(count[i]==0){
        cout << i + 1;
        break;
    }
}
for(int i=0; i<n; i++){
    if(count[i]==2){
        cout << i + 1;
        break;
    }
} 




// there is a one more optimise way without creating an extra array

for(int i=0; i<n; i++){
    arr[i]--;
}
for(int i=0; i<n;i++){
    arr[arr[i]%N] += N;   // n is size of array
}
// Missing Number
for(int i=0; i<n;i++){
    if(arr[i]/N == 0);{
        cout << i+1;
        break;
    }  
}
// Reapeating Number
for(int i=0; i<n;i++){
    if(arr[i]/N == 2);{
        cout << i+1;
        break;
    }  
}






// Q2: Find the Occurence of Number
// Array given of N size, you have to print how many times each elements are present in the array


// we can use all methods discuss above
// also by making an extra array 




// Q3: Majority Element

// print number that has occur more than N/2 times

// - one approach can be checking each element one by one and checking it repetance 

// - another method would be by first sorting the array and then counting the number


// - another method would be to take two variables: candidate and count
// this is also called moore voting algorithm

// also verify at the end whether the last candidate is the highest occuring element or not

int candidate;
int count = 0;
for(int i=0; i<N; i++){
    if(count==0){
        candidate = arr[i]
        count = 1;
    }
    else{
        if(candidate==arr[i]){
            count++;
        }
        else
            count--;
    }
}
// verifying selected candidate
count = 0;
for(int i=0; i<n; i++){
    if(arr[i]==candidate)
        count++;
}
if(count > N/2){
    return candidate;                    
}
else
    return -1;