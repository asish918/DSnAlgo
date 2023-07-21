#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int subarrCount(int arr[], int n, int k) {
    int count_subarr = 0;
    int left = 0;
    int right = 0;

    unordered_map<char, int> intFreq;

    while(right < n) {
        intFreq[arr[right]]++;

        while(intFreq.size() > k) {
            intFreq[arr[left]]--;

            if(intFreq[arr[left]] == 0)
                intFreq.erase(arr[left]);

            left++;
        }

        count_subarr += right - left + 1;

        right++;
    }

    return count_subarr;
}

int main() {
    int arr[] = {1, 2, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << subarrCount(arr, n, 2) - subarrCount(arr, n, 2 - 1) << endl;
    return 0;
}

/*
 The formula right - left + 1 essentially indicates count of subarrays ending at right index.
 Detailed explaination and dry run below
To count the number of subarrays ending at the current right pointer, we need to consider the possible combinations of the left pointer's position with the fixed right pointer. As the right pointer iterates through the array, we consider different subarrays that end at that position.

Let's take an example:

Suppose we have an array: [3, 4, 5, 3, 2], and we want to find the count of subarrays with at most 2 distinct elements.

Initialize two pointers, left and right, both pointing to the start of the array.
Move the right pointer to the right and keep track of the elements and their frequency within the current window.
If the number of distinct elements within the window is greater than k (which is 2 in this case), move the left pointer to contract the window from the left until the number of distinct elements is at most k.
Now, let's see how the expression right - left + 1 represents the count of subarrays ending at the current right pointer:

When the right pointer is at position 1 (element 4), the window contains [3, 4], and there are 2 subarrays ending at the right pointer: [3, 4] and [4].

When the right pointer moves to position 2 (element 5), the window contains [3, 4, 5], and there are 3 subarrays ending at the right pointer: [3, 4, 5], [4, 5], and [5].

When the right pointer moves to position 3 (element 3), the window contains [4, 5, 3], and there are 3 subarrays ending at the right pointer: [4, 5, 3], [5, 3], and [3].

When the right pointer moves to position 4 (element 2), the window contains [5, 3, 2], and there are 3 subarrays ending at the right pointer: [5, 3, 2], [3, 2], and [2].

As you can see, for each position of the right pointer, the count of subarrays ending at that position is equal to right - left + 1.

Therefore, the expression right - left + 1 gives us the count of subarrays ending at the current right pointer and containing at most k distinct elements. By incrementing the right pointer and using this expression, we can consider all possible valid subarrays and accumulate the total count in the result variable.
*/
