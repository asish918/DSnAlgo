#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int i, int j, vector<vector<int>>& triangle) {
    int n = triangle.size();

    if(i == n - 1) return triangle[i][j];

    int down = triangle[i][j] + recursion(i + 1, j, triangle);
    int diagonal = triangle[i][j] + recursion(i + 1, j + 1, triangle);

    return min(down, diagonal);
}

int memoization(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    int n = triangle.size();

    if(i == n - 1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + memoization(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + memoization(i + 1, j + 1, triangle, dp);

    return dp[i][j] = min(down, diagonal);
}

int tabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>>dp (n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) 
        dp[n - 1][i] = triangle[n - 1][i];

    for(int row = n - 2; row >= 0; row--) {
        for(int col = row; col >= 0; col--) {
            int down = triangle[row][col] + dp[row + 1][col];
            int diagonal = triangle[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(down, diagonal);
        } 
    }

    return dp[0][0];
}

int space_optimisation(vector<vector<int>>& triangle) {
    int n = triangle.size();

    int frontRow[n];
    for(int i = 0; i < n; i++)
        frontRow[i] = triangle[n - 1][i];

    int curr[n];
    for(int row = n - 2; row >= 0; row--) {
        memset(curr, 0, sizeof(curr));
        for(int col = row; col >= 0; col--) {
            int down = triangle[row][col] + frontRow[col];
            int diagonal = triangle[row][col] + frontRow[col + 1];

            curr[col] = min(down, diagonal);
        }

        memcpy(frontRow, curr, sizeof(curr));
    }

    return frontRow[0];
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << recursion(0, 0, triangle) << endl;
    cout << memoization(0, 0, triangle, dp) << endl;
    cout << tabulation(triangle) << endl;
    cout << space_optimisation(triangle) << endl;
    return 0;
}
