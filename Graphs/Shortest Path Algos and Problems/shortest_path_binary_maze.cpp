#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

int findShortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m , 1e9));
    queue<pair<int, pair<int, int>>> q;

    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int directions[5] = {-1, 0, 1, 0, -1};

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for(int i = 0; i<4; i++) {
            int nrow = directions[i];
            int ncol = directions[i + 1];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]) {
                if(row == destination.first && col == destination.second) return dis + 1;
                dist[nrow][ncol] = dis + 1;
                q.push({dis + 1, {nrow, ncol}});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1},
    };
    
    pair<int, int> source = make_pair(0, 1);
    pair<int, int> destination = make_pair(2, 2);
    
    cout << findShortestPath(grid, source, destination) << endl;
    return 0;
}
