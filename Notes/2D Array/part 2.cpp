// row major order -> by default in cpp, row major is used
// column major order -> though in databases you can customize f 
#include<iostream>
#include<vector>
using namespace std;


// vector in 2d
int main(){
    vector<vector<int>> matrix; 

   // vector<vector<int>> matrix(rows, vector<int> (col, initializer))
    vector<vector<int> >matrix(3, vector<int> (4, 2));

    // update values:
    matrix[1][2] = 5;
    cin>> matrix[2][2];

    // how to find no of rows and col of vector
    int row = matrix.size();
    int col = matrix[0].size();
    
    // print
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << matrix[i][j] << " ";
        }
    }

// much more on 2d vector.
}




// Q1: print matrix like a Waveform

int wave(int arr[][4], int row, int col){
    for(int j=0; j<col; j++){
        if(j%2==0){
            for(int i=0; i<row; i++){
                cout << arr[i][j] << " ";
            }
        }
        else
            for(int i=row-1; i<=0; i--){
                cout << arr[i][j] << " ";
            }    
    }

}


// Q2: print matrix in spiral form
 
// top->right->bottom->left (and then repeat)
int spiral(int arr[][4], int row, int col){
    vector<int>ans;
    int top = 0, bottom = row-1, left = 0, right = col-1;

    while(left<=right&&top<=bottom){
        // Print top
        for(int j=left; j<=right; j++){
            ans.push_back(arr[top][j]);
            top++;
        }
        // Print right
        for(int i=top; i<=bottom; i++){
            ans.push_back(arr[i][right]);
            right--;
        }
        // print bottom
        if(top<=bottom){
        for(int j=right; j<=left; j--){
            ans.push_back(arr[bottom][j]);
            bottom--;
        }
        }
        // print left
        if(left<=right){
        for(int i=bottom; i<=top; i--){
            ans.push_back(arr[i][left]);
            left++;
        }
        }
    }

}


// Q3: Transpose Matrix:
// arr[i][j] -> arr[j][i]
// row becomes column

// one method:To change in same matrix
for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
        swap(arr[i][j], arr[j][i]);
    }
}

// another method:
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        swap(arr[i][j], arr[j][i]);
    }
}



// creating new arr to store
for(int i=0; i<n; i++){
    for(j=0; j<n; j++){
        arr[j][i] = matrix[i][j];
    }
}


