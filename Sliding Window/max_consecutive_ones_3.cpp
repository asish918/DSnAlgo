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
