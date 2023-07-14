#include <climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int recursion(int i, int j, vector<vector<int>>& grid) {
if (i == 0 && j == 0) return grid[i][j];
    
    if (i < 0|| j < 0) return INT_MAX;
    
    int leftCost = recursion(i, j - 1, grid);
    int upCost = recursion(i - 1, j, grid);
    
    return grid[i][j] + min(leftCost, upCost);
}

int memoization(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i == 0 && j == 0) return grid[i][j];
    if(i < 0 || j < 0) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    int leftCost = memoization(i, j - 1, grid, dp);
    int upCost = memoization(i - 1, j, grid, dp);
    return dp[i][j] = grid[i][j] + min(leftCost, upCost);
}

int tabulation(vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = INT_MAX;
                int left = INT_MAX;

                if(i > 0) up = grid[i][j] + dp[i - 1][j];
                if(j > 0) left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int space_optimised(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int prev[m];
    memset(prev, 0, sizeof(prev));

    int curr[m];
    for(int i = 0; i < n; i++) {
        memset(curr, 0, sizeof(curr));

        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) curr[j] = grid[i][j];
            else {
                int up = INT_MAX;
                int left = INT_MAX;

                if(i > 0) up = grid[i][j] + prev[j];
                if(j > 0) left = grid[i][j] + curr[j - 1];

                curr[j] = min(up, left);
            }
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[m - 1];
}

int main(){
    vector<vector<int>> grid = {
        {9, 4, 9, 9},
        {6, 7, 6, 4},
        {8, 3, 3, 7},
        {7, 4, 9, 10}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << recursion(n - 1, m - 1, grid) << endl;
    //cout << memoization(n - 1, m - 1, grid, dp) << endl;
    cout << tabulation(grid, dp) << endl;
    cout << space_optimised(grid) << endl;
    return 0;
}
