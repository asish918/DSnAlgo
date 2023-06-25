#include <vector>
#include <iostream>
using namespace std;

bool isSafe1(int row, int col, vector<string> board, int n){
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while(col >= 0){
        if(board[row][col] == 'Q')
            return false;
        col--;
    }

    col = dupcol;

    while(row < n && col >= 0){
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe1(row, col, board, n)){
            board[row][col] = 'Q';

            solve(col + 1, board, ans, n);

            board[row][col] = '.';
        }
    }
}

void solve2(int col, vector<string>& board, vector<vector<string>>& ans, int n, int leftRow[], int upperDiagonal[], int lowerDiagonal[]){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){
        if(leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;

            solve2(col + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main() {
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for(int i = 0; i < n; i++)
        board[i] = s;

    //solve(0, board, ans, n);

    //Slightly better time complexity
    int upperDiagonal[2 * n - 1] = {0};
    int lowerDiagonal[2 * n - 1] = {0};
    int leftRow[n] = {0};
    solve2(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

    for(auto it : ans){
        for(auto i : it)
            cout << i << endl;;
        cout << "-----------" << endl;
    }
    return 0;
}
