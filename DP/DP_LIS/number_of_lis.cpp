#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 4, 7};
    int N = arr.size();

    vector<int> dp(N, 1);
    vector<int> cnt(N, 1);

    int maxLen = 0;
    for(int index = 0; index < N; index++) {
        for(int prev_index = 0; prev_index < index; prev_index++) {
            if(arr[prev_index] < arr[index] && 1 + dp[prev_index] > dp[index]) {
                dp[index] = 1 + dp[prev_index];
                cnt[index] = cnt[prev_index];
            }
            else if(arr[prev_index] < arr[index] && 1 + dp[prev_index] == dp[index]) 
                cnt[index] += cnt[prev_index];
        }

        maxLen = max(maxLen, dp[index]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(dp[i] == maxLen) ans += cnt[i];
    }

    cout << ans << endl;

    return 0;
}
