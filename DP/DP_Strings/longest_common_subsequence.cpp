#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int recursion(int index1, int index2, string s1, string s2) {
    if(index1 < 0 || index2 < 0)
        return 0;

    if(s1[index1] == s2[index2])
        return 1 + recursion(index1 - 1, index2 - 1, s1, s2);

    return max(recursion(index1 - 1, index2, s1, s2), recursion(index1, index2 - 1, s1, s2)); 
}

int memoization(int index1, int index2, string s1, string s2, vector<vector<int>>& dp) {
    if(index1 < 0 || index2 < 0)
        return 0;

    if(dp[index1][index2] != -1) return dp[index1][index2];

    if(s1[index1] == s2[index2])
        return dp[index1][index2] = 1 + memoization(index1 - 1, index2 - 1, s1, s2, dp);

    return dp[index1][index2] = max(memoization(index1 - 1, index2, s1, s2, dp), memoization(index1, index2 - 1, s1, s2, dp));
}

int tabulation(string s1, string s2){
    int N = s1.length();
    int M = s2.length();

    vector<vector<int>> dp(N + 1, vector<int> (M + 1, -1));

    for(int i = 0; i <= N; i++) {
        dp[0][i] = 0;
    }

    for(int j = 0; j <= M; j++) {
        dp[j][0] = 0;
    }

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= M; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            else 
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    return dp[N][M];
}

int space_optimisation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int prev[M + 1];
    memset(prev, 0, sizeof(prev));

    int curr[M + 1];
    memset(curr, 0, sizeof(curr));

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= M; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                curr[index2] = 1 + prev[index2 - 1];
            else
                curr[index2] = max(prev[index2], curr[index2 - 1]);
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[M];
}

int main() {
    string text1 = "ABCDGH";
    string text2 = "AEDFHR";
    
    int N = text1.length();
    int M = text2.length();

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));

    cout << recursion(N - 1, M - 1, text1, text2) << endl;
    cout << memoization(N - 1, M - 1, text1, text2, dp) << endl;
    cout << tabulation(text1, text2) << endl;
    cout << space_optimisation(text1, text2) << endl;

    return 0;
}
