#include <iostream>
#include <vector>
using namespace std;

void subsets(int index, int arr[], int n, vector<int>& ds){
    for(auto i : ds)
        cout << i << " ";
    cout << endl;

    for(int i = index; i<n; i++){
        if(i > index && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        subsets(i + 1, arr, n, ds);
        ds.pop_back();
    }
}

int main(){
    vector<int> ds;
    int nums[] = {1, 2, 2};
    int n = sizeof(nums)/sizeof(int);

    subsets(0, nums, n, ds);

    return 0;
}
