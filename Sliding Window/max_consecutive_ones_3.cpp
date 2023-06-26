#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxConsecutiveOne3(int arr[], int n, int k){
    int i = 0, j = 0, zeroCount = 0, ans = INT_MIN;

    while(j < n){
        if(arr[j] == 0)
            zeroCount++;

        while(zeroCount > k){
            if(arr[i] == 0)
                zeroCount--;
            i++;
        }
       
        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main(){
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    cout << maxConsecutiveOne3(arr, n, k);

    return 0;
}

/*
The function longestOnes takes an input array nums and an integer k as parameters.

Initialize variables n to store the length of the array, left and right pointers to represent the sliding window, maxOnes to keep track of the maximum consecutive 1's encountered so far, and zerosCount to count the number of 0's within the window.

Use a while loop that runs until the right pointer reaches the end of the array.

Inside the loop:

If the current element at nums[right] is 0, increment zerosCount to track the number of 0's within the window.
If the number of 0's within the window exceeds k, enter the inner while loop to adjust the window by moving the left pointer forward. If the element at nums[left] is 0, decrement zerosCount.
Calculate the length of the current consecutive sequence of 1's using right - left + 1.
Update maxOnes with the maximum length encountered so far.
Move the right pointer forward.
Finally, return maxOnes, which represents the maximum number of consecutive 1's considering the allowed flips of at most k 0's.
*/
