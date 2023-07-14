/*
Exactly same as subset sum equals k
Logic

 - Subset 1 = Subset 2
 - Subset 1 + Subset 2 = Total Sum
 - 2 * Subset 1 = Total Sum
 - Subset 1 = Total Sum / 2 = Subset 2

 Hence, we need to find a subset with sum equal to Total Sum / 2
 if Total Sum is odd, equal partition is not possible

 Recursion, Tabulation, Memoization can be referred from that file
 Only Space Optimization implemented here
*/


#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool partitionPossible(vector<int>& arr, int N) {
    int totalSum = 0;
    for(int i = 0; i < N; i++)
        totalSum += arr[i];
    
    if(totalSum % 2 == 1) return false;

    int target = totalSum / 2;

    bool prev[target + 1];
    memset(prev, false, sizeof(prev));
    prev[0] = true;

    if(arr[0] <= target) prev[arr[0]] = true;

    bool curr[target + 1];
    memset(curr, true, sizeof(curr));
    for(int index = 1; index < N; index++) {

        for(int target_state = 1; target_state <= target; target_state++) {
            bool pick = false;

            if(arr[index] <= target_state)
                pick = prev[target_state - arr[index]];

            bool not_pick = prev[target_state];

            curr[target_state] = pick || not_pick;
        }

        memcpy(prev, curr, sizeof(curr));
    }
    
    return prev[target];
}

int main(){
    vector<int> arr = {1, 2, 3};
    int N = 3;

    cout << partitionPossible(arr, N) << endl;
    return 0;
}
