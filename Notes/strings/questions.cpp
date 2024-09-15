// Defanging an IP Address

// whenever point comes write it inside []
// for example: address = 255.100.25.60
                    //    255[.]100[.]25[.]60

// add if condition to check '.'
#include<iostream>
#include<string>
using namespace std;


int main(){
    string address;
    getline(cin, address);
    int index = 0;
    string ans;
    while(index<address.size()){
        if(address[index]=='.'){
            ans = ans+"[.]";
        }
        else
            ans = ans+address[index];
        
        index++;
    }
    cout << ans;
}



//Q2: check if string is rotated by 2 places(clockwise or anticlockwise)

// 2 cases -> 1. Clockwise 2. Anti-clockwise
// you have to move 2 places
void rotateclockwise(string &s){   // passing it as a reference to make change in orignal string too
    char c = s[s.size()-1];
    int index = s.size()-2;
    while(index>=0){
        s[index+1] = s[index];
        index--;
    }
    s[0] = c;
}

void rotateanticlockwise(string &s){  // passing it as a reference(&) to make change in orignal string too
    char c = s[0];
    int index = 1;
    while(index<s.size()){
        s[index-1] = s[index];
        index++;
    }
    s[s.size()-1] = c;
}


int main(){
string str1, str2;
if(str1.size()!=str2.size())
    return 0;
                 
string clockwise = str1;
string anticlockwise = str1;
rotateclockwise(clockwise);
rotateclockwise(clockwise);
if(clockwise==str2){
    return 1;
}

rotateanticlockwise(anticlockwise);
rotateanticlockwise(anticlockwise);
if(anticlockwise==str2){
    return 1;
}

return 0;    // if it's neither rotated clockwise or anticlockwise
}



#include<vector>


// Q3: Check Pangram -> checkk if all lowercase alphabets are present in the string or not

// Sentence = the quick brown fox jumps over the lazy dog
// return 1 if it's pangram or return 0 if it's not

// one way is to check one by one all the alphabets

// another way is to make an array of size 26
// and initialize all with zero
// now go over the string and whenever you find an alphabet, you make that alphabet's index on array equal to 1

// if all values in the array is 1 then it's pangram else it's not
 
int main(){
    string sentence = "the quick brown fox jumps over the lazy dog";
    vector<bool>alpha(26,0);
    for(int i = 0; i<sentence.size();i++){
        int index = sentence[i] - 'a';
        alpha[index] = 1;
    }
    for(int i=0; i<alpha.size(); i++){
        if(alpha[i]==0)
            return 1;
    }
    return 1;
}
 



// Q4: Sorting a string

// we can apply all sorting methods we learned previously here
// for eg: s = eabcabd -> aabbcde
// we will do some comparison using there ASCII values and sort them


// another method to do is: T.C = O(n)
// we can count how many each letter from a-z is occuring then we can write it one by one from the start to end
// just keeping count of each character

// same as previous problem, make an array of size 26

int main(){
    vector<int>alpha(26,0);
    string s;
    string ans;
    for(int i=0; i<s.size(); i++){
        int index = s[i] - 'a';
        alpha[index]++;
    }
    for(int i=0; i<26; i++){
        char c = 'a' + i;
        while(alpha[i]){
            ans = ans + c;
            alpha[i]--;
        }
    }
}



//Q5: Longest Palindrome -> alphabets can be both small and large (a and A are diffrent)

// you will be given string, you have to select characters and create palindromes and give largest possible palindrome

// for eg s = aaaabbbacccc
// all character should be even but the middle character can be odd

// we can solve this by first counting the occurence of each alphabets
// then if they are even, add thier number to the final ans
// if they are odd then, add number-1 to the final ans
// if any of alphabet has occured odd times, add 1 at the end in the end


