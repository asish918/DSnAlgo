#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int rottenOranges(int grid[3][3]){
    int n = 3;
    int m = 3;
    int vis[n][m];
    int cntFresh = 0;

    queue<pair<pair<int, int>, int> > q;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2){
                q.push(make_pair(make_pair(i, j), 0));
                vis[i][j] = 2;
            }
            else 
                vis[i][j] = 0;

            if(grid[i][j] == 1) cntFresh++;
        }
    }

    int tm = 0;
    int cnt = 0;
    int directions[5] = {-1, 0, 1, 0, -1};

    while(!q.empty()){
       int r = q.front().first.first;
       int c = q.front().first.second;
       int t = q.front().second;
       q.pop();

       tm = max(t, tm);

       for(int i = 0; i<4; i++){
           int nrow = r + directions[i];
           int ncol = c + directions[i+1];

           if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push(make_pair(make_pair(nrow, ncol), t + 1));
                vis[nrow][ncol] = 2;
                cnt++;
           }
       }
    }

    if(cnt != cntFresh) return -1;

    return tm;
}

int main(){
    int grid[3][3] = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << rottenOranges(grid);
}

/*
The directions array is defined as {1, 0, -1, 0, 1}. This array contains the relative coordinate changes for each direction: (1, 0) for moving down, (0, -1) for moving left, (-1, 0) for moving up, and (0, 1) for moving right. Each pair of consecutive values in the directions array represents the coordinate changes for a specific direction.
*/
