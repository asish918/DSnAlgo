/*
Cooldown

Similar to Buy and Sell 2
Changed condition - 
Cannot buy immediately after selling

Hence instead of moving index + 1, move to index + 2 after selling

*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int tabulation(vector<int>& price) {
    int N = price.size();

    int dp[N + 2][2];
    memset(dp, 0, sizeof(dp));

    for(int index = N - 1; index >= 0; index--) {
        dp[index][1] = max(-price[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
        dp[index][0] = max(price[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
    }

    return dp[0][1];
}

int space_optimisation(vector<int>& price) {
    int N = price.size();

    int frontRow1[2];
    int frontRow2[2];
    memset(frontRow1, 0, sizeof(frontRow1));
    memset(frontRow2, 0, sizeof(frontRow2));

    int curr[2];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        curr[1] = max(-price[index] + frontRow1[0], 0 + frontRow1[1]);
        curr[0] = max(price[index] + frontRow2[1], 0 + frontRow1[0]);

        memcpy(frontRow2, frontRow1, sizeof(frontRow1));
        memcpy(frontRow1, curr, sizeof(curr));
    }

    return curr[1];
}

int main() {
    vector<int> price = {1, 2, 3, 0, 2};
    
    cout << tabulation(price) << endl;
    cout << space_optimisation(price) << endl;

    return 0;
}
