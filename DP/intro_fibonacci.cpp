#include<iostream>
#include<vector>
using namespace std;

//Basic Recursion
//TC - O(2^n)
//SC - O(n)
int recursion(int n) {
    if(n <= 1)
        return n;

    return recursion(n - 1) + recursion(n - 2);
}

//Memoization (Top - Down)
//TC - O(n)
//SC - O(n) + O(n)
int memoization(int n, vector<int>& dp) {
    if(n <= 1)
        return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp); 
}

//Tabulation (Bottom -Up)
//TC SC similar to memoization
int tabulation(int n, vector<int>& dp) {
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i<=5; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

//Space Optimization
//TC - O(n);
//SC - O(1);
int space_optimization(int n) {
    int prev = 1, prev2 = 0;

    for(int i = 2; i <= n; i++) {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }

    return prev;
}

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);

    cout << recursion(n) << endl;
    cout << memoization(n, dp) << endl;
    //cout << tabulation(n, dp) << endl;
    cout << space_optimization(n) << endl;

    return 0;
}
