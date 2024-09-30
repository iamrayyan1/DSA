#include <iostream>

using namespace std;

bool isSafeToPlace(int **chessBoard, int boardSize, int row, int col) {
    for (int i = 0; i < boardSize; ++i)
        if (chessBoard[row][i] || chessBoard[i][col])
            return false;

    for (int i = 0; i < boardSize; ++i) {
        if (row - i >= 0 && col - i >= 0 && chessBoard[row - i][col - i])
            return false;
        if (row + i < boardSize && col + i < boardSize && chessBoard[row + i][col + i])
            return false;
        if (row - i >= 0 && col + i < boardSize && chessBoard[row - i][col + i])
            return false;
        if (row + i < boardSize && col - i >= 0 && chessBoard[row + i][col - i])
            return false;
    }

    return true;
}

bool solveNQueensRecursive(int **chessBoard, int boardSize, int col) {
    if (col >= boardSize)
        return true;

    for (int row = 0; row < boardSize; ++row) {
        if (isSafeToPlace(chessBoard, boardSize, row, col)) {
            chessBoard[row][col] = 1; // Place queen

            if (solveNQueensRecursive(chessBoard, boardSize, col + 1))
                return true;

            chessBoard[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int **solveNQueens(int boardSize) {
    int **chessBoard = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i)
        chessBoard[i] = new int[boardSize](); // Initialize board with zeros (no queens)

    solveNQueensRecursive(chessBoard, boardSize, 0);
    return chessBoard;
}

int main() {
    int boardSize;
    cout << "Enter the size of the chessboard (N): ";
    cin >> boardSize;

    int **chessBoard = solveNQueens(boardSize);

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col)
            cout << (chessBoard[row][col] ? 'Q' : '.') << " "; // Print 'Q' for queen, '.' for empty
        cout << endl;
    }

    for (int i = 0; i < boardSize; ++i)
        delete[] chessBoard[i];
    delete[] chessBoard;

    return 0;
}
