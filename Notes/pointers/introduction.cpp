// address -> fast access

#include<iostream>
#include <vector>
using namespace std;

int main(){
    int a = 10;
    cout << a;
    cout << &a;      // to print address of a
    
    int *ptr = &a;      // a pointer that stores/points to the address of a
    cout << ptr;   // prints address of a, that ptr is pointing to

    char c = 'a';
    char *ptr1 = &c;
    cout << ptr1;
    cout << *ptr1;     // printing the value inside c variable.
    cout << *ptr;     // printing the value inside a variable

    a++;
    cout<<*ptr;

    int b = 30;
    ptr = &b;        // value of address inside ptr is updated from address of a to address of b

    int *ptr2;   // if the pointer is not initialized at start. It contains null value

    

}





// Relationship with array
int main(){
    // arr = &arr[0]
    // arr stores the address of zeroth index of array
    int arr[10];
    int *ptr = &arr[0];
    int *ptr2 = &arr[1];
    // or
    ptr = arr;
    ptr2 = arr+1;
    // arr[i] = *(arr+i)
    
    // print the address of first element or 0 index
    cout << arr << endl;
    cout << arr+0 << endl;
    cout << &arr[0] << endl;
    cout << ptr << endl;

    // print the value of 0 index
    cout << arr[0] << endl;
    cout << *arr << endl;
    cout << *(arr+0);
    cout << *ptr << endl;

    // print addresses of all elements in  the array
    for(int i=0; i<5; i++)
    cout << arr+i << endl;

    // print values of array
    for(int i=0; i<5; i++)
    cout << *(arr+i) << endl;
}



// print array using pointer variable
int main(){
    int arr[5];
    int *ptr = arr;
    for(int i=0; i<5;i++){
        cout << ptr[i];
        // or
        cout << *(ptr+i);
    }
}



// arithmetic operations using pointers
int main(){
    int arr[5];
    int *ptr = arr;
    for(int i=0; i<5;i++){
        cout << *ptr;
        ptr++;
    }
    // or
    ptr = arr + 4;
    for(int i=0; i<5;i++){
        cout << *ptr;  // will print values backwards
        ptr--;
    }

    // printing alternate values
    ptr = arr;
    for(int i=0; i<5/2;i++){
        cout << *ptr;  
        ptr+2;
    }    
}









// pointers with character array
int main(){
    char arr[5] = "1234";    //last index is kept for null character
    
    char *ptr = arr;   // contains address of zero index of array

    cout << arr;    // this will print all the character inside array(instead of address of zeroth element)
    cout << ptr;    // this will also print all the character inside array untill null characters come(instead of printing address) 
    // it is different in case of pointers with character array
    
    // to print address write:
    cout << (void*) arr;
    cout << (void*) ptr;
    // we are doing typecasting here. converting char ptr to void ptr.
// (void*) this is a void pointer. It means it indicate a location but it doesn't tell the data type of the pointer



    char name = 'a';
    ptr = &name;
    cout << name;   // this will print value inside name

    cout << &name;   // same logic as char arr, it will print values untill null character come. (it will print random values after 'a' untill null character comes)
    cout << ptr;    // same result as cout << &name;

    // to resolve this issue to print address properly, we can typecast it using null pointer


// instead of typecasting, we can also do static casting
}




// functions
void increment(int n){    // value of n was 10 first
    n++;   // value of n has become 11;
}

int main(){
    int num = 10;
    int temp = num;
    cout << temp;   // prints 10;

    increment(num);   // passing the value to the function
    cout << num;     // the value of num will be 10 not 11.    
    // this is because the address of variable n inside increment function is different and address of num variable is different.
    // so when you make some changes inside a function, it is not applied on the orignal variable inside main. It will only change values inside function. (local variable)
    // when we pass variables inside function(increment(num)) while calling it, only the value is transfered not the address of the orignal variable
}



// functions with pointers
void increment(int *n){    // n is the pointer variable the contains the address of num variable present inside main function
    *n = *n + 1;  // using *n to access the variable to which n is pointing
    // now the value inside num is incremented since now we have the address of the num variable and we can access it using pointer variable
}

int main(){
    int num = 10;
    int temp = num;
    cout << temp;  

    increment(&num);  // passing the address of num variable to the function
    cout << num;   // now it will print 11
}


// with array
int dob(int *p){   // you can also write int p[] instead. In this p contains address of zeroth index of the array
    for(int i=0; i<5; i++){
        p[i] = 2*p[i];  // doubling the value of each element
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    
    dob(arr);    // passing address of the array to the function

    for(int i=0; i<5; i++){
        cout << arr[i];
    }
}

// practice

int swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int first = 10;
    int second = 20;
    // now with the help of a function you have to swap the values of both the variables
    swap(&first, &second);
    cout << first << second;
}




// reference variable -> &
int swap(int &p1, int &p2){    // using reference variable instead of pointer variable
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

int main(){
    int first = 10;
    int second = 20;
    // now with the help of a function you have to swap the values of both the variables
    swap(first, second);
    cout << first << second;
}
// in the above code we have used reference variable which is used to:
//  It allows you to create a second name for the same memory location, 
// making it useful for various tasks 
// such as passing arguments to functions by reference, avoiding copies, and returning multiple values from a function.
// syntax : type &referenceName = existingVariable;
// int &temp = num;  num and temp are same and used onterchangebly


/*
1. Pass by value
2. Pass by pointer
3. Pass by reference
*/




// passing vector
int pass(vector<int>&temp){
    for(int i=0; i<5; i++){
        temp[i] = 20;
    }
}
//passing array
int pass(int p[]){
    for(int i=0; i<5; i++){
        p[i] = 20;
    }
}

int main(){
    vector<int>v(5,0);
    pass(v);
    int arr[5] = {1,2,3,4,5};
    pass(arr);
    for(int i=0;i<5;i++){
        cout << v[i];
    }
    for(int i=0;i<5;i++){
        cout << arr[i];
    }
}


// for ease
// vector, string pass pass with the help of reference
// int arr, char, arr pass with the help of pointer
