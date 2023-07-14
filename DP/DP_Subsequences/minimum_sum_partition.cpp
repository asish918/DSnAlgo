#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

int tabulation(vector<int>& arr, int N) {
    int totalSum = 0;
    for(int i = 0; i < N; i++)
        totalSum += arr[i];

    bool dp[N][totalSum + 1];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i < N; i++)
        dp[i][0] = true;

    if(arr[0] <= totalSum) dp[0][arr[0]] = true;

    for(int index = 1; index < N; index++) {
        for(int target = 1; target <= totalSum; target++) {
            bool pick = false;
            if(arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];

            bool not_pick = dp[index - 1][target];
            dp[index][target] = pick || not_pick;
        }
    }

    int minSum = 1e9;
    for(int targetSum = 0; targetSum <= totalSum; targetSum++) {
        if(dp[N - 1][targetSum]) {
            int S1 = targetSum;
            int S2 = totalSum - targetSum;
            minSum = min(minSum, abs(S1 - S2));
        }
    }

    return minSum;
}

int space_optimisation(vector<int>& arr, int N) {
    int totalSum = 0;
    for(int i = 0; i < N; i++)
        totalSum += arr[i];

    bool prev[totalSum + 1];
    memset(prev, false, sizeof(prev));

    prev[0] = true;
    if(arr[0] <= totalSum) prev[arr[0]] = true;

    bool curr[totalSum + 1];
    memset(curr, true, sizeof(curr));

    for(int index = 1; index < N; index++) {
        for(int target = 1; target <= totalSum; target++) {
            bool pick = false;

            if(arr[index] <= target)
                pick = prev[target - arr[index]];

            bool not_pick = prev[target];

            curr[target] = pick || not_pick;
        }

        memcpy(prev, curr, sizeof(curr));
    }

    int minSum = 1e9;
    for(int targetSum = 0; targetSum <= totalSum / 2; targetSum++)
        if(prev[targetSum])
            minSum = min(minSum, abs(targetSum - (totalSum - targetSum)));

    return minSum;
}

int main(){
    vector<int> arr = {1, 6, 11, 5};
    int N = 4;
    
    cout << tabulation(arr, N) << endl;
    cout << space_optimisation(arr, N) << endl;
    return 0;
}
