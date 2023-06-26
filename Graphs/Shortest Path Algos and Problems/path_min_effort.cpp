#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

void minimumEffort(vector<vector<int>> heights){
    int n = heights.size();
    int m = heights[0].size();

    priority_queue<pair<int ,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    vector<vector<int>> diff(n, vector<int> (m, 1e9));

    diff[0][0] = 0;
    q.push({0, {0, 0}});

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        auto it = q.top();
        q.pop();

        int nodeDiff = it.first;
        int r = it.second.first;
        int c = it.second.second;
        
        if(r == n - 1 && c == m - 1){
            cout << nodeDiff << endl;
            return;
        }

        for(int i = 0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                int newEffort = max(abs(heights[nrow][ncol] - heights[r][c]), nodeDiff);
                
                if(newEffort < diff[nrow][ncol]){
                    diff[nrow][ncol] = newEffort;
                    q.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5},
    };
    
    minimumEffort(heights);

    return 0;
}
