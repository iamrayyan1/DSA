#include<iostream>
#include <vector>
using namespace std;

// creating 1D array using pointer

int main(){
    int *ptr = new int[4];
}



// creating 2D array

int main(){
    // 5 rows, 4 cols  -> 5 1D array of size 4  -> 5 pointers to store addresses of each array

    // creating a array that will store addresses of the array
    // and using a double pointer to access the array containing addresses

    // *(*(ptr=2)+1) = ptr[2][1]

    // 1. Create 1D array to store address
    // 2. Each element in that array stores the address of another array

    int n, m;
    cin >> n >> m;
    int **ptr = new int *[n];   // creating an array of size n(rows) -> this will store the addresses of other arrays
    for(int i=0; i<n; i++){
        ptr[i] = new int[m];     // creating 1D arrays of size m(cols) and storing thier addresses inside the array created above 
    }
    // this is how we create 2D array of size n rows and m cols

    // to insert value
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ptr[i][j];
        }
    }

    // priting array
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ptr[i][j];
        }
    }

    // to release memory
    for(int i=0; i<n; i++){
        delete[] ptr[i];   
    }
    delete[] ptr;
}




// creating 3D Array

int main(){
    // 3D array is made up of multiple 2D arrays


    // *(*(*(ptr+2)+1)+2)  == ptr[2][1][2]

    // creating
    int l,b,h;
    cin >> l >> b >> h;
    int ***ptr = new int**[l];
    for(int i=0; i<l; i++){
        // creating 2d array and store it's address in ptr
        ptr[i] = new int*[b];
        for(int j=0; j<b; j++){
            ptr[i][j] = new int[h];
        }
    }

    // creating memory: L->B->H
    // releasing memory:H->B->L
    

}


// 4D Array



// pointer just contains the address