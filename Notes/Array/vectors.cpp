// Standart Template library

// To use already writen codes in your program. Just like libraries in python
//  already written template


// we can use vectors library in place of arrays.

#include<iostream>
#include<vector>
using namespace std;

// how to declare a vector
/*
syntax: vector<datatype>name;
        vector<datatype>name(sizeofvector,value to initialize with);   (optional)
*/
vector<int>nums;


// How to insert value in vector:
vector<int>nums(4);           // vector variable of int type of size 4

// initializing value to 2;
vector<int>nums(4,2);         // value of size 4. Each index inside vector is intialize with 2


// adding values inside vectors
int main(){
    vector<int>a;
    a.push_back(4);    // a[0] contains 4
    a.push_back(8);    // a[2] has 8
    a.push_back(5);    // 4,8,5

// push_back is a predefinded function inside vectors library. The actual implementation inside push_back function is very intresting

// more ways to initialize
    vector<int>v = {2,4,6,8,10};
    //or
    vector<int>v(5);
    for(int i=0; i<v.size(); i++){
        cin >> v[i];
    }

    // or
    int n;
    cin >> n;
    vector<int>arr(n);         // took user input for the size of array.
    for(int i=0; i<n; i++){
        cin >> v[i];
    }




// dsa is applied on ram
// ram is divided into two parts stack and heap
// stack has very less memeory and heap recieves large memory
// main function memory is allocated to stack.
// Static memory allocation -> stack
// Dynamic memory allocation -> heap
// vectors memory is allocated to heap

// updating value:
    v[1] = 5;



// How to remove value from vector

    v.pop_back();    // to remove the last element(memory won't be released)
    v.clear();       // to empty the array(space will still be allocated)
    v.erase(v.begin()+2);    // to delete v[2]. so if the array was 6,7,8,9,10, after v.erase() it would be 6,7,9,10,_. last space would be left empty since in array element are stored in continous manner

    v.insert(v.begin()+1, 50);   // to add value on v[1]


// size and capacity of vector:

// size is where elements are stored   
// capacity also include empty spaces after the stored elements
// for example an vector of capacity 10 contains: 1,2,3,4,5,6
// so now it's size is 6 but the capacity is 10.

    v.size();   // gives the size of the vector
    v.capacity();


// Front, back, at, empty 
    cout << v.front();    // to get element at first index   
    cout << v.back();     // to get element at last index    
    cout << v.empty();    // returns true or false



// iterator in a vector(a pointer variable pointing at a position in vector)

// 1. v.begin(): // iterator pointing at the first index of the vector   
// 2. v.end(): // iterator pointing after the end of the vector

    for(auto it = v.begin(); it!=v.end(); it++){   // auto is used to automatically get the data type. used in places where you don't know the data type
        cout << *it << endl;    // used * to access the memory location
    }


// v.rbegin(): iterator pointing at the last index of the vector
// v.rend(): iterator pointing before the start of the vector


// other ways to print vector
    for(int i =0; i<v.size(); i++){
        cout << v[i];
    }
    // or
    for(auto x : v){
        cout << x << " ";
    }




// sorting
    vector<int>nums = {1,2,3,4,5};
    
    sort(nums.begin(), nums.end());  // sort in increasing order

    sort(nums.begin(), nums.end(), greater<int>());   // sort in descending order
// another way to sort in descending order
    sort(nums.rbegin(), nums.rend());


// copy value from one vector to another

vector<int>a;
a = nums;


 
// search in binary search(sorted array)
    cout << binary_search(nums.begin(), nums.end(), 54);   // it will return 0 if 54 is not present inside nums or 1 if 54 is present inside nums

// to get index of the element to search
    cout << find(nums.begin(), nums.end(), 54) - nums.begin();   // it will return iterator pointing at the index where 54 is present. to find the index minus it by nums.begin()

}


// there are many more operation that we can do using vector library


// function call in vector







// there are many more STLs.