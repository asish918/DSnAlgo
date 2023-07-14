/*
#### Base Case change for array values equal to zero
For Eg - N = 3
        arr = 0, 0, 1
        sum = 1

        Output - 1
        Expected Output - 4

// For recursion && memoization
if(index == 0) {
    if(sum == 0 && arr[0] == 0) return 2;  //taking a zero or not taking wont alter the sum, hence two possibilities, take or don't take
    if(sum == 0 && arr[0] != sum) return 1; //Only one possibility, not taking it
    if(sum != 0 && arr[0] == sum) return 1; //Only one possibility, take it
    else 0;
}

//For tabulation && space optimization
if(arr[0] == 0) dp[0][0] = 2;
else {
dp[0][0] = 1;
if(arr[0] <= sum) dp[0][arr[0]] = 1;
}

*/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int recursion(int i, int sum, vector<int>& arr) {
    if(i == 0) {
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 && arr[0] != 0) return 1;
        if(sum != 0 && arr[0] == sum) return 1;
        else return 0;
    }

    int pick = 0;
    if(arr[i] <= sum)
        pick = recursion(i - 1, sum - arr[i], arr);

    int not_pick = recursion(i - 1, sum, arr);

    return pick + not_pick;
}

int memoization(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    if(i == 0) {
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 && arr[0] != 0) return 1;
        if(sum != 0 && arr[0] == sum) return 1;
        else return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    int pick = 0;
    if(arr[i] <= sum)
        pick = memoization(i - 1, sum - arr[i], arr, dp);

    int not_pick = memoization(i - 1, sum, arr, dp);

    return dp[i][sum] = pick + not_pick;
}

int tabulation(vector<int>& arr, int sum) {
    int N = arr.size();
    
    int dp[N][sum + 1];
    memset(dp, 0, sizeof(dp));

    if(arr[0] == 0)
        dp[0][0] = 2;
    else {
        dp[0][0] = 1;
        if(arr[0] <= sum) dp[0][arr[0]] = 1;
    }

    for(int index = 1; index < N; index++){
        for(int target = 0; target <= sum; target++) { //we don't start from 1 because we are counting and hence the entire 1st column will not be 1, we add the count of subsets with sum 0 incrementally as the index increases
            int pick = 0;
            
            if(arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];

            int not_pick = dp[index - 1][target];

            dp[index][target] = not_pick + pick;
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

int main(){
    int N = 10;
    vector<int> arr = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int sum = 31;

    vector<vector<int>> dp(N, vector<int> (sum + 1, -1));

    cout << recursion(N - 1, sum, arr) << endl;
    cout << memoization(N - 1, sum, arr, dp) << endl;
    cout << tabulation(arr, sum) << endl;
    cout << space_optimisation(arr, sum) << endl;
    return 0;
}
