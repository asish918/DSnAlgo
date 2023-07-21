#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void tabulation(string s1, string s2) {
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

    cout << "Length - " << N - dp[N][M] + M << endl;;

    int i = N;
    int j = M;
    string scs = "";

    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            scs += s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            scs += s1[i - 1];
            i--;
        }
        else {
            scs += s2[j - 1];
            j--;
        }
    }

    while(i > 0) {
        scs += s1[i - 1];
        i--;
    }

    while(j > 0) {
        scs += s2[j - 1];
    }

    cout << "String - " << scs << endl;
}

int main() {
    string x = "abcd";
    string y = "xycd";

    tabulation(x, y);

    return 0;
}
