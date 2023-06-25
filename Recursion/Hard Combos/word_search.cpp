#include<iostream>
#include<vector>
using namespace std;

bool solve(int index, int row, int col, string s, vector<vector<char>>& board, int n, int m, int drow[], int dcol[], vector<vector<int>>& vis) {
    if(index == s.length())
        return true;

    for(int i = 0; i<4; i++) {
        int nextrow = row + drow[i];
        int nextcol = col + dcol[i];

        if(nextrow >= 0 && nextrow < n && nextcol >= 0 && nextcol < m && board[nextrow][nextcol] == s[index] && !vis[nextrow][nextcol]) {
            vis[row][col] = 1;
            if(solve(index + 1, nextrow, nextcol, s, board, n, m, drow, dcol, vis))
                return true;
            vis[row][col] = 0;
        }
    }
    
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis (n, vector<int> (m, 0));

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    string s = "ABCCED";

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) {
            if(board[i][j] == s[0]){
                cout << solve(1, i, j, s, board, n, m, drow, dcol, vis);
                return 0;
            }
        }
    }

    return 0;
}
