#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(int arr[], int n, int k){
    int i = 0, j = 0, count = 0, sum = 0;
    unordered_map<int, int> mp;

    while(j < n){
        sum += arr[j];
        if(sum == k) count++;
        if(mp.find(sum - k) != mp.end()) count+=mp[sum-k];

        mp[sum]++;
        j++;
    }

    return count;
}

int main(){
    int arr[] = {1, 1, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    cout << subarraySum(arr, n, k);

    return 0;
}
