#include<iostream>
#include<algorithm>
using namespace std;

//O(n*n)
int bruteForce(int arr[], int n) {
    int ans = 0;

    for(int left = 0; left<n; left++) {
        int minVal = arr[left];
        int maxVal = arr[left];
        
        for(int right = left; right < n; right++) {
            minVal = min(minVal, arr[right]);
            maxVal = max(maxVal, arr[right]);

            ans += (maxVal - minVal);
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(int);

    cout << bruteForce(nums, n) << endl;
    return 0;
}
