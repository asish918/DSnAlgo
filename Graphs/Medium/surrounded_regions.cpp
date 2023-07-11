#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O')
            dfs(nrow, ncol, grid, vis, delrow, delcol);
    }
}

void surroundRegionsDFS(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i<m; i++) {
        if(!vis[0][i] && grid[0][i] == 'O')
            dfs(0, i, grid, vis, delrow, delcol);

        if(!vis[n-1][i] && grid[n - 1][i] == 'O')
            dfs(n-1, i, grid, vis, delrow, delcol);
    }

    for(int i = 0; i<n; i++) {
        if(!vis[i][0] && grid[i][0] == 'O')
            dfs(i, 0, grid, vis, delrow, delcol);

        if(!vis[i][m-1] && grid[i][m-1] == 'O')
            dfs(i, m - 1, grid, vis, delrow, delcol);
    }

    for(int i = 1; i<n - 1; i++)
        for(int j = 1; j<m - 1; j++)
            if(!vis[i][j] && grid[i][j] == 'O')
                grid[i][j] = 'X';
}

void surroundRegionsBFS(vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i<m; i++) {
        if(grid[0][i] == 'O') {
            q.push({0, i});
            vis[0][i] = 1;
        }

        if(grid[n - 1][i] == 'O') {
            q.push({n - 1, i});
            vis[n - 1][i] = 1;
        }
    }

    for(int i = 0; i<n; i++) {
        if(grid[i][0] == 'O') {
            q.push({i, 0});
            vis[i][0] = 1;
        }

        if(grid[i][m - 1] == 'O') {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        
        int row = it.first;
        int col = it.second;

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O') {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    for(int i = 1; i<n - 1; i++)
        for(int j = 1; j<m - 1; j++)
            if(!vis[i][j] && grid[i][j] == 'O')
                grid[i][j] = 'X';
}

int main() {
    vector<vector<char>> grid = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    
    //surroundRegionsDFS(grid);
    surroundRegionsBFS(grid);

    for(auto i : grid) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

