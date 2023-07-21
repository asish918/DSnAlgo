#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4}; //5
    int N = arr.size();

    int profit = 0;
    int minStock = 7;

    for(int i = 1; i < N; i++) {
        int cost = arr[i] - minStock;
        profit = max(profit, cost);
        minStock = min(arr[i], minStock);
    }

    cout << profit << endl; //max profit
    return 0;
}
