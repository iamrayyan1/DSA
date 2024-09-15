// 2D Arrays
// row and column
// stored in continous location. a0,a1,a2,b0,b1,b2,c0,c1,c2

// arr[row index[column index]]

#include<iostream>
using namespace std;

int main(){

    int arr[4][3];

    int nums[4][3] = {1,2,3,11,12,13,21,22,23,31,32,33};

    int a[4][3] = {
                    1,2,3,
                    11,12,13,
                    21,22,23,
                    31,32,33
    };

    // update value
    arr[3][0] = 15;
    // user input
    cin>>arr[1][2];

    // print values of array
    for(int i=0; i<4; i++){   //i<row
        for(int j=0; j<3; j++){  //j<col
            cout << arr[i][j]; 
        }
        cout << endl;
    }
}



// Q1: Search an element in Array
    int main(){
        int x;
        cin >> x;
        int arr[4][3];
        for(int i=0; i<4; i++){   //i<row
            for(int j=0; j<3; j++){  //j<col
            cin >> arr[i][j]; 
            }
        }

        for(int i=0; i<4; i++){   //i<row
            for(int j=0; j<3; j++){  //j<col
                if(arr[i][j]== x)
                    cout << "Found";
                    return 1;
            }
        }
        return 0;
    }


// passing 2d array in function

int print(int arr[][4], int row, int col){    // we metion column length
    for(int i=0; i<row; i++){   //i<row
        for(int j=0; j<col; j++){  //j<col
            cout << arr[i][j]; 
        }
        cout << endl;
    }
}

int main(){
    int arr[3][4];
    print(arr,3,4);
}


//Q2: Add 2 Matrix. T.C = O(row*col)
                //  S.C = O(row*col)
int main(){
    int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int ans[3][4];

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}


// Q3: Print row index with max sum
int main(){
    int arr[5][4] = {3,4,7,18,2,8,3,9,5,4,2,2,7,3,0,8,2,8,9,1};
    int sum = 0;
    int index = -1;

    for(int i=0; i<5; i++){
        int total = 0;
        for(int j=0; j<4; j++){
            total += arr[i][j];
        }
        if(sum<total){
            sum = total;
            index = i;
        }
    }
    cout << "Total: " << sum << " Index: " << index;
}


//Q4:  Print sum of diagonal element.
// The row should be equal to column for this question(square matrix)

int main(){
    int row;
    cin >> row;
    int arr[10][10];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            cin >> arr[i][j];
        }
    }

    int first = 0;
    for(int i=0; i<row; i++){       // a;sp can done with while loop
        first += arr[i][i];
    }

    int last = 0;
    int i = 0, j = row -1;
    while(j>=0){
        last += arr[i][j];
        i++, j--;
    }
    cout << "First: " << first << " Last: " << last;

}


// Q5: Reverse each row of matrix

int main(){
    int row;
    cin >> row;
    int col;
    cin >> col;
    int arr[row][col];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    // to reverse the row we will take two variable start and end

    for(int i=0; i<row; i++){
        int start = 0, end = col -1;
        while(start<end){
            swap(arr[i][start],arr[i][end]);
            start++, end--;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}


