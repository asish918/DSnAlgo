#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 5, 3, 2};
    int N = nums.size();

    vector<int> dp1(N, 1);
    vector<int> dp2(N, 1);

    for(int index = 0; index < N; index++) {
        for(int prev_index = 0; prev_index < index; prev_index++) {
            if(nums[prev_index] < nums[index] && 1 + dp1[prev_index] > dp1[index])
                dp1[index] = 1 + dp1[prev_index];
        }
    }

    for(int index = N - 1; index >= 0; index--) {
        for(int prev_index = N - 1; prev_index > index; prev_index--) {
            if(nums[prev_index] < nums[index] && 1 + dp2[prev_index] > dp2[index])
                dp2[index] = 1 + dp2[prev_index];
        }
    }

    int maxAns = 0;
    for(int i = 0; i < N; i++) {
        maxAns = max(maxAns, dp1[i] + dp2[i] - 1);
    }

    cout << maxAns << endl;

    return 0;
}
