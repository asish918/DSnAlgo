/*Exactly Similar to Buy and Sell with at most 2 transactions

  Replace 2 with K

  For alternate approach - 
  4 Transactions states - 2
  2 * K Transaction states - K

  Hence only space optimisation implemented here

*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int space_optimisation(vector<int>& price, int K) {
    int N = price.size();

    int frontRow[2 * K + 1];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[2 * K + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        for(int transaction = 2 * K - 1; transaction >= 0; transaction--) {
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
    vector<int> arr = {20, 580, 420, 900};
    int K = 3;

    cout << space_optimisation(arr, K) << endl;

    return 0;
}
