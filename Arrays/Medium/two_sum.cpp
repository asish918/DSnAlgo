#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

void twoSum1(vector<int> nums, int target){
    map<int, int> mpp;
    vector<int> ans;

    for(int i = 0; i<nums.size(); i++){
        if(mpp.find(target - nums[i]) != mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[target - nums[i]]);
        }
        mpp[nums[i]] = i;
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

void twoSum2(vector<int> nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    vector<int> ans;

    while(left < right){
        int sum = nums[left] + nums[right];

        if(sum == target){
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            break;
        }
        else if (sum < target) left++;
        else right--;
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    twoSum1(nums, target);
    twoSum2(nums, target);

    return 0;
}
