#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int index, int W, int wt[], int val[]) {
    if(index == 0) {
        return (W / wt[0]) * val[0];
    }

    int pick = 0;
    if(wt[index] <= W)
        pick = val[index] + recursion(index, W - wt[index], wt, val);
    int not_pick = recursion(index - 1, W, wt, val);

    return max(pick, not_pick);
}

int memoization(int index, int W, int wt[], int val[], vector<vector<int>>& dp) {

    if(index == 0) {
        return (W / wt[0]) * val[0];
    }

    if(dp[index][W] != -1) return dp[index][W];

    int pick = 0;
    if(wt[index] <= W)
        pick = val[index] + memoization(index, W - wt[index], wt, val, dp);
    int not_pick = memoization(index - 1, W, wt, val, dp);

    return dp[index][W] = max(pick, not_pick);
}

int tabulation(int W, int wt[], int val[], int N) {

    int dp[N][W + 1];
    memset(dp, 0, sizeof(dp));

    for(int weight = 0; weight <= W; weight++)
        dp[0][weight] = (weight / wt[0]) * val[0];

    for(int index = 1; index < N; index++) {
        for(int weight = 1; weight <= W; weight++) {
            int pick = 0;
            if(wt[index] <= weight)
                pick = val[index] + dp[index][weight - wt[index]];
            int not_pick = 0 + dp[index - 1][weight];
            dp[index][weight] = max(pick, not_pick);
        }
    }

    return dp[N - 1][W];
}

int space_optimization(int W, int wt[], int val[], int N) {
    int prev[W + 1];
    memset(prev, 0, sizeof(prev));

    for(int weight = 0; weight <= W; weight++)
        prev[weight] = (weight / wt[0]) * val[0];

    int curr[W + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int weight = 1; weight <= W; weight++) {
            int pick = 0;
            if(wt[index] <= weight)
                pick = val[index] + curr[weight - wt[index]];
            int not_pick = prev[weight];
            curr[weight] = max(pick, not_pick);
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[W];
}


int ultra_space_optimization(int W, int wt[], int val[], int N) {
    int prev[W + 1];
    memset(prev, 0, sizeof(prev));

    for(int weight = 0; weight <= W; weight++)
        prev[weight] = (weight / wt[0]) * val[0];

    for(int index = 1; index < N; index++) {
        for(int weight = 1; weight <= W; weight++) {
            int pick = 0;
            if(wt[index] <= weight)
                pick = val[index] + prev[weight - wt[index]];
            int not_pick = prev[weight];
            prev[weight] = max(pick, not_pick);
        }
    }

    return prev[W];
}

int main() {
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int N = 4;
    int W = 8;

    vector<vector<int>> dp(N, vector<int>(W + 1, -1));

    cout << recursion(N - 1, W, wt, val) << endl;
    cout << memoization(N - 1, W, wt, val, dp) << endl;
    cout << tabulation(W, wt, val, N) << endl;
    cout << space_optimization(W, wt, val, N) << endl;
    cout << ultra_space_optimization(W, wt, val, N) << endl;

    return 0;
}
