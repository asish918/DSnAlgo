#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int recursion(int index, int sum, vector<int>& arr) {
    if(index == 0) {
        if(sum % arr[0] == 0) return 1;
        else return 0;
    }

    int pick = 0;
    if(arr[index] <= sum)
        pick = recursion(index, sum - arr[index], arr);
    int not_pick = recursion(index - 1, sum, arr);

    return pick + not_pick;
}

int memoization(int index, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    if(index == 0) {
        if(sum % arr[0] == 0) return 1;
        else return 0;
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    int pick = 0;
    if(arr[index] <= sum)
        pick = memoization(index, sum - arr[index], arr, dp);
    int not_pick = memoization(index - 1, sum, arr, dp);

    return dp[index][sum] = pick + not_pick;
}

int tabulation(vector<int>& arr, int sum) {
    int N = arr.size();

    int dp[N][sum + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= sum; i++) {
        if(i % arr[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }

    for(int index = 1; index < N; index++) {
        for(int target = 0; target <= sum; target++) {
            int pick = 0;
            if(arr[index] <= target)
                pick = dp[index][target - arr[index]];
            int not_pick = dp[index - 1][target];

            dp[index][target] = pick + not_pick;
        }
    }

    return dp[N - 1][sum];
}

int space_optimization(vector<int>& arr, int sum) {
    int N = arr.size();
    
    int prev[sum + 1];
    memset(prev, 0, sizeof(prev));

    for(int i = 0; i <= sum; i++) {
        if(i % arr[0] == 0) prev[i] = 1;
        else prev[i] = 0;
    }

    int curr[sum + 1];
    memset(curr, 0, sizeof(curr));
    
    for(int index = 1; index < N; index++) {
        for(int target = 0; target <= sum; target++) {
            int pick = 0;
            if(arr[index] <= target)
                pick = curr[target - arr[index]];
            int not_pick = prev[target];
            curr[target] = pick + not_pick;
        }
        
        memcpy(prev, curr, sizeof(curr));
    }
    
    return prev[sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    int N = coins.size();

    vector<vector<int>> dp(N, vector<int>(sum + 1, -1));

    cout << recursion(N - 1, sum, coins) << endl;
    cout << memoization(N - 1, sum, coins, dp) << endl;
    cout << tabulation(coins, sum) << endl;
    cout << space_optimization(coins, sum) << endl;

    return 0;
}
