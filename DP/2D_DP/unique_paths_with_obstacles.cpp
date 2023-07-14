#include <cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int n, int m, vector<vector<int>>& arr) {
    if(n >= 0 && m >= 0 && arr[n][m] == 1) return 0;
    if(n == 0 && m == 0) return 1;
    if(n < 0 || m < 0) return 0;

    int left = recursion(n, m - 1, arr);
    int up = recursion(n - 1, m, arr);

    return left + up;
}

int memoization(int n, int m, vector<vector<int>>& dp, vector<vector<int>>& arr) {
    if(n >= 0 && m >= 0 && arr[n][m] == 1) return 0;
    if(n == 0 && m == 0) return 1;
    if(n < 0 || m < 0) return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    int left = recursion(n, m - 1, arr);
    int up = recursion(n - 1, m, arr);

    return dp[n][m] = left + up;
}

int tabulation(int n, int m, vector<vector<int>>& arr) {
    vector<vector<int>> dp(n, vector<int> (m, -1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int space_optimization(int n, int m, vector<vector<int>>& arr) {
    int prev[m];
    memset(prev, 0, sizeof(prev));

    int curr[m];
    for(int i = 0; i < n; i++) {
        memset(curr, 0, sizeof(curr));

        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) curr[j] = 0;
            else if(i == 0 && j == 0) curr[j] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j - 1];
                curr[j] = up + left;
            }
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[m - 1];
}

int main(){
    int n = 3;
    int m = 3;
    vector<vector<int>> arr = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << recursion(n - 1, m - 1, arr) << endl;
    cout << memoization(n - 1, m - 1, dp, arr) << endl;
    cout << tabulation(n, m, arr) << endl;
    cout << space_optimization(n, m, arr) << endl;

    return 0;
}
