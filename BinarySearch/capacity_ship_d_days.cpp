#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

bool isShippingPossible(int arr[], int n, int mid, int days){
    int d = 1;
    int sum = 0;

    for(int i = 0; i<n; i++){
        sum+=arr[i];

        if(sum > mid){
            d++;
            sum = arr[i];
        }
    }

    if(d <= days)
        return true;
    else
        return false;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(int);
    int d = 5;

    int low = 0;
    int high = 0;
    int ans = 0;

    for(int i = 0; i<n; i++){
        high+=arr[i];
        low = max(low, arr[i]);
    }

    if(d == n){
        cout << low << endl;
        return 0;
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        if(isShippingPossible(arr, n, mid, d)){
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << ans << endl;
    
    return 0;
}