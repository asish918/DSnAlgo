//Also goes by the name - Split Array Largest Sum

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& nums, int k, int bar) {
    int count = 1, totalSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > bar)
            return false;
        else if(totalSum + nums[i] > bar) {
            count++;
            totalSum = nums[i];
        }
        else
            totalSum += nums[i];
    }

    if(count > k)
        return false;

    return true;
}

int bruteForce(vector<int>& nums, int k) {
    int n = nums.size();

    int low = 0;
    int high = 0;

    for(int i = 0; i < n; i++) {
        high += nums[i];
        low = max(low, nums[i]);
    }

    int ans = 1e9;
    for(int i = low; i <= high; i++) {
        if(isPossible(nums, k, i))
            ans = min(ans, i);
    }

    return ans;
}

int optimal(vector<int>& nums, int k) {
    int low = 0;
    int high = 0;

    int n = nums.size();

    for(int i = 0; i < n; i++) {
        high += nums[i];
        low = max(low, nums[i]);
    }

    while(low < high) {
        int mid = (high - low)/2 + low;

        if(isPossible(nums, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    //Expected Output - 18

    cout << bruteForce(nums, k) << endl;

    //Binary Search
    cout << optimal(nums, k) << endl;
    return 0;
}
