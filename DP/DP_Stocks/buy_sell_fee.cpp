/*
Again very similar to buy and sell 2

There's a fee for each transaction

Meaning we need to subtract the fee from each individual transaction
i.e For each buy and sell - fee applied once:  price[index] - fee + ....

*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int space_optimisation(vector<int>& price, int fee) {
    int N = price.size();
    
    int frontRow[2];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[2];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        curr[1] = max(-price[index] + frontRow[0], 0 + frontRow[1]);
        curr[0] = max(price[index] - fee + frontRow[1], 0 + frontRow[0]);

        memcpy(frontRow, curr, sizeof(curr));
    }

    return frontRow[1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    
    cout << space_optimisation(prices, fee) << endl; 

    return 0;
}
