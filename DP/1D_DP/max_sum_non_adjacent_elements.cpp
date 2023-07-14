#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int index, vector<int>& arr) {
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    int pick = arr[index] + recursion(index - 2, arr);
    int not_pick = 0 + recursion(index - 1, arr);
    return max(pick, not_pick);
}

int memoization(int index, vector<int>& arr, vector<int>& dp) {
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];
    int pick = arr[index] + memoization(index - 2, arr, dp);
    int not_pick = 0 + memoization(index - 1, arr, dp);

    return dp[index] = max(pick, not_pick);
}

int tabulation(int index, vector<int>& arr, vector<int>& dp) {
    dp[0] = arr[0];

    for(int i = 1; i<=index; i++) {
        int pick = arr[i];
        if(i > 1)
            pick += dp[i - 2];
        int not_pick = 0 + dp[i - 1];

        dp[i] = max(pick, not_pick);
    }

    return dp[index];
}

int space_optimization(int index , vector<int>& arr) {
    int prev = arr[0];
    int prev2 = 0;

    for(int i = 1; i<=index; i++) {
        int pick = arr[i] + prev2;
        int not_pick = 0 + prev;
        
        int curri = max(pick, not_pick);
        prev2 = prev;
        prev = curri;
    }

    return prev;;
}

int main(){
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int n = 6;

    vector<int> dp(n, -1);

    cout << recursion(n - 1, arr) << endl;
    //cout << memoization(n, arr, dp) << endl;
    cout << tabulation(n - 1, arr, dp) << endl;
    cout << space_optimization(n - 1, arr) << endl;

    return 0;
}
