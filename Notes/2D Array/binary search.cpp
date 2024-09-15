// it can only be applied on sorted 2d array

// basic approach would be two run through the entire array and use if condition to find the element

// another way is to go to each row and check first and last element of each row
// and create a range and check whether target value is between this range or not
// if yes check over that range else move to next row
// to check over the row apply binary search on that row

for(int i=0; i<n; i++){
    if(matrix[i][0] <= target && matrix[i][m-1]>=target){
        int start = 0; 
        int end = m - 1;
        while(start<=end){
            int mid = (start+end)/2
            if(matrix[i][mid]==target){
                return 1;
            }
            else if(target>matrix[i][mid]){
                start = mid + 1;
            }
            else
                end = mid -1;
        }
        return 0;
    }
}
//T.C = O(N+log(N))
// S.C = O(1)


// there is one more better approach

// convert it into 1D array(not actually) by using row major concepts and apply binary search them

// row_index = index/col
// col_index = index%col
int row,col;
int start = 0;
int end = (row*col) - 1;

while(start<=end){
    mid = (start+end)/2;
    row_index = mid/col;
    col_index = mid%col;
    if(matrix[row_index][col_index] == target){
        return 1;
    }
    else if(matrix[row_index][col_index] < target){
        start = mid + 1;
    }
    else
        end = mid - 1;
}
return 0;  







//Q2: Search in sorted row and col wise matrix.

// we can use first two method we discussed above to solve this question.
// One going on through the entire array and using if condition to search the array
// the other was to go on each row and apply binary search specifically on that row if target comes under that row's range



//To apply binary search you have to apply different logic in this
// you have to find a case where you can find one way where the value increases and one way where it decreases

// left or down

int row = 0;
int col = m-1;

while(row<n && col>=0){
    if(arr[row][col]==ans){
        return 1;
    }
    else if(arr[row][col]<ans){
        row++;
    }
    else
        col--;
}
return 0;

// T.C would be O(n+m)