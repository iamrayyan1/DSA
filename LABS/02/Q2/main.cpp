#include<iostream>
using namespace std;
#include "matrix_multiply.h"

int main(){
    cout << "Enter number of rows and columns of the first matrix: " << endl;
    int row1, col1;
    cin >> row1 >> col1;

    cout << "Enter number of rows and columns of the second matrix: " << endl;
    int row2, col2;
    cin >> row2 >> col2;

    if (col1 != row2){
        cout << "Matrix multiplication not possible due to incompatible dimensions." << endl;
        return 1;
    }

    int** A = new int*[row1];
    for (int i = 0; i < row1; i++){
        A[i] = new int[col1];
    }

    int** B = new int*[row2];
    for (int i = 0; i < row2; i++){
        B[i] = new int[col2];
    }

    int** matrix = new int*[row1];
    for (int i = 0; i < row1; i++){
        matrix[i] = new int[col2];
    }

    cout << "Enter elements of 1st matrix:" << endl;
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            cin >> A[i][j];

    cout << "Enter elements of 2nd matrix:" << endl;
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            cin >> B[i][j];

    matrixMultiply(A, B, matrix, row1, col1, col2);

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < row1; ++i){
        for (int j = 0; j < col2; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row1; i++) delete[] A[i];
    delete[] A;

    for (int i = 0; i < row2; i++) delete[] B[i];
    delete[] B;

    for (int i = 0; i < row1; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
