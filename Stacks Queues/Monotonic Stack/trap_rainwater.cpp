#include<iostream>
#include<algorithm>
using namespace std;

//TC - O(n + n + n)
//SC - O(2n)
int bruteForce(int height[], int n) {
    if(n<=2)
        return 0;

    int prefix_max[n];
    int suffix_max[n];

    prefix_max[0] = height[0];
    suffix_max[n-1] = height[n-1];

    for(int i = 1; i<n; i++)
        prefix_max[i] = max(prefix_max[i-1], height[i]);

    for(int i = n - 2; i>=0; i--)
        suffix_max[i] = max(suffix_max[i+1], height[i]);

    int ans = 0;

    for(int i = 1; i<n-1; i++) {
        int left = prefix_max[i-1];
        int right = suffix_max[i+1];
        int diff = min(left, right) - height[i];

        if(diff > 0)
            ans += diff;
    }
    
    return ans;
}

//TC - O(n)
//SC - O(1)
int optimised(int height[], int n) {
    int leftMax = 0;
    int rightMax = 0;

    int left = 0;
    int right = n - 1;

    int ans = 0;

    while(left <= right) {
        if(height[left] <= height[right]) {
            if(height[left] > leftMax) leftMax = height[left];
            else 
                ans += leftMax - height[left];

            left++;
        }
        else {
            if(height[right] > rightMax) rightMax = height[right];
            else 
                ans += rightMax - height[right];

            right--;
        }
    }

    return ans;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(int);

    cout << bruteForce(height, n) << endl;
    cout << optimised(height, n) << endl;

    return 0;
}
