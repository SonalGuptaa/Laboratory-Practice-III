#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][8], int row, int col, int n) {
    // Check the column for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    while(row>=0 && col>=0){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

   
    while(row>=0 && col<n){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    

    return true;
}

void printBoard(int board[][8], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) cout << "[Q]";
            else cout << "[]";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool nQueen(int board[][8], int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return true;
    }

    bool placed = false;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            placed = nQueen(board, row + 1, n) || placed;
            board[row][col] = 0; // Backtrack
        }
    }

    return placed;
}

int main() {
    int n;
    cin >> n; // Read the value of n from the user

    int board[n][8] = {0}; // Initialize the board with all 0s

    if (!nQueen(board, 0, n)) {
        cout << "No solution exists.";
    } else {
        cout << "--------All possible solutions--------";
    }

    return 0;
}
