#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int sumOfSubarrMin(int arr[], int n){
    vector<int> next_smaller (n);
    vector<int> prev_smaller (n);

    stack<int> s1;
    stack<int> s2;

    for(int i = 0; i<n; i++){
        next_smaller[i] = n - 1 - i;
        prev_smaller[i] = i;
    }

    for(int i = 0; i<n; i++){
        while(!s1.empty() && arr[s1.top()] >= arr[i]){
            next_smaller[s1.top()] = i - s1.top() - 1;
            s1.pop();
        }
        s1.push(i);
    }

    for(int i = n - 1; i>=0; i--){
        while(!s2.empty() && arr[s2.top()] > arr[i]){
            prev_smaller[s2.top()] = s2.top() - i - 1;
            s2.pop();
        }
        s2.push(i);
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans+=(arr[i] * (next_smaller[i] + 1) * (prev_smaller[i] + 1));
    }

    return ans;
}

int main(){
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(n);

    cout << sumOfSubarrMin(arr, n);
    return 0;
}
