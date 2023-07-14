#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int recursion(int index, int sum, vector<int>& arr) {
    if(index == 0) {
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 && arr[0] != 0) return 1;
        if(sum != 0 && arr[0] == sum) return 1;
        else return 0;
    }

    int pick = 0;
    if(arr[index] <= sum)
        pick = recursion(index - 1, sum - arr[index], arr);

    int not_pick = recursion(index - 1, sum, arr);
    return pick + not_pick;
}

int memoization(int index, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    if(index == 0) {
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 && arr[0] != 0) return 1;
        if(sum != 0 && arr[0] == sum) return 1;
        else return 0;
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    int pick = 0;
    if(arr[index] <= sum)
        pick = memoization(index - 1, sum - arr[index], arr, dp);
    int not_pick = memoization(index - 1, sum, arr, dp);

    return dp[index][sum] = pick + not_pick;
}

int tabulation(vector<int>& arr, int sum) {
    int N = arr.size();
    
    vector<vector<int>> dp (N, vector<int> (sum + 1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else {
        dp[0][0] = 1;

        if(arr[0] <= sum) dp[0][arr[0]] = 1;
    }

    for(int index = 1; index < N; index++) {
        for(int target = 0; target <= sum; target++) {
            int pick = 0;
            if(arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];
            int not_pick = dp[index - 1][target];

            dp[index][target] = pick + not_pick;
        }
    }

    return dp[N - 1][sum];
}

int space_optimisation(vector<int>& arr, int sum) {
    int N = arr.size();
    
    int prev[sum + 1];
    memset(prev, 0, sizeof(prev));
    int curr[sum + 1];
    memset(curr, 0, sizeof(curr));

    if(arr[0] == 0) {
        prev[0] = 2;
        curr[0] = 2;
    }
    else {
        prev[0] = 1;
        curr[0] = 1;
        if(arr[0] <= sum) prev[arr[0]] = 1;
    }


    for(int index = 1; index < N; index++) {
        for(int target = 0; target <= sum; target++) {
            int pick = 0;

            if(arr[index] <= target)
                pick = prev[target - arr[index]];
            int not_pick = prev[target];

            curr[target] = pick + not_pick;
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[sum];
}

int main() {
    int N = 4;
    int d = 3;
    vector<int> arr = {5, 2, 6, 4};

    int totalSum = 0;
    for(int i = 0; i < N; i++) 
        totalSum += arr[i];

    if(totalSum - d < 0 || (totalSum - d) % 2 == 1) {
        cout << "Not Possible" << endl;
        return 0;
    }

    int target = (totalSum - d) / 2;

    vector<vector<int>> dp(N, vector<int> (target + 1, -1));

    cout << recursion(N - 1, target, arr) << endl;
    cout << memoization(N - 1, target, arr, dp) << endl;
    cout << tabulation(arr, target) << endl;
    cout << space_optimisation(arr, target) << endl;
    return 0;
}
