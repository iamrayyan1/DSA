#include<iostream>
using namespace std;

int main(){
    int numRows = 5; 
    int **arr = new int*[numRows];

    
    for (int i = 0; i < numRows; i++){
        arr[i] = new int[i + 1]; 

        for (int j = 0; j < i + 1; j++){
            arr[i][j] = i + j;
        }
    }

    cout << "Initial Jagged Array:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int newNumRows = 10;
    int **newArr = new int*[newNumRows];

    for (int i = 0; i < newNumRows; i++){
        if (i < numRows){
            newArr[i] = new int[i + 1]; 
            for (int j = 0; j < i + 1; j++) {
                newArr[i][j] = arr[i][j];
            }
        } else {
            newArr[i] = new int[i + 1]; 
            for (int j = 0; j < i + 1; j++) {
                newArr[i][j] = 0;  
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;

    cout << "\nResized Jagged Array:" << endl;
    for (int i = 0; i < newNumRows; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < newNumRows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
