#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;

int recursion(int index, int W, vector<int>& val, vector<int>& wt) {
    if(index == 0) {
        if(wt[0] <= W) return val[0];
        else return 0;
    }
    
    int pick = INT_MIN;
    if(wt[index] <= W)
        pick = val[index] + recursion(index - 1, W - wt[index], val, wt);
    int not_pick = 0 + recursion(index - 1, W, val, wt);

    return max(pick, not_pick);
}

int memoization(int index, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if(index == 0) {
        if(wt[0] <= W) return val[0];
        return 0;
    }

    if(dp[index][W] != -1) return dp[index][W];

    int pick = INT_MIN;
    if(wt[index] <= W)
        pick = val[index] + memoization(index - 1, W - wt[index], val, wt, dp);
    int not_pick = 0 + memoization(index - 1, W, val, wt, dp);

    return dp[index][W] = max(pick, not_pick);
} 

int tabulation(vector<int>& val, vector<int>& wt, int W) {
    int N = val.size();

    int dp[N][W + 1];
    memset(dp, 0, sizeof(dp));

    for(int weight = wt[0]; weight <= W; weight++)
        dp[0][weight] = val[0];

    for(int index = 1; index < N; index++) {
        for(int currWeight = 0; currWeight <= W; currWeight++) { // we can start from 1 because if the curr bag weight happens to be zero, we won't be able to steal the item anyways. The dp[0][0] column is initialised to 0 (this base case i.e if(W == 0) return 0 can be added in recursion too)
            int pick = INT_MIN;
            if(wt[index] <= currWeight)
                pick = val[index] + dp[index - 1][currWeight - wt[index]];
            
            int not_pick = 0 + dp[index - 1][currWeight];

            dp[index][currWeight] = max(pick, not_pick);
        }
    }

    return dp[N - 1][W];
}

int space_optimisation(vector<int>& val, vector<int>& wt, int W) {
    int N = val.size();

    int prev[W + 1];
    memset(prev, 0, sizeof(prev));

    for(int weight = wt[0]; weight <= W; weight++)
        prev[weight] = val[0];

    int curr[W + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int currWeight = 0; currWeight <= W; currWeight++) {
            int pick = INT_MIN;

            if(wt[index] <= currWeight)
                pick = val[index] + prev[currWeight - wt[index]];

            int not_pick = 0 + prev[currWeight];

            curr[currWeight] = max(pick, not_pick);
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[W];
}

int ultra_space_optimisation(vector<int>& val, vector<int>& wt, int W) {
    int N = val.size();

    int row[W + 1];
    memset(row, 0, sizeof(row));

    for(int weight = wt[0]; weight <= W; weight++)
        row[weight] = val[0];

    for(int index = 1; index < N; index++) {
        for(int currWeight = W; currWeight >= 0; currWeight--) {
            int pick = INT_MIN;

            if(wt[index] <= currWeight)
                pick = val[index] + row[currWeight - wt[index]];

            int not_pick =  0 + row[currWeight];
            
            row[currWeight] = max(not_pick, pick);
        }
    }

    return row[W];
}

int main() {
    int N = 3;
    int W = 4;

    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};

    vector<vector<int>> dp (N, vector<int>(W + 1, -1));

    cout << recursion(N - 1, W, val, wt) << endl;
    cout << memoization(N - 1, W, val, wt, dp) << endl;
    cout << tabulation(val, wt, W) << endl;
    cout << space_optimisation(val, wt, W) << endl;
    cout << ultra_space_optimisation(val, wt, W) << endl;

    return 0;
}
