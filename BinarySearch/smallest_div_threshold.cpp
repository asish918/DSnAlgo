#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;

bool isPossible(int arr[], int n, int mid, int th){
    int res = 0;
    for(int i = 0; i<n; i++){
        res+= (int)ceil(arr[i]*1.0 / mid);
    }

    if(res<=th)
        return true;
    else
        return false;
}

int bruteForce(int arr[], int th, int n) {
    int ans = 1e9;
    int low = 1;
    int high = -1e9;

    for(int i = 0; i < n; i++)
        high = max(high, arr[i]);

    for(int i = low; i <= high; i++) {
        if(isPossible(arr, n, i, th))
            ans = min(ans, i);
    }

    return ans;
}

int main(){
    int arr[] = {1, 2, 5, 9};
    int n = sizeof(arr) / sizeof(int);
    int th = 6;

    cout << bruteForce(arr, th, n) << endl;

    //Binary Search - Optimal
    int low = 1;
    int high = INT_MIN;
    int min_div = INT_MAX;

    for(int i = 0; i<n; i++){
        high = max(high, arr[i]);
    }

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, mid, th)){
            min_div = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << min_div << endl;
    
    return 0;
}
