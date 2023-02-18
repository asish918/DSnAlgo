#include <iostream>
#include <unordered_map>
using namespace std;

//int atMost(vector<int>& nums, int goal)
    //{
        //int window_start=0, window_end=0, ans=0,count=0;
        //if (goal < 0)
            //return 0;
        //for(window_end=0; window_end<nums.size() ;window_end++)
        //{
            //count+=nums[window_end];
            //while(count>goal)
            //{
                //count-=nums[window_start];
                //window_start++;
            //}
            //ans+=window_end-window_start+1;
        //}
        //return ans;
    //}
    //int numSubarraysWithSum(vector<int>& nums, int goal) {
        //return atMost(nums,goal)-atMost(nums,goal-1);
    //}

int numSubarraysWithSum(int arr[], int n, int sum){
    unordered_map<int, int> mp;
    mp[0] = 1;

    int curr = 0;
    int count = 0;

    for(int i = 0; i<n; i++){
        curr+=arr[i];
        if(mp[curr - sum])
            count+=mp[curr-sum];
        mp[curr]++;
    }

    return count;
}

int main(){
    int arr[] = {1, 0, 1, 0, 1};
    int n = sizeof(arr) / sizeof(int);

    cout << numSubarraysWithSum(arr, n, 2);

    return 0;
}
