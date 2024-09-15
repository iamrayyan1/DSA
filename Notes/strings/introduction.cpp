// character array

#include<iostream>
#include<string>
using namespace std;

int main(){

// for example you want to store word apple
char arr[] = {'a','p','p','l','e'};

// taking input from user
// first asking user for the size of array
cout << "size of the array";
int n;
cin >> n;
char arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}


// what if we don't ask user for size of the array
char arr[20];   
cin >> arr;     // user can directly input inside the array
// if the user types apple
// then the array would look like this:
// a p p l e \0 ...empty array...  the null character will be placed after the end of the string automatically by the system

// the user of this null char is:
// what if we cout << arr, then the arr will start 0 index and will print until null character arrives
cout << arr;
// it will stop printing elements until null character arrives. the things after null char won't be printed

// character takes 1 byte of space




// still we have to mention the size of array while declaring
// here comes the idea of string
// it uses the idea of dynamic memory

string s;
cin >> s;
cout << s;
// still it stores the null character for example apple is of 5 letters it will be stored in array of size 6. you don't have to write "\0" , system will take care of it

string name = "Rayyan";   // declaring and initializing


// if we enter space in our string 
string name = "Rayyan Merchant";         // this will print fine since we have initialized it directly
// but we take user input and he types: Rayyan Merchant is a good boy
cin >> name;
// then only rayyan will be stored in the string variable
// because the cin operator, as soon as we type enter, tab or space, it stops taking input(reading)

// the solution for this is to instead of using cin, use getline(cin,s); function
// getline(cin, s) will only stop when you press enter
getline(cin, s);
cout << s;   // now entire string will print




// size of string
string s = "Rayyan";
cout << s.size();   // returns size of string


// string concatanation 
string s1 = "Rayyan";
string s2 = "Merchant";
string s3 = s1 + s2;    // another way to do this is: s1.append(s2);


// if you want to attach one character at the end of the string
s.push_back('P');


// if you want to remove a char from last
s.pop_back();



// memory is allocated inside heap(dynamic memory)



// what if you want to print " " in your paragraph -> we use escape character(\)
string s = "Rayyan is a \"good\" boy";


// reversing string
string s = "Rayyan";
// it is same as we did for reversing an 1D 
int start = 0, end = s.size()-1;
while(start<end){
    swap(s[start], s[end]);
    start++, end--;
}



// To print size of array without using s.size()
// since we know that the last character string array is a null character.
int size = 0;
while(s[size]!='\0'){
    size++;
}
cout << size;



// check if string is palindrome or not -> for eg: "naman"
// take two varaibles start and end and start comparing both indexes.
int start = 0, end = s.size()-1;
while(start<end){
    if(s[start]!=s[end]){
        cout << "Not a Palindrome";
        return 0;
    }
    start++, end--;
}
cout << "It is a Palindrome";








}