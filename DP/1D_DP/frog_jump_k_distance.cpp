#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int n, int k, vector<int>& heights) {
    if(n == 0) return 0;
    int minJumpCost = 1e9;

    for(int i = 1; i<=k; i++) {
        if(n - i >= 0) {
            int jumpsCost = recursion(n - i, k, heights) + abs(heights[n] - heights[n - i]);
            minJumpCost = min(minJumpCost, jumpsCost);
        }
    }

    return minJumpCost;
}

int memoization(int n, int k, vector<int>& heights, vector<int>& dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    int minJumpCost = 1e9;

    for(int i = 1; i<=k; i++) {
        if(n - i >= 0) {
            int jumpsCost = memoization(n - i, k, heights, dp) + abs(heights[n] - heights[n - i]);
            minJumpCost = min(minJumpCost, jumpsCost);
        }
    }

    return dp[n] = minJumpCost;
}

int tabulation(int n, int k, vector<int>& heights, vector<int>& dp) {
    dp[0] = 0;

    for(int i = 1; i<=n; i++) {
        int minJumpCost = 1e9;

        for(int j = 1; j<=k; j++) {
            if(i - j >= 0) {
                int jumpsCost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minJumpCost = min(minJumpCost, jumpsCost);
            }
        }

        dp[i] = minJumpCost;
    }

    return dp[n];
}

int main() {
    int k = 3;
    int n = 5;
    vector<int> heights = {10, 30, 40, 50, 20};
    vector<int> dp(n, -1);
    
    cout << recursion(n - 1, k, heights) << endl; 
    //cout << memoization(n - 1, k, heights, dp) << endl;
    cout << tabulation(n - 1, k, heights, dp) << endl;
    return 0;
}


/*
This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.
*/
