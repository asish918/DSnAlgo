#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int recursion(int index, int rodLen, vector<int>& price) {
    if(index == 0) {
        return rodLen * price[0];
    }

    int pick = 0;
    int currRodLen = index + 1;

    if(currRodLen <= rodLen)
        pick = price[index] + recursion(index, rodLen - currRodLen, price);
    int not_pick = recursion(index - 1, rodLen, price);

    return max(pick, not_pick);
}

int memoization(int index, int rodLen, vector<int>& price, vector<vector<int>>& dp) {
    if(index == 0)
        return rodLen * price[0];

    if(dp[index][rodLen] != -1) return dp[index][rodLen];

    int pick = 0;
    int currRodLen = index + 1;

    if(currRodLen <= rodLen)
        pick = price[index] + memoization(index, rodLen - currRodLen, price, dp);
    int not_pick = memoization(index - 1, rodLen, price, dp);

    return dp[index][rodLen] = max(pick, not_pick);
}

int tabulation(vector<int>& price, int rodLen) {
    int N = price.size();

    int dp[N][rodLen + 1];
    memset(dp, 0, sizeof(dp));

    for(int len = 0; len <= rodLen; len++)
        dp[0][len] = len * price[0];

    for(int index = 1; index < N; index++) {
        for(int currRodLen = 1; currRodLen <= rodLen; currRodLen++) {
            int pick = 0;
            
            int len = index + 1;
            if(len <= currRodLen)
                pick = price[index] + dp[index][currRodLen - len];
            int not_pick = dp[index - 1][currRodLen];

            dp[index][currRodLen] = max(pick, not_pick);
        }
    }

    return dp[N - 1][rodLen];
}

int space_optimisation(vector<int>& price, int rodLen) {
    int N = price.size();

    int prev[rodLen + 1];
    memset(prev, 0, sizeof(prev));

    for(int len = 0; len <= rodLen; len++)
        prev[len] = len * price[0];

    int curr[rodLen + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int currRodLen = 1; currRodLen <= rodLen; currRodLen++) {
            int pick = 0;
            
            int len = index + 1;
            if(len <= currRodLen)
                pick = price[index] + curr[currRodLen - len];
            int not_pick = prev[currRodLen];

            curr[currRodLen] = max(pick, not_pick);
        }

        memcpy(prev, curr, sizeof(curr));
    }
    
    return prev[rodLen];
}


int ultra_space_optimisation(vector<int>& price, int rodLen) {
    int N = price.size();

    int prev[rodLen + 1];
    memset(prev, 0, sizeof(prev));

    for(int len = 0; len <= rodLen; len++)
        prev[len] = len * price[0];

    for(int index = 1; index < N; index++) {
        for(int currRodLen = 1; currRodLen <= rodLen; currRodLen++) {
            int pick = 0;
            
            int len = index + 1;
            if(len <= currRodLen)
                pick = price[index] + prev[currRodLen - len];
            int not_pick = prev[currRodLen];

            prev[currRodLen] = max(pick, not_pick);
        }
    }
    
    return prev[rodLen];
}

int main() {
    vector<int> price = {1, 1, 3, 4, 4, 6, 8, 9, 11};
    int N = price.size();
    int rodLen = 9;

    vector<vector<int>> dp(N, vector<int>(rodLen + 1, -1));

    cout << recursion(N - 1, rodLen, price) << endl;
    cout << memoization(N - 1, rodLen, price, dp) << endl;
    cout << tabulation(price, rodLen) << endl;
    cout << space_optimisation(price, rodLen) << endl;
    cout << ultra_space_optimisation(price, rodLen) << endl;

    return 0;
}
