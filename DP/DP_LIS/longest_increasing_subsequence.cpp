#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursion(int index, int prev_ind, vector<int>& arr) {
    int N = arr.size();

    if(index == N)
        return 0;

    int pick = 0;
    if(prev_ind == -1 || arr[index] > arr[prev_ind]) 
        pick = 1 + recursion(index + 1, index, arr);

    int not_pick = 0 + recursion(index + 1, prev_ind, arr);

    return max(pick, not_pick);
}

int memoization(int index, int prev_ind, vector<int>& arr, vector<vector<int>>& dp) {
    int N = arr.size();

    if(index == N)
        return 0;

    if(dp[index][prev_ind + 1] != -1) return dp[index][prev_ind + 1];

    int pick = 0;
    if(prev_ind == -1 || arr[index] > arr[prev_ind])
        pick = 1 + memoization(index + 1, index, arr, dp);

    int not_pick = memoization(index + 1, prev_ind, arr, dp);

    return dp[index][prev_ind + 1] = max(pick, not_pick);
}

int tabulation(vector<int>& arr) {
    int N = arr.size();
    
    int dp[N + 1][N + 1];
    memset(dp, 0, sizeof(dp));

    for(int index = N - 1; index >= 0; index--) {
        for(int prev_index = index - 1; prev_index >= -1; prev_index--) {
            int pick = 0;
            if(prev_index == -1 || arr[prev_index] < arr[index])
                pick = 1 + dp[index + 1][index + 1];

            int not_pick = 0 + dp[index + 1][prev_index + 1];
            dp[index][prev_index + 1] = max(pick, not_pick);
        }
    }

    return dp[0][-1 + 1];
}

int space_optimisation(vector<int>& arr) {
    int N = arr.size();

    int frontRow[N + 1];
    memset(frontRow, 0, sizeof(frontRow));

    int curr[N + 1];
    memset(curr, 0, sizeof(curr));

    for(int index = N - 1; index >= 0; index--) {
        for(int prev_index = index - 1; prev_index >= -1; prev_index--) {
            int pick = 0;
            if(prev_index == -1 || arr[index] > arr[prev_index])
                pick = 1 + frontRow[index + 1];

            int not_pick = 0 + frontRow[prev_index + 1];
            curr[prev_index + 1] = max(pick, not_pick);
        }

        memcpy(frontRow, curr, sizeof(curr));
    }

    return frontRow[-1 + 1];
}

//Alternate Approach (To backtrack and print the LIS)
void printLIS(vector<int>& arr) {
    int N = arr.size();

    vector<int> dp(N, 1); //Every element has 1 LIS upto its index in the beginning
    //The dp array essentially keeps track of LIS from 0 to that particular index

    int maxLen = 0;
    int maxInd = 0;
    int hashInd[N];
    memset(hashInd, 0, sizeof(hashInd));

    for(int index = 0; index < N; index++) {
        hashInd[index] = index;

        for(int prev_index = 0; prev_index < index; prev_index++) {
            if(arr[prev_index] < arr[index] && 1 + dp[prev_index] > dp[index]) {
                dp[index] = 1 + dp[prev_index];
                hashInd[index] = prev_index;
            }
        }

        if(dp[index] > maxLen) {
            maxLen = dp[index];
            maxInd = index;
        }
    }

    vector<int> lis;
    lis.push_back(arr[maxInd]);
    while(hashInd[maxInd] != maxInd) {
        maxInd = hashInd[maxInd];
        lis.push_back(arr[maxInd]);
    }

    reverse(lis.begin(), lis.end());

    for(auto it : lis)
        cout << it << " ";
    cout << endl;
}

//Most optimal way of finding only length of LIS (nlogn compared to n^2 in previous methods)
int optimalLengthLIS(vector<int>& arr) {
    int N = arr.size();

    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1; i < N; i++) {
        if(arr[i] > temp.back())
            temp.push_back(arr[i]);
        else {
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }

    return temp.size();
}

int main() {
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int N = arr.size();

    vector<vector<int>> dp(N, vector<int> (N + 1, -1));
    
    cout << recursion(0, -1, arr) << endl;
    cout << memoization(0, -1, arr, dp) << endl;
    cout << tabulation(arr) << endl;
    cout << space_optimisation(arr) << endl;

    printLIS(arr);

    cout << optimalLengthLIS(arr) << endl;

    return 0;
}
