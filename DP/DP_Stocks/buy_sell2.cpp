/*Buy and Sell any number of times*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int recursion(int index, int buy, vector<int>& price) {
    if((unsigned long)index == price.size())
        return 0;
    
    int profit = 0;
    if(buy) {
        profit = max(-price[index] + recursion(index + 1, 0, price), 0 + recursion(index + 1, 1, price));
    }
    else {
        profit = max(price[index] + recursion(index + 1, 1, price), 0 + recursion(index + 1, 0, price));
    }

    return profit;
}

int memoization(int index, int buy, vector<int>& price, vector<vector<int>>& dp) {
    if((unsigned long)index == price.size())
        return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if(buy) {
        profit = max(-price[index] + memoization(index + 1, 0, price, dp), 0 + memoization(index + 1, 1, price, dp));
    }
    else {
        profit = max(price[index] + memoization(index + 1, 1, price, dp), 0 + memoization(index + 1, 0, price, dp));
    }

    return dp[index][buy] = profit;
}

int tabulation(vector<int>& price) {
    int N = price.size();

    int dp[N + 1][2];
    memset(dp, 0, sizeof(dp));

    dp[N][0] = dp[N][1] = 0;
    
    for(int index = N - 1; index >= 0; index--) {
        dp[index][1] = max(-price[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
        dp[index][0] = max(price[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
    }

    return dp[0][1];
}

int space_optimisation(vector<int>& price) {
    int N = price.size();

    int frontRow[2];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[2];
    memset(curr, 0, sizeof(frontRow));

    for(int index = N - 1; index >= 0; index--) {
        curr[1] = max(-price[index] + frontRow[0], 0 + frontRow[1]);
        curr[0] = max(price[index] + frontRow[1], 0 + frontRow[0]);

        memcpy(frontRow, curr, sizeof(curr));
    }

    return frontRow[1];
}

int space_optimisation2(vector<int>& price) {
    int N = price.size();

    int aheadBuy = 0, aheadNotBuy = 0;
    int currBuy = 0, currNotBuy = 0; //currNotBuy essentially indicates that we are selling(since we are not buying)

    for(int index = N - 1; index >= 0; index--){
        currBuy = max(-price[index] + aheadNotBuy, 0 + aheadBuy);
        currNotBuy = max(price[index] + aheadBuy, 0 + aheadNotBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }

    return aheadBuy;
}

int main() {
    vector<int> price = {1, 2, 3, 4, 5, 6, 7};
    int N = price.size();

    vector<vector<int>> dp(N, vector<int>(2, -1));
    cout << recursion(0, 1, price) << endl;
    cout << memoization(0, 1, price, dp) << endl;
    cout << tabulation(price) << endl;
    cout << space_optimisation(price) << endl;
    cout << space_optimisation2(price) << endl;

    return 0;
}
