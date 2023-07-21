/*
#### Question exactly similar to count subsets with sum k and count subsets with partition difference d
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int space_optimisation(vector<int>& arr, int target) {
    int N = arr.size();

    int prev[target + 1];
    int curr[target + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    if(arr[0] == 0) {
        prev[0] = 2;
        curr[0] = 2;
    }
    else {
        prev[0] = 1;
        curr[0] = 1;
        if(arr[0] <= target) prev[arr[0]] = 1;
    }

    for(int index = 1; index < N; index++) {
        for(int currTarget = 0; currTarget <= target; currTarget++) {
            int pick = 0;

            if(arr[index] <= currTarget)
                pick = prev[currTarget - arr[index]];
            
            int not_pick = prev[currTarget];

            curr[currTarget] = pick + not_pick;
        }
        
        memcpy(prev, curr, sizeof(curr));
    }

    return prev[target];
}

int main() {
    vector<int> arr {1, 1, 1, 1, 1};
    int target = 3;
    int N = arr.size();

    int totalSum = 0;
    for(int i = 0; i < N; i++)
        totalSum += arr[i];

    if(totalSum - target < 0 || (totalSum - target) % 2 == 1) {
        cout << "Not Possible";
        return 0;
    }

    int sumTarget = (totalSum - target) / 2;

    cout << space_optimisation(arr, sumTarget) << endl;
    return 0;
}
