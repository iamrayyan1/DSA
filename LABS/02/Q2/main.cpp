// Create a header file called matrix_multuply.h that takes two arrays as input and multiplies them and outputs a multiplied array.

#include<iostream>
using namespace std;
#include "matrix_multiply.h"

int main(){
    cout << "Enter no of rows and cols of first matrix: " << endl;
    int row1, col1;
    cin >> row1 >> col1;

    cout << "Enter no of rows and cols of first matrix: " << endl;
    int row2, col2;
    cin >> row2 >> col2;

    int A[row1][col1];
    int B[row2][col2];
    int matrix[row1][col2];

    cout << "Enter elements of 1st matrix" << endl;
    for(int i=0; i<row1; i++)
    for(int j=0; j<col1; j++)
    cin >> A[i][j];

    cout << "Enter elements of 2nd matrix" << endl;
    for(int i=0; i<row2; i++)
    for(int j=0; j<col2; j++)
    cin >> B[i][j];

    matrixMultiplication(A, B, matrix, row1, col1, row2, col2);

    cout << "Resultant Matrix C:" << endl;
    for (int i = 0; i < row1; ++i){
        for (int j = 0; j < col2; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }




}