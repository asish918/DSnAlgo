#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int tabulation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));

    int ans = 0;

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= M; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1]) {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                ans = max(ans, dp[index1][index2]);
            }
            else
                dp[index1][index2] = 0;
        }
    }

    return ans;
}


int space_optimisation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int prev[M + 1];
    int curr[M + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    int ans = 0;

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= M; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1]) {
                curr[index2] = 1 + prev[index2 - 1];
                ans = max(ans, curr[index2]);
            }
            else
                curr[index2] = 0;
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return ans;
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << tabulation(s1, s2) << endl;
    cout << space_optimisation(s1, s2) << endl;

    return 0;
}
