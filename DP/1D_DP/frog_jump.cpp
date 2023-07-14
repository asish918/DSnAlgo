#include <cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int n, vector<int>& heights) {
    if(n == 0) return 0;
    
    int left = recursion(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int right = 1e9;

    if(n > 1)
        right = recursion(n - 2, heights) + abs(heights[n] - heights[n - 2]);

    return min(left, right);
}

int memoization(int n, vector<int>& heights, vector<int>& dp) {
    if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    int left = memoization(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = 1e9;

    if(n > 1)
        right = memoization(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);

    return dp[n] = min(left, right);
}

int tabulation(int n, vector<int>& heights, vector<int>& dp) {
    dp[0] = 0;

    for(int i = 1; i<=n; i++) {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = 1e9;

        if(i > 1) 
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[n];
}

int space_optimised(int n, vector<int>& heights) {
    int prev = 0, prev2 = 1e9;

    for(int i = 1; i<=n; i++) {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = prev2;

        if(i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);

        int curri = min(left, right);
        prev2 = prev;
        prev = curri;
    }

    return prev;
}

int main() {
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    vector<int> dp(n + 1, -1);

    //n - 1 since it asks min energy from 0 to n - 1 index
    cout << recursion(n - 1, heights) << endl;
    //cout << memoization(n - 1, heights, dp) << endl;
    cout << tabulation(n - 1, heights, dp) << endl;;
    cout << space_optimised(n - 1, heights) << endl;
}

/*
###### Problem Statement
Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/
