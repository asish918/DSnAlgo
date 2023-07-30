#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

bool isShippingPossible(int arr[], int n, int capacity, int days){
    int d = 1;
    int sum = 0;

    for(int i = 0; i<n; i++){
        sum+=arr[i];

        if(sum > capacity){
            d++;
            sum = arr[i];
        }
    }

    if(d <= days)
        return true;
    else
        return false;
}

int bruteForce(int arr[], int n, int days) {
    int high = 0;
    int low = 0;

    for(int i = 0; i < n; i++) {
        high += arr[i];
        low = max(low, arr[i]);
    }

    int ans = 1e9;
    for(int i = low; i <= high; i++) {
        if(isShippingPossible(arr, n, i, days))
            ans = min(ans, i);
    }

    return ans;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(int);
    int d = 5;

    int low = 0;
    int high = 0;

    for(int i = 0; i<n; i++){
        high+=arr[i];
        low = max(low, arr[i]);
    }

    if(d == n){
        cout << low << endl;
        return 0;
    }

    cout << bruteForce(arr, n, d) << endl;

    while(low < high){
        int mid = low + (high - low)/2;
        if(isShippingPossible(arr, n, mid, d)){
            high = mid;
        }

        else
            low = mid + 1;
    }

    cout << low << endl;
    
    return 0;
}
