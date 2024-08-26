// 1. Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index.


#include<iostream>
using namespace std;

int main(){
    int numRows; 
    cin >> numRows;
    int **arr = new int*[numRows];

    for(int i=0; i<numRows; i++){
        arr[i] = new int[5]; 

        for(int j=0; j<5; j++){
            arr[i][j] = i+j;
        }
    }

    for(int i=0; i<numRows; i++){
        for(int j=0; j<5; j++){
            cout << arr[i][j];
        }
    }

    for(int i=0; i<numRows; i++){
        
        int *newArray = new int[10];

        for(int j=0; j< 5; j++){
            newArray[j] = arr[i][j];
        }

        for(int j=5; j<10; j++){
            newArray[j] = 0;
        }

        delete[] arr[i];
        arr[i] = newArray;

    }

    for(int i=0; i<numRows; i++)
    for(int j=0; j<10; j++)
    cout << arr[i][j] << " ";

    for (int i = 0; i < numRows; ++i){
        delete[] arr[i];
    }
    delete[] arr;

}