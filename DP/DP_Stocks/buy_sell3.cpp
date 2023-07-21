/*Buy and Sell stocks at most 2 times*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int recursion(int index, int buy, int cap, vector<int>& price) {
    if((unsigned long)index == price.size() || cap == 0) return 0;

    int profit = 0;
    if(buy) {
        profit = max(-price[index] + recursion(index + 1, 0, cap, price), 0 + recursion(index + 1, 1, cap, price));
    }
    else {
        profit = max(price[index] + recursion(index + 1, 1, cap - 1, price), 0 + recursion(index + 1, 0, cap, price));
    }

    return profit;
}

int memoization(int index, int buy, int cap, vector<int>& price, vector<vector<vector<int>>>& dp) {
    if((unsigned long)index == price.size() || cap == 0) return 0;

    int profit = 0;

    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

    if(buy) {
        profit = max(-price[index] + memoization(index + 1, 0, cap, price, dp), 0 + memoization(index + 1, 1, cap, price, dp));
    }
    else {
        profit = max(price[index] + memoization(index + 1, 1, cap - 1, price, dp), 0 + memoization(index + 1, 0, cap, price, dp));
    }

    return profit;
}

int tabulation(vector<int>& price) {
    int N = price.size();

    int dp[N + 1][2][3];
    memset(dp, 0, sizeof(dp));

    for(int index = N - 1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) { //cap == 0 is a base case which already zero by default
                int profit = 0;

                if(buy)
                    profit = max(-price[index] + dp[index + 1][0][cap], 0 + dp[index + 1][1][cap]);
                else
                    profit = max(price[index] + dp[index + 1][1][cap - 1], 0 + dp[index + 1][0][cap]);

                dp[index][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int space_optimisation(vector<int>& price) {
    int N = price.size();

    int frontRow[2][3];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[2][3];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                int profit = 0;

                if(buy)
                    profit = max(-price[index] + frontRow[0][cap], 0 + frontRow[1][cap]);
                else
                    profit = max(price[index] + frontRow[1][cap - 1], 0 + frontRow[0][cap]);

                curr[buy][cap] = profit;
            }
        }

        memcpy(frontRow, curr, sizeof(curr));
    }
    
    return frontRow[1][2];
}

int main() {
    vector<int> price = {10, 22, 5, 75, 65, 80};
    int N = price.size();

    vector<vector<vector<int>>> dp (N + 1, vector<vector<int>> (2, vector<int> (3, -1)));
    cout << recursion(0, 1, 2, price) << endl;
    cout << memoization(0, 1, 2, price, dp) << endl;
    cout << tabulation(price) << endl;
    cout << space_optimisation(price) << endl;

    return 0;
}
