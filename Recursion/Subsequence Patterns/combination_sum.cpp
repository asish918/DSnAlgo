#include<iostream>
#include<vector>
using namespace std;

void findCombo(int index, int target, int arr[], int n, vector<int>& ans){
    if(index == n){
        if(target == 0){
            for(auto i : ans)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    if(arr[index] <= target){
        ans.push_back(arr[index]);
        findCombo(index, target - arr[index], arr, n, ans);
        ans.pop_back();
    }

    findCombo(index + 1, target, arr, n, ans);
}

int main(){
    vector<int> ans;

    int arr[] = {2, 3, 6, 7};
    int target = 7;
    int n = sizeof(arr)/sizeof(int);

    findCombo(0, target, arr, n, ans);

    return 0;
}
