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
The left + 1 represents the number of subarrays that can be formed starting from index 0 up to the current left pointer.
*/
