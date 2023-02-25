#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void findCombo2(int index, int target, int n, int arr[], vector<int>& ds){
    if(target == 0){
        for(auto i : ds)
            cout << i << " ";
        cout << endl;
        return;
    }

    for(int i = index; i<n; i++){
        if(i > index && arr[i] == arr[i - 1]) continue;
        if(arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombo2(i + 1, target - arr[i], n, arr, ds);
        ds.pop_back();
    }
}

int main(){
    vector<int> ds;

    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);

    findCombo2(0, target, n, arr, ds);

    return 0;
}
