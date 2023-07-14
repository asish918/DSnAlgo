/* Variable starting point and variable ending point */
//Max Path
#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int recursion(int i, int j, vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(j < 0 || j >= m) return INT_MIN;
    if(i == 0) return grid[i][j];

    int up = grid[i][j] + recursion(i - 1, j, grid);
    int upRight = grid[i][j] + recursion(i - 1, j + 1, grid);
    int upLeft = grid[i][j] + recursion(i - 1, j - 1, grid);

    int maxPoints = max(up, max(upRight, upLeft));

    return maxPoints;
}

int memoization(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int m = grid.size();

    if(j < 0 || j >= m) return INT_MIN;
    if(i == 0) return grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + memoization(i - 1, j, grid, dp);
    int upLeft = grid[i][j] + memoization(i - 1, j - 1, grid, dp);
    int upRight = grid[i][j] + memoization(i - 1, j + 1, grid, dp);

    int maxPoints = max(up, max(upLeft, upRight));

    return dp[i][j] = maxPoints;
}

int tabulation(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int col = 0; col < m; col++)
        dp[0][col] = grid[0][col];

    for(int row = 1; row < n; row++) {
        for(int col = 0; col < m; col++) {
            int upLeft = INT_MIN;
            int upRight = INT_MIN;

            int up = grid[row][col] + dp[row - 1][col];
            if(col - 1 >= 0) upLeft = grid[row][col] + dp[row - 1][col - 1];
            if(col + 1 < m) upRight = grid[row][col] + dp[row - 1][col + 1];
            
            dp[row][col] = max(up, max(upRight, upRight));
        }
    }

    int maxPoints = 0;
    for(int col = 0; col < m; col++)
        maxPoints = max(maxPoints, dp[n - 1][col]);

    return maxPoints;
}

int space_optimisation(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int prev[m];
    for(int col = 0; col < m; col++)
        prev[col] = grid[0][col];

    int curr[m];
    for(int row = 1; row < n; row++){
        memset(curr, 0, sizeof(curr));

        for(int col = 0; col < m; col++) {
            int upLeft = INT_MIN;
            int upRight = INT_MIN;

            int up = grid[row][col] + prev[col];
            if(col - 1 >= 0) upLeft = grid[row][col] + prev[col - 1];
            if(col + 1 < m) upRight = grid[row][col] + prev[col + 1];

            curr[col] = max(up, max(upLeft, upRight));
        }

        memcpy(prev, curr, sizeof(curr));
    }

    int maxPoints = 0;
    for(int col = 0; col < m; col++)
        maxPoints = max(maxPoints, prev[col]);

    return maxPoints;
}

int main() {
    vector<vector<int>> grid = {
        {348, 391},
        {618, 193},
    };
    //1009
    
    int n = grid.size();
    int m = grid[0].size();
    
    //Recursion
    int maxPoints = 0;
    //for(int col = 0; col < m; col++)
    //    maxPoints = max(maxPoints, recursion(n - 1, col, grid));

    //Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int col = 0; col < m; col++)
        maxPoints = max(maxPoints, memoization(n - 1, col, grid, dp));
    cout << maxPoints << endl;

    //Tabulation
    cout << tabulation(grid) << endl;

    //Space Optimisation
    cout << space_optimisation(grid) << endl;
    return 0;
}
