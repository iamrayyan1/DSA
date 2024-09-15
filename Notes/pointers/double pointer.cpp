#include<iostream>
#include <vector>
using namespace std;

void fun(int *p1){
    *p1 = *p1 + 10;   // to change value of n
}

void fun(int **p1){
    *p1 = *p1 + 1;        // to change the address of pointer using double pointer
}


int  main(){
    int n = 10;
    int *p = &n;
    int **ptr = &p;  // using double pointers to store the address of the pointer
    int ***triple = &ptr;   // triple pointer to store address of double pointer
    // like this you can create multiple pointers
    // it is used while making 2d, 3d arrays


// modify value in n
    *p = *p + 4;       // updating the value of n from 10 to 14
    **ptr = **ptr + 10; // updating the value from 14 to 24
    *p = 15;   // n=15

    // to access n we can use *p or **ptr or ***triple


    // using a function to modify n using pointer
    fun(p);          
    cout << n;

    // changing address of pointer using double pointer
    fun(ptr);
}





// Q1: Predict Output
int main(){
    char c[] = "GATE2024";       // character array
    char *p = c;
    cout << p + p[3] - p[1];    // Address + 'E' - 'A'
                                // Address + 4
                                // cout << Address + 4*(sizeofdatatype)
                                // output = 2024
}


// Q2:
void second(int *p1, int *p2){   // p1->i , p2->j 
    p1 =  p2;      // p1->j
    *p1 = 2;       // j=2
}
int main(){
    int i=0, j=1;
    second(&i, &j);
    cout << i << j;      // output = 0 2

}


//Q3:
int main(){
    int *ptr;
    int x = 0;
    ptr = &x;    // ptr->x
    int y = *ptr;    // y = x -> y = 0
    *ptr = 1;       // x = 1
    cout << x << y;   // Output = 1 0
}


// Q4: 
int main(){
    int a=5 , b=10;
    int &name = a;    // reference variable  a<->name
    int *ptr = &a;    // ptr->a
    (*ptr)++;         // a++   -> a=6
    ptr = &b;         // ptr->b
    *ptr = *ptr + 5;  // b = b + 5  -> b=15
    name += 5;        // a = a + 5  -> a=11
    cout << a << b;   // Output = 11 15
}


// Q5: 
int four(int x, int *py, int **ppz){   // x = 4, py=&c, ppz=&b
    int y, z;
    **ppz += 1;   // c = c + 1;  -> c=5
    z = **ppz;    // z = c   -> z=5
    *py += 2;     // c = c + 2  -> c=7
    y = *py;      // y = c   -> y=7
    x += 3;       // x = x + 3   -> x=7
    return x + y + z;    // 7 + 7 + 5
}

int main(){
    int c, *b, **a;
    c = 4, b=&c, a=&b;  
    cout << four(c,b,a);    // passing 4, address of c and address of b
// output = 19
}



// Q6:
void five(char *str1, char *str2){   // str1 = address of first[0], str2 = address of second[0]
    while((*str1 = *str2)){       // while first[] = second[]
        str1++, str2++;        // increment both by one
    }
    // at the end of the loop first = Rohan and second = Rohan
}

int main(){
    char first[] = "Mohit";
    char second[] = "Rohan";
    five(first, second);
    cout << first;      // Output = Rohan
}

// Above code is for string copying