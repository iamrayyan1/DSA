#include<iostream>
#include<vector>
using namespace std;

// Q1: N-Queeens Problem
// The problem of placing n queeenson an nxn chessboard such that no two queens attack each other

// Given an integer n, return all distinct solutions to the n-queens puzzle
// Each solution contains a distinct board configuration of the n-queens placement, where 'Q' and '.' both indicate a queen and an empty space, respectively
 
/*
Must follow 3 rules:
    1. Every row should have one queen
    2. Every col should have one queen
    3. None of the Q should attack each other
*/

// Queen can attack in 8 directions
// generate all possible ways

// backtracking step: when we go back, we remove Q too 

/*
Thought process is to try filling Qs at every column and check using above 3 rules that whether we can place Q at a particular index or not
Calling functions recursively to check each index. Also if we're going back we are removing the Qs we added during the recursion process
*/



bool isSafe(int row, int col, vector<string> board, int n){     // you have to check for 3 directions only
    // check upper diagonal
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

    // check lower diagonal
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






// Q2: Suduko Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells
/*
A sudoku solution must satisfy all of the following rules:
    1. Each of the digits 1-9 must occur exactly once in each row
    2. Each of the digits 1-9 must occur exactly once in each column
    3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub boxes of the grind
*/


// A suduko board is 9x9 board and it comprises of 9 small 3x3 boards
// we have to solve suduko puzzle that is incomplete

// You have to try all possible ways

/*
The thought process behind solving Sudoku using recursion and backtracking involves trying to fill the Sudoku grid systematically by making choices and undoing them when necessary. 
Backtracking is particularly useful when there are multiple possible options, but not all may lead to a solution. 
Here's a step-by-step breakdown of how the thought process works:

1. Understand the problem
A Sudoku puzzle consists of a 9x9 grid, divided into 3x3 subgrids.
Some cells are pre-filled with numbers (1-9), and others are empty.
The goal is to fill the empty cells in such a way that:
Each row contains numbers 1-9 without repetition.
Each column contains numbers 1-9 without repetition.
Each 3x3 subgrid contains numbers 1-9 without repetition.

2. Choose a strategy: backtracking
Backtracking is a trial-and-error approach where you place a number in an empty cell, check if it violates any rules, and move forward.
If a violation occurs (i.e., the current number doesn't work), backtrack by removing the number and trying the next one.

3. Recursive thought process
Find an empty cell: Begin by identifying the next empty cell to fill.
Try possible numbers (1-9): For the chosen cell, attempt to place a number from 1 to 9.
Check for validity: After placing a number, check whether the placement satisfies Sudoku rules:
The number should not already appear in the same row.
The number should not already appear in the same column.
The number should not already appear in the 3x3 subgrid.
Recursive call: Once a valid number is placed, recursively call the same function to fill the next empty cell.
Backtrack if necessary: If no number can be placed in the current cell without violating the rules, undo the last placement (backtrack) and try the next possible number. If all numbers fail, continue backtracking to the previous cells and undo their placements.

4. Base case: solution found
The recursion continues until every cell is filled correctly, meaning no empty cells remain.
The base case of the recursive function is when there are no more empty cells, signaling that a valid solution has been found.

5. Termination
The algorithm terminates when it either finds a solution or has tried all possibilities and concludes there is no valid solution (e.g., if the initial puzzle setup is incorrect or unsolvable).
*/


/*
Key points in the thought process:
Try every possibility: For each empty cell, you try all valid numbers (1-9).
Recursively solve: After placing a valid number, move on to the next cell and repeat the process.
Backtrack if necessary: If a placement leads to an unsolvable state later, undo the placement and try a different number.
Stop when solved: The recursion terminates when no empty cells remain, meaning the puzzle is solved.
This method ensures that every possibility is explored, and backtracking eliminates incorrect choices to find a solution efficiently.
*/

#include <iostream>
#include <vector>

using namespace std;

// This function checks if it's valid to place the character 'c' at the position (row, col) in the Sudoku board.
// It ensures that 'c' doesn't already exist in the current row, column, or the 3x3 subgrid that the cell belongs to.
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // Check the entire column for the presence of 'c'
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c)
            return false;  // 'c' already exists in the column
    }

    // Check the entire row for the presence of 'c'
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c)
            return false;  // 'c' already exists in the row
    }

    // Check the 3x3 subgrid for the presence of 'c'
    // (3 * (row / 3)) gives the starting row of the subgrid, and similarly for the column
    for (int i = 0; i < 9; i++) {
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;  // 'c' already exists in the 3x3 subgrid
    }

    // If no conflicts, the placement is valid
    return true;
}

// This function solves the Sudoku puzzle using recursion and backtracking.
// It modifies the board in-place to fill the cells with numbers that satisfy the Sudoku constraints.
bool solveSudoku(vector<vector<char>>& board) {
    // Iterate over the entire board to find an empty cell (denoted by '.')
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {  // Found an empty cell
                // Try placing numbers from '1' to '9' in the empty cell
                for (char c = '1'; c <= '9'; c++) {
                    // Check if placing 'c' is valid at position (i, j)
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;  // Place 'c' in the cell

                        // Recursively attempt to solve the rest of the board
                        if (solveSudoku(board))
                            return true;  // Puzzle solved, return true
                        else
                            board[i][j] = '.';  // Backtrack: Undo the placement if no solution found
                    }
                }

                // If no number from '1' to '9' can be placed, return false (trigger backtracking)
                return false;
            }
        }
    }

    // If there are no empty cells left, the puzzle is solved
    return true;
}

int main() {
    // Define a partially filled Sudoku board where '.' represents empty cells
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    // Call the solveSudoku function to solve the puzzle
    solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";  // Print each element with a space
        cout << "\n";  // Newline after each row
    }

    return 0;
}




// Q3: M-Coloring Problem

// Given an undirected graph and a number m, determine if the graph can 
// be colored with at most m colors such that no two adjacent vertices of the graph 
// are colored with the same color.

/*
Approach:

Basically starting from vertex 0 color one by one the different vertices. 

Base condition:
If I have colored all the N nodes return true.

Recursion:
Trying every color from 1 to m with the help of a for a loop.
Is safe function returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.
In case this is an algorithm and follows a certain intuition, please mention it. 
Color it with color i then call the recursive function for the next node if it returns true we will return true.
And If it is false then take off the color.
Now if we have tried out every color from 1 to m and it was not possible to color it with any of the m colors then return false.
*/


#include<iostream>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}






// Q4: Rat in a Maze

/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

Note: In a path, no cell can be visited more than one time.


Solution 1: Recursion

Intuition:
The best way to solve such problems is using recursion.:

Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and rightwards(R).
As the answer should be in lexicographical order so it's better to try the directions in lexicographical order i.e (D,L,R,U)
Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so it's important to keep track of the visited cells in a particular path.
If a cell is in path, mark it in the visited array.
Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 
Whenever you reach the destination(n,n) it's very important to get back as shown in the recursion tree.
While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different path possible while getting back and if yes, then mark that cell in the visited array.
*/

#include<iostream>
#include<vector>
using namespace std;



bool valid(){

}

vector<string> findPath(int m, int n){

}

int main(){
    int n = 4;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<string> result = findPath(m, n);

    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;

}
