#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int bruteForce(vector<int>& nums, int k) {
    int i = 0, n = nums.size(), curr = 0, count = 0;

    for(i = 0; i<n; i++){
        if(nums[i] % 2 == 0)
            nums[i] = 0;
        else
            nums[i] = 1;
    }

    unordered_map<int, int> mp;
    mp[0] = 1;

    for(i = 0; i < n; i++){
        curr+=nums[i];
        if(mp[curr - k])
            count+=mp[curr - k];
        mp[curr]++;
    }

    return count;
}

//Optimal (constant space)
int countNiceSubarr(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0;
    int right = 0;
    int odd_count = 0;
    int count_subarr = 0;

    while(right < n) {
        if(arr[right] % 2 == 1)
            odd_count++;

        while(odd_count > k) {
            if(arr[left] % 2 == 1)
                odd_count--;
            left++;
        }

        count_subarr += (right - left + 1);
        right++;
    }

    return count_subarr;
}

int main(){
    vector<int> nums = {1, 1, 2, 1, 1};

    cout << countNiceSubarr(nums, 3) - countNiceSubarr(nums, 3 - 1) << endl;

    return 0;
}
