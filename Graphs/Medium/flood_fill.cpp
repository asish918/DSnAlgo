#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& grid, int initColor, int newColor, int drow[], int dcol[], vector<vector<int>>& image) {
    image[sr][sc] = newColor;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<4; i++) {
        int nrow = sr + drow[i];
        int ncol = sc + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == initColor && image[nrow][ncol] != newColor) {
            dfs(nrow, ncol, grid, initColor, newColor, drow, dcol, image);
        }
    }
}

void dfsApproach(vector<vector<int>>& grid, int sr, int sc, int newColor) {
    int initColor = grid[sr][sc];
    vector<vector<int>> image = grid;;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    dfs(sr, sc, grid, initColor, newColor, drow, dcol, image);

    for(auto i : image){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << "----------" << endl;
}

void bfsApproach(vector<vector<int>>& grid, int sr, int sc, int newColor) {
    int initColor = grid[sr][sc];
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> image = grid;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int row = it.first;
        int col = it.second;

        for(int i = 0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == initColor && image[nrow][ncol] != newColor) {
                q.push({nrow, ncol});
                image[nrow][ncol] = newColor;
            } 
        }
    }

    
    for(auto i : image){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << "----------" << endl;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };
    int sr = 1, sc = 1, color = 2;

    dfsApproach(grid, sr, sc, color);
    bfsApproach(grid, sr, sc, color);

    return 0;
}

