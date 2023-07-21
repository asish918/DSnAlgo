#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int recursion(int index, int amount, vector<int>& coins) {
    if(index == 0) {
        if(amount % coins[0] == 0) return amount / coins[0];
        else return 1e9;
    }

    int pick = 1e9;
    if(coins[index] <= amount) 
        pick = 1 + recursion(index, amount - coins[index], coins);

    int not_pick = 0 + recursion(index - 1, amount, coins);

    return min(pick, not_pick);
}

int memoization(int index, int amount, vector<int>& arr, vector<vector<int>>& dp) {
    if(index == 0) {
        if(amount % arr[0] == 0) return amount / arr[0];
        else return 1e9;
    }

    if(dp[index][amount] != -1) return dp[index][amount];

    int pick = 1e9;
    if(arr[index] <= amount)
        pick = 1 + memoization(index, amount - arr[index], arr, dp);

    int not_pick = 0 + memoization(index - 1, amount, arr, dp);

    return dp[index][amount] = min(pick, not_pick);
}

int tabulation(vector<int>& arr, int amount) {
    int N = arr.size();

    int dp[N][amount + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= amount; i++) 
        if(i % arr[0] == 0) dp[0][i] = i / arr[0];
        else dp[0][i] = 1e9;

    for(int index = 1; index < N; index++) {
        for(int currAmount = 1; currAmount <= amount; currAmount++) { //Another base case of if(amount == 0) return 0 can be added to the recursion, hence the currAmount can definitely start from 1 because if currAmount becomes 0, we can't pick anymore coins (0)
            int pick = 1e9;

            if(arr[index] <= currAmount)
                pick = 1 + dp[index][currAmount - arr[index]];
            int not_pick = dp[index - 1][currAmount];

            dp[index][currAmount] = min(pick, not_pick);
        }
    }

    return dp[N - 1][amount];
}

int space_optimisation(vector<int>& arr, int amount) {
    int N = arr.size();

    int prev[amount + 1];
    memset(prev, 0, sizeof(prev));

    for(int i = 0; i <= amount; i++) {
        if(i % arr[0] == 0) prev[i] = i / arr[0];
        else prev[i] = 1e9;
    }

    int curr[amount + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int currAmount = 1; currAmount <= amount; currAmount++) {
            int pick = 1e9;

            if(arr[index] <= currAmount)
                pick = 1 + curr[currAmount - arr[index]];
            int not_pick = prev[currAmount];

            curr[currAmount] = min(pick, not_pick);
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int N = coins.size();

    int amount = 11;

    vector<vector<int>> dp(N, vector<int>(amount + 1, -1));

    cout << recursion(N - 1, amount, coins) << endl;
    cout << memoization(N - 1, amount, coins, dp) << endl;
    cout << tabulation(coins, amount) << endl;
    cout << space_optimisation(coins, amount) << endl;

    return 0;
}
