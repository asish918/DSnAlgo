#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

void betterApproach(vector<int> arr, int k){
    int n = arr.size();

    map<int, int> mpp;
    int len = 0;
    int sum = 0;

    for(int i = 0; i<n; i++){
        sum += arr[i];

        if(sum == k)
            len = i + 1;

        int target = sum - k;

        if(mpp.find(target) != mpp.end())
            len = max(len, i - mpp[target]);

        if(mpp.find(sum) == mpp.end())
            mpp[sum] = i;
    }

    cout << len << endl;
}

void bruteForce(vector<int> arr, int k){
    int len = INT_MIN;
    int n = arr.size();

    for(int i = 0; i<n; i++){
        int sum = 0;
        
        for(int j = i; j<n; j++){
            sum += arr[j];

            if(sum == k)
                len = max(len, j - i + 1);
        }
    }

    cout << len << endl;
}

void optimalApproach(vector<int> arr, int k){
    int n = arr.size();
    
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int len = 0;

    while(right < n){
        while(sum > k && left <= right){
            sum -= arr[left];
            left++;
        }

        if(sum == k)
            len = max(len, right - left + 1);

        right++;
        sum += arr[right];
    }

    cout << len << endl;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1 , 9};
    int k = 15;

    //TC - (O(n^2))
    //SC - (O(1))
    //bruteForce(arr, k);

    //Optimal if array has positives, negatives and zeroes
    //TC - (O(nlogn))
    //SC - (O(n))
    //betterApproach(arr, k);

    //Optimal only for positives
    //TC - (O(n))
    //SC - (O(1))
    optimalApproach(arr, k);

    return 0;
}
