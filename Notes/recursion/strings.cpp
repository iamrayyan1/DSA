#include<iostream>
#include <vector>
using namespace std;


// checking palindrome
bool pal(string s, int start, int end){
    if(start>end){   // base condition
        return 1;
    }
    if(s[start]!=s[end]){
        return 0;
    }
    return pal(s, start+1, end-1);
}

int main(){

} 




// count vowels
int vowels(string s, int index){
    if(index==-1){
        return 0;
    }

    if(s[index]=='a' || s[index]=='e' || s[index]=='i' || s[index]=='o' || s[index]=='u'){
        return 1 + vowels(s, index-1);
    }
    else
        return 0 + vowels(s, index-1);
}
// if starting from the start, add one more argument of size of array




// reverse a string'
void reverse(string &str, int start, int end){
    if(start>=end){
        return;
    }
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    reverse(str, start+1, end-1);
}



// lower case to uppercase
void convert(string &str, int index){
    if(index==-1){
        return;
    }
    str[index] = 'A' + str[index] - 'a';
    convert(str, index-1);
}