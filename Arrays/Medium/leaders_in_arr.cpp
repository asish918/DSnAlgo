#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {16, 17, 3, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(int);

    vector<int> ans;

    ans.push_back(arr[n-1]);
    int maxi = arr[n-1];

    for(int i = n-2; i>=0; i--){
        maxi = max(maxi, arr[i]);
        if(maxi == arr[i]){
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());


    for(auto j : ans){
        cout << j << " ";
    }
    
    return 0;
}