#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int main(){
    int grid[3][4] = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    int vis[3][4] = {0};
    int dist[3][4] = {0};

    queue<pair<pair<int, int>, int> > q;
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            if(grid[i][j] == 1){
                q.push(make_pair(make_pair(i, j), 0));
                vis[i][j] = 1;
            }
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 4 && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push(make_pair(make_pair(nrow, ncol), steps + 1));
            }
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }

    return 0;
}
