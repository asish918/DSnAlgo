#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int recursion(int i, int j1, int j2, vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();

    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return INT_MIN;
    if(i == n - 1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxChocolates = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if(j1 == j2) value += grid[i][j1];
            else value += grid[i][j1] + grid[i][j2];

            value += recursion(i + 1, j1 + dj1, j2 + dj2, grid);
            maxChocolates = max(value, maxChocolates);
        }
    }

    return maxChocolates;
}

int memoization(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    int n = grid.size();
    int m = grid[0].size();

    if(j1 < 0 || j2  < 0 || j1 >= m || j2 >= m) return INT_MIN;
    if(i == n - 1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxChocolates = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if(j1 == j2) value += grid[i][j1];
            else value += grid[i][j1] + grid[i][j2];

            value += memoization(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            
            maxChocolates = max(value, maxChocolates);
        }
    } 

    return dp[i][j1][j2] = maxChocolates;
}

int tabulation(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));
    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2) dp[n-1][j1][j2] = grid[n - 1][j1];
            else dp[n-1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for(int i = n - 2; i>=0; i--) {
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];

                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];

                        dp[i][j1][j2] = max(value, dp[i][j1][j2]);
                    }
                } 
            }
        }
    }

    return dp[0][0][m - 1];
}

int space_optimisation(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int front[m][m];
    memset(front, 0, sizeof(front));

    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2) front[j1][j2] = grid[n-1][j1];
            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    int curr[m][m];
    for(int i = n - 2; i>=0; i--) {
        memset(curr, 0, sizeof(curr));

        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];

                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += front[j1 + dj1][j2 + dj2];

                        curr[j1][j2] = max(value, curr[j1][j2]);
                    }
                } 
            }
        }

        memcpy(front, curr, sizeof(curr));
    }

    return front[0][m-1];
}

int main() {
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1},
    };
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

    cout << recursion(0, 0, m - 1, grid) << endl;
    cout << memoization(0, 0, m - 1, grid, dp) << endl;
    cout << tabulation(grid) << endl;
    cout << space_optimisation(grid) << endl;
    return 0;
}
