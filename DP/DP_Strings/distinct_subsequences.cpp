#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int recursion(int i, int j, string s, string t) {
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(s[i] == t[j])
        return recursion(i - 1, j - 1, s, t) + recursion(i - 1, j, s, t);

    return recursion(i - 1, j, s, t);
}

int memoization(int i, int j, string s, string t, vector<vector<int>>& dp) {
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = memoization(i - 1, j - 1, s, t, dp) + memoization(i - 1, j, s, t, dp);

    return dp[i][j] = memoization(i - 1, j, s, t, dp);
}

int tabulation(string s, string t) {
    int N = s.length();
    int M = t.length();

    int dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[N][M];
}

int space_optimisation(string s, string t) {
    int N = s.length();
    int M = t.length();

    int prev[M + 1];
    int curr[M + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    prev[0] = 1;
    curr[0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                curr[j] = prev[j];
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[M];
}

int main() {
    string s = "babgbag";
    string t = "bag";

    int N = s.length();
    int M = t.length();

    vector<vector<int>> dp(N, vector<int>(M, -1));

    cout << recursion(N - 1, M - 1, s, t) << endl;
    cout << memoization(N - 1, M - 1, s, t, dp) << endl;
    cout << tabulation(s, t) << endl;
    cout << space_optimisation(s, t) << endl;

    return 0;
}
