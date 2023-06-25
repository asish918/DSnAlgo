#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int mid, int cows) {
    int currentStall = arr[0];
    int currCount = 1;

    for(int i = 1; i<n; i++) {
        if(arr[i] - currentStall >= mid) {
            currCount++;
            currentStall = arr[i];
        }
    }

    if(currCount >= cows) return true;
    return false;
} 

int main() {
    int arr[] = {1, 2, 4, 8, 9};
    int n = 5;
    int k = 3;

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int res = -1;

    while(low<=high) {
        int mid = (high - low)/2 + low;

        if(isPossible(arr, n, mid, k)) {
            res = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }

    cout << res << endl;
    return 0;
}
