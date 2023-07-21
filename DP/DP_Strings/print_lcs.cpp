#include<iostream>
#include<cstring>
using namespace std;

string tabulation(string s1, string s2) {
    int N = s1.length();
    int M = s2.length();

    int dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= M; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            else
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
        }
    }

    int lcsLen = dp[N][M];
    int index = lcsLen;
    string lcs('s', lcsLen);

    int i = N, j = M;

    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs[index--] = s1[i - 1];

            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int main() {
    string text1 = "ABCDGH";
    string text2 = "AEDFHR";
    
    cout << tabulation(text1, text2) << endl;

    return 0;
}
