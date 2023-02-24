#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void subset_sum(int index, int arr[], int n, int sum, vector<int>& ds){
    if(index == n){
        ds.push_back(sum);
        return;
    }

    sum += arr[index];
    subset_sum(index + 1, arr, n, sum, ds);
    sum -= arr[index];
    subset_sum(index + 1, arr,  n, sum, ds);
}

int main(){
    vector<int> ds;

    int arr[] = {5, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    subset_sum(0, arr, n, 0, ds);

    sort(ds.begin(), ds.end());

    for(auto i : ds){
        cout << i << " ";
    }

    return 0;
}
