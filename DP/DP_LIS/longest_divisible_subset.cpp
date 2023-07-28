#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 8};

    sort(arr.begin(), arr.end());

    int N = arr.size();
    int hashInd[N];
    memset(hashInd, 0, sizeof(hashInd));

    vector<int> dp(N, 1);

    int maxLen = 0;
    int maxInd = 0;

    for(int index = 0; index < N; index++) {
        hashInd[index] = index;

        for(int prev_index = 0; prev_index < index; prev_index++) {
            if(arr[index] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[index]) {
                dp[index] = 1 + dp[prev_index];
                hashInd[index] = prev_index;
            }
        }

        if(dp[index] > maxLen) {
            maxLen = dp[index];
            maxInd = index;
        }
    }

    vector<int> ans;
    ans.push_back(arr[maxInd]);
    while(hashInd[maxInd] != maxInd) {
        maxInd = hashInd[maxInd];
        ans.push_back(arr[maxInd]);
    }

    reverse(ans.begin(), ans.end());

    for(auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}
