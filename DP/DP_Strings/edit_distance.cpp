#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int recursion(int i, int j, string s1, string s2) {
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(s1[i] == s2[j])
        return 0 + recursion(i - 1, j - 1, s1, s2);

    int insert = 1 + recursion(i, j - 1, s1, s2);
    int deletion = 1 + recursion(i - 1, j, s1, s2);
    int replace = 1 + recursion(i - 1, j - 1, s1, s2);

    return min(insert, min(deletion, replace));
}

int memoization(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 0 + memoization(i - 1, j - 1, s1, s2, dp);

    int insert = 1 + memoization(i, j - 1, s1, s2, dp);
    int deletion = 1 + memoization(i - 1, j, s1, s2, dp);
    int replace = 1 + memoization(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = min(insert, min(deletion, replace));
}

int tabulation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= M; i++)
        dp[0][i] =  i;

    for(int j = 0; j <= N; j++)
        dp[j][0] = j;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else {
                int insert = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(insert, min(deletion, replace));
            }
        }
    }

    return dp[N][M];
}

int space_optimisation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int prev[M + 1];
    memset(prev, 0, sizeof(prev));

    for(int i = 0; i <= M; i++)
        prev[i] = i;

    int curr[M + 1];
    memset(curr, 0, sizeof(curr));

    for(int i = 1; i <= N; i++) {
        curr[0] = i;

        for(int j = 1; j <= M; j++) {
            if(s1[i - 1] == s2[j - 1])
                curr[j] = 0 + prev[j - 1];
            else {
                int insert = 1 + curr[j - 1];
                int deletion = 1 + prev[j];
                int replace = 1 + prev[j - 1];

                curr[j] = min(insert, min(deletion, replace));
            }
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[M];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    int N = word1.length();
    int M = word2.length();

    vector<vector<int>> dp (N, vector<int>(M, -1));

    cout << recursion(N - 1, M - 1, word1, word2) << endl;
    cout << memoization(N - 1, M - 1, word1, word2, dp) << endl;
    cout << tabulation(word1, word2) << endl;
    cout << space_optimisation(word1, word2) << endl;

    return 0;
}
