#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>> & vis, vector<vector<char>> board, int delrow[], int delcol[]){
    vis[row][col] = 1;

    for(int i = 0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && nrow < 4 && ncol >= 0 && ncol < 4 && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            dfs(nrow, ncol, vis, board, delrow, delcol);
    }
}

void solve(vector<vector<char>> &board){
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(4, vector<int>(4, 0));
    
    for(int i = 0; i<4; i++){
        if(!vis[0][i] && board[0][i] == 'O')
            dfs(0, i, vis, board, delrow, delcol);

        if(!vis[3][i] && board[3][i] == 'O')
            dfs(3, i, vis, board, delrow, delcol);
    }

    for(int i = 0; i<4; i++){
        if(!vis[i][0] && board[i][0] == 'O')
            dfs(i, 0, vis, board, delrow, delcol);

        if(!vis[i][3] && board[i][3] == 'O')
            dfs(i, 3, vis, board, delrow, delcol);
    }

    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
            if(!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
}

int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solve(board);

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
