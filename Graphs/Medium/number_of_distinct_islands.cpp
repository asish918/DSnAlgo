#include<iostream>
#include<queue>
#include <string>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;

void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, string& shape){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> q;
    q.push({row, col});

    vector<int> directions = {-1, 0, 1, 0, -1};
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int row = it.first;
        int col = it.second;

        for(int i = 0; i<4; i++) {
            int nrow = row + directions[i];
            int ncol = col + directions[i + 1];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
                shape.append(to_string(i));
            }
        }
    }
}

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, string& shape) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    vector<int> directions = {-1, 0, 1, 0, -1};
    for(int i = 0; i<4; i++) {
        int nrow = row + directions[i];
        int ncol = col + directions[i + 1];

        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]){
            shape.append(to_string(i));
            dfs(nrow, ncol, grid, vis, shape);
            shape.append("#");
        }
    }
}

int islandsDFS(vector<vector<int>>& grid) {
    unordered_set<string> islands;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                string shape;
                dfs(i, j, grid, vis, shape);
                islands.insert(shape);
            }
        }
    }

    return islands.size();
}

int islandsBFS(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<string>islands; //to store unique shapes - It's size is the final answer
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                string shape = "";
                bfs(i, j, grid, vis, shape);
                islands.insert(shape);
            }
        }
    }

    return islands.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };
    
    cout << islandsBFS(grid) << endl;
    cout << islandsDFS(grid) << endl;
    return 0;
}

/*
In the provided code, the "#" symbol is appended to the shape string during the Depth-First Search (DFS) traversal of the island. The purpose of appending "#" is to differentiate between different directions of movement within the shape string.

Each island in the grid is represented by a shape string, which captures the sequence of directions taken during the DFS traversal. In the code snippet, the directions are encoded as integers from 0 to 3: 0 represents moving up, 1 represents moving right, 2 represents moving down, and 3 represents moving left.

When traversing from one cell to another adjacent cell, the corresponding direction of movement is appended to the shape string using shape.append(to_string(i)), where i represents the direction. By appending the direction as an integer, the shape string maintains the order of movements during the DFS traversal.

To differentiate between different movements within the same island, the "#" symbol is appended after each direction. This helps distinguish between adjacent movements and ensures that the shape string correctly captures the sequence of directions followed during the DFS traversal.

Overall, the "#" symbol acts as a separator between consecutive directions, enabling the correct reconstruction of the island's shape during the DFS traversal.

example test case  
0 1 1
0 1 0
0 0 0

0 1 1
0 0 1
0 0 0

  in both matrix  if we dont put # our string will be same    but both are different structre 
*/