// create two arrays one for small case and other for capital letters. initialize both to 0
int main(){
    string s;
    vector<int>lower(26,0), upper(26,0);
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a'){
            lower[s[i]-'a']++;
        }
        else 
            upper[s[i]-'A']++;
    }
    int count = 0;
    bool odd = 0;
    for(int i=0; i<26; i++){
        if(lower[i]%2==0){
            count += lower[i];        
        }
        else
            count += lower[i]-1;
            odd = 1;

        if(upper[i]%2==0){
            count += lower[i];        
        }
        else
            count += upper[i]-1;
            odd = 1;
    }
    if(odd==1){
        count++;
    }
    return count;
}



// Q6: Sorting the sentence according to the numbering at the end of each word in the sentence
// for eg: S = "is2 sentence4 This1 a3"

// create a temp string variable 
int main(){
vector<string>ans(10);
string s;
char ans[1000];
int count =0, index = 0, pos=0;
while(index<s.size()){
    if(s[index]==' '){
        int pos = temp[temp.size()-1] - '0';
        temp.pop_back;
        ans[pos] = temp;
        temp.clear;
        count++;
    }
    else{    
        temp += s[index];
        index++;
    }
}
int pos = temp[temp.size()-1] - '0';
temp.pop_back;
ans[pos] = temp;
temp.clear;
count++;

for(int i=1; i<=count; i++){
        temp += ans[i];
        temp += ' ';
    }
temp.pop_back;
return temp;
}


string sortSentence(string s) {
        vector<string>ans(10);
        string temp="";
        int idx=0;
        int count=0;
        while(idx<s.size()){
            if(s[idx]==' '){
            int pos=temp[temp.size()-1]-'0';
            temp.pop_back();
            ans[pos]=temp;
            temp.clear();
            count++;
            }
            else temp+=s[idx];
            idx++;
        }
        int pos=temp[temp.size()-1]-'0';
            temp.pop_back();
            ans[pos]=temp;
            temp.clear();
            count++;
        for(int i=1;i<=count;i++){
            temp+=ans[i];
            temp+=' ';
        }
        temp.pop_back();

        return temp;
    }





// Roman to integer
int num(char c){
    if(c=='I')
        return 1;
    else if(c=='V')
        return 5;
    else if(c=='X')
        return 10;
    else if(c=='L')
        return 50;
    else if(c=='C')
        return 100;
    else if(c=='D')
        return 500;
    else
        return 1000;
}

int convert(string s){
    int sum = 0, index = 0;
    while(index<s.size()-1){
        if(num(s[index])<num(s[index+1])){
            sum = sum - num(s[index]);
        }
        else
            sum = sum + num(s[index]);
        index++;
    }
    sum += num(s[s.size()-1]);
    return sum;
}




//Q: Factorial of a Number










// Q8: Longest Substring without repeating character(any character 0-256)

// it can be done by two different approaches


// but the best possible solution is to do it using sliding window algorithm

// will take two variables(like we did in two pointers)

int longestSubstring(string s){
    vector<bool>count(256,0);       // taking an array of characters and initializing with 0
    int first =0, second=0, len=0;
    while(second<s.size()){
        while(count[s[second]]){   // to remove repeating character
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        len = max(len, second-first+1);   // only update value if new value is greater
        second++;
    }
    return len;
}






// smallest distinct window(characters can repeat) -> every container should come one time

// you have to first define how may unique characters there are
// will return len variable with smallest value
// will take an array of 256 size, all index initialized to zero
// will take two vairables first and second
// take a diff variable that checks if all unique characters are present or not

int findSubstring(string str){
    vector<int>count(256,0);
    int first = 0, second=0, len=str.size(), diff = 0;

    // calculate all unique characters
    while(first<str.size()){
        if(count[str[first]]==0){
            diff++;
        }
        count[str[first]]++;
        first++;
    }

    for(int i=0; i<256; i++){
        count[i] = 0;
    }
    first = 0;

    while(second<str.size()){
        // jab tak diff exist
        while(diff&&second<str.size()){
            if(count[str[second]]==0){
                diff--;
            }
            count[str[second]]++;
            second++;

        }
        len = min(len, second-first); 

        // jab diff != 1
        while(diff!=1){
            len =min(len, second-first);
            count[str[first]]--;

            if(count[str[first]]==0){
                diff++;
            }
            first++;
        }
    }
    return len;

}


