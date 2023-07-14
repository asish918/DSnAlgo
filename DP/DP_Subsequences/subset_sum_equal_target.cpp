#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool recursion(int i, int target, vector<int>& arr) {
    if(target == 0) return true;
    if(i == 0) return arr[0] == target;

    bool pick = false;
    if(arr[i] <= target) 
        pick = recursion(i - 1, target - arr[i], arr);

    bool not_pick = recursion(i - 1, target, arr);
    
    return pick || not_pick;
}

bool memoization(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(i == 0) return target == arr[0];

    if(dp[i][target] != -1) return dp[i][target];

    bool pick = false;
    if(arr[i] <= target)
        pick = memoization(i - 1, target - arr[i], arr, dp);

    bool not_pick = memoization(i - 1, target, arr, dp);

    return dp[i][target] = pick || not_pick;
}

int tabulation(int N, int target, vector<int>& arr) {
    vector<vector<bool>> dp(N, vector<bool> (target + 1, false));
    
    for(int row = 0; row < N; row++)
        dp[row][0] = true;

    //Add a check if arr[0] <= target incase the constraints don't specify
    dp[0][arr[0]] = true;

    for(int index = 1; index < N; index++) {
        for(int target_state = 1; target_state <= target; target_state++) {
            bool pick = false;

            if(arr[index] <= target_state)
                pick = dp[index - 1][target_state - arr[index]];

            bool not_pick = dp[index - 1][target_state];
            
            dp[index][target_state] = pick || not_pick;
        }
    }

    return dp[N - 1][target];
}

bool space_optimisation(int N, int target, vector<int>& arr) {
    bool prev[target + 1];
    memset(prev, false, sizeof(prev));

    //Add a check if arr[0] <= target incase the constraints don't specify
    prev[0] = true;
    prev[arr[0]] = true;

    bool curr[target + 1];
    memset(curr, true, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int target_state = 1; target_state <= target; target_state++) {
            bool pick = false;

            if(arr[index] <= target_state)
                pick = prev[target_state - arr[index]];
            
            bool not_pick = prev[target_state];
            curr[target_state] = pick || not_pick;
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[target];
}

int main(){
    int N = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    vector<vector<int>> dp(N, vector<int>(sum + 1, -1));

    cout << recursion(N - 1, sum, arr) << endl;
    cout << memoization(N - 1, sum, arr, dp) << endl;
    cout << tabulation(N, sum, arr) << endl;
    cout << space_optimisation(N, sum, arr) << endl;

    return 0;
}
