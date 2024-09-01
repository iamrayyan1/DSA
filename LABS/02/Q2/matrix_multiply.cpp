#include "matrix_multiply.h"

void matrixMultiply(int** A, int** B, int** C, int row1, int col1, int col2){
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++){
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++){
            for (int k = 0; k < col1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
