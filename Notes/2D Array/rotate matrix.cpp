//Q1: rotate matrix by 90 colockwise.

// using extra array:

// ith row -> n-1-i column
// column -> row

// for example a matric of [4][4]:

// [0][0] -> [0][3]
// [0][1] -> [1][3]
// [0][2] -> [2][3]
// [0][3] -> [3][3]

// [1][0] -> [0][2]
// [1][1] -> [1][2]
// [1][2] -> [2][2]
// [1][3] -> [3][2]

// [2][0] -> [0][3]
// [2][1] -> [1][3]
// [2][2] -> [2][3]
// [2][3] -> [3][3]

// therefore: ans[j][n-1-i] = matrix[i][j]
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        ans[j][n-1-i] = matrix[i][j]
    }
}


                       
// adjusting on the same array:

// col->reverse = row
// reverse first col and it would be equal to first row

// hence the simple logic is to first transpose the matrix then to reverse the rows

// Step 1: Transpose of matrix
// Step 2: reverse all rows

for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
        swap(arr[i][j], arr[j][i]);
    }
}
for(int i=0; i<n; i++){
    int start = 0; 
    int end = n-1;
    while(start<end){
        swap(arr[i][start], arr[i][end])
        start++, end--;
    }
}





//Q2: Rotate Matrix 180

// one way is to repeat above things two times

// another way:

// first row -> reverse = last row

// first take first row to last, last to first, second to second last and second last to last
// the reverse all rows.

// simple to say first you just have to reverse the columns then the rows

for(int j=0; j<m; j++){
    int start = 0; 
    int end = m-1;
        while(start<end){
        swap(arr[start][j], arr[end][j])
        start++, end--;
    }
}
for(int i=0; i<n; j++){
    int start = 0; 
    int end = n-1;
        while(start<end){
        swap(arr[i][start], arr[i][end])
        start++, end--;
    } 
}



//Q3: rotate matrix by 90 anti-clockwise(270 clockwise)

// apply 90 degree clockwise code 3 times

// other method is to first transpose the matrix then reverse the columns.
for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
        swap(arr[i][j], arr[j][i]);
    }
}
for(int j=0; j<m; j++){
    int start = 0; 
    int end = m-1;
        while(start<end){
        swap(arr[start][j], arr[end][j])
        start++, end--;
    }
}


// another is to first reverse the rows then transpose the matrix



// Q4: Rotate matrix the K time.

// one time means to rotate 90
// two -> 180 degree
// 3 -> 270 degree
// 4 -> orignal position

// you can use some maths to decide what answer you want give

// for eg if k=5
// 500%4
// or use this formula: k%4
