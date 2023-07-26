/*
Alternate approach of using transaction state and eliminating buy and cap states

Transaction States - 
B S B S (Length 4)
0 1 2 3

As we buy or sell at a particular index, the transaction state moves forward
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int recursion(int index, int transaction, vector<int>& price) {
    if((unsigned long)index == price.size() || transaction == 4)
        return 0;
    
    if(transaction % 2 == 0)
        return max(-price[index] + recursion(index + 1, transaction + 1, price), 0 + recursion(index + 1, transaction, price));

    return max(price[index] + recursion(index + 1, transaction + 1, price), 0 + recursion(index + 1, transaction, price));
}

int memoization(int index, int transaction, vector<int>& price, vector<vector<int>>& dp) {
    if((unsigned long)index == price.size() || transaction == 4)
        return 0;

    if(dp[index][transaction] != -1) return dp[index][transaction];

    if(transaction % 2 == 0)
        return dp[index][transaction] = max(-price[index] + memoization(index + 1, transaction + 1, price, dp), 0 + memoization(index + 1, transaction, price, dp));

    return dp[index][transaction] = max(price[index] + memoization(index + 1, transaction + 1, price, dp), 0 + memoization(index + 1, transaction, price, dp));
}

int tabulation(vector<int>& price) {
    int N = price.size();

    int dp[N + 1][4 + 1];
    memset(dp, 0, sizeof(dp));

    for(int index = N - 1; index >= 0; index--) {
        for(int transaction = 3; transaction >= 0; transaction--) {
            if(transaction % 2 == 0)
                dp[index][transaction] = max(-price[index] + dp[index + 1][transaction + 1], 0 + dp[index + 1][transaction]);
            else
                dp[index][transaction] = max(price[index] + dp[index + 1][transaction + 1], 0 + dp[index + 1][transaction]);
        }
    }

    return dp[0][0];
}

int space_optimisation(vector<int>& price) {
    int N = price.size();
    
    int frontRow[4 + 1];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[4 + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        for(int transaction = 3; transaction >= 0; transaction--) {
            if(transaction % 2 == 0)
                curr[transaction] = max(-price[index] + frontRow[transaction + 1], 0 + frontRow[transaction]);
            else
                curr[transaction] = max(price[index] + frontRow[transaction + 1], 0 + frontRow[transaction]);
        }

        memcpy(frontRow, curr, sizeof(curr));
    }

    return frontRow[0];
}

int main() {
    vector<int> price = {10, 22, 5, 75, 65, 80};
    int N = price.size();

    vector<vector<int>> dp(N + 1, vector<int>(4, -1));

    cout << recursion(0, 0, price) << endl;
    cout << memoization(0, 0, price, dp) << endl;
    cout << tabulation(price) << endl;
    cout << space_optimisation(price) << endl;

    return 0;
}
