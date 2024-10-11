#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n){     // you have to check for 3 directions only
    //Check the upper diagonal
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // check left
    col = dupcol;
    row = duprow;
    while(col>=0){
        if(board[row][col] == 'Q'){
            return false;
        }
        col--;
    }

    //Check the lower diagonal
    col = dupcol;
    row = duprow;
    while(row<n && col>=0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;

}


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){              // base case
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){       // traversing through each row of column
        if(isSafe(row, col, board, n)){   // checking if all 3 conditions are met
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);  //  recursively calling function and moving to next col
            board[row][col] = '.';        // after coming back changing Q back to '.'
        }
    }
}


vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;          // filling in empty characters on board
    }

    solve(0, board, ans, n);    // starting from first col
    return ans;
}


int main() {
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);
    
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
