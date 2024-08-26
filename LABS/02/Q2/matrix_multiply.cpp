#include "matrix_multiply.h"

int matrixMultiplication(int A[][], int B[][], int matrix[][], int row1, int col1, int row2, int col2){

    if(col1!=row2){
        return 0;
    }

    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            for(int k=0; k<col2; k++){
                matrix[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }

}