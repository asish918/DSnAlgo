#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int n = sizeof(arr) / sizeof(int);
    vector<int> ans;

    deque<int> dq;

    for(int i = 0; i<n; i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();

        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    
    for(auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
