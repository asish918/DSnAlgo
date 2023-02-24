#include<iostream>
#include <vector>
#include <iterator>
using namespace std;

void print_subs(int s, int sum, int index, int n, int arr[], vector<int> &ans){
    if(index == n){
        if(s == sum) {
            for(auto i : ans)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    ans.push_back(arr[index]);
    s+=arr[index];
    print_subs(s, sum, index + 1, n, arr, ans);
    ans.pop_back();
    s-=arr[index];
    print_subs(s, sum, index + 1, n, arr, ans);
}

int main(){
    vector<int> ans;

    int nums[] = {1, 2, 3};
    int sum = 3;
    int n = sizeof(nums) / sizeof(int);

    print_subs(0, sum, 0, n, nums, ans);

    return 0;
}
