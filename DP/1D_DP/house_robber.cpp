/*
First variant - exactly same to same as max_sum_non_adjacent

Second Variant - See the code below (slight change as first element's neighbour would be the last element)

Hence first and last cannot be considered together. Therefore we divide them in two exclusive arrays and find the maximum of both
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int space_optimisation(vector<int> houses) {
    int prev = houses[0];
    int prev2 = 0;

    for(int i = 1; i<houses.size(); i++) {
        int pick = houses[i] + prev2;
        int not_pick = 0 + prev;

        int curri = max(pick, not_pick);
        prev2 = prev;
        prev = curri;
    }

    return prev;
}

int main() {
    int n = 3;
    vector<int> houses = {2, 3, 2};

    vector<int> firstHouseExclude;
    vector<int> lastHouseExclude;
    
    for(int i = 0; i<n; i++) {
        if(i != 0) firstHouseExclude.push_back(houses[i]);
        if(i != n - 1) lastHouseExclude.push_back(houses[i]);
    }

    int ans = max(space_optimisation(firstHouseExclude), space_optimisation(lastHouseExclude));

    cout << ans << endl;
    return 0;
}
