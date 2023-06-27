#include <iostream>
#include <unordered_map>
using namespace std;

int atMost(int nums[], int n, int goal)
    {
        int start=0, end=0, ans=0,count=0;
        if (goal < 0)
            return 0;
        for(end=0; end < n; end++)
        {
            count+=nums[end];
            while(count>goal)
            {
                count-=nums[start];
                start++;
            }
            ans+=end-start+1;
        }
        return ans;
    }

//Optimal (Constant Space Complexity)
int numSubarraysWithSum1(int nums[], int n, int goal) {
    return atMost(nums, n, goal) - atMost(nums, n, goal-1);
}

int numSubarraysWithSum2(int arr[], int n, int sum){
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

    cout << numSubarraysWithSum1(arr, n, 2);

    return 0;
}

/*
The code consists of two functions: atMost and numSubarraysWithSum.

Function atMost:

It takes an array nums, the size of the array n, and the goal sum goal as input.
It initializes variables start and end to represent the start and end indices of the current subarray, ans to store the count of subarrays satisfying the condition, and count to keep track of the current sum.
It checks if the goal is less than 0. If so, it returns 0, as there cannot be any subarrays with a negative sum.
It iterates over the array using the end index.
In each iteration, it adds the current element nums[end] to the count.
It enters a while loop to shrink the window by incrementing the start index if the count exceeds the goal.
In each iteration of the while loop, it subtracts the element at nums[start] from the count and increments the start index.
After exiting the while loop, it updates the ans by adding the length of the current subarray, which is end - start + 1.
Finally, it returns the ans, which represents the count of subarrays satisfying the condition.
Function numSubarraysWithSum:

It takes an array nums, the size of the array n, and the goal sum goal as input.
It calls the atMost function twice to calculate the count of subarrays with a sum at most goal and the count of subarrays with a sum at most goal-1.
It subtracts the count of subarrays with a sum at most goal-1 from the count of subarrays with a sum at most goal and returns the result. This gives the count of subarrays with a sum exactly equal to goal.
The main idea behind this implementation is that atMost(nums, n, goal) calculates the count of subarrays with a sum at most goal, and atMost(nums, n, goal-1) calculates the count of subarrays with a sum at most goal-1. By subtracting the latter from the former, we get the count of subarrays with a sum equal to goal.
*/
