#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 4;
    int n = sizeof(arr)/sizeof(int);
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i<k; i++) {
        ans.push_back(-1);
        minHeap.push(arr[i]);
    }

    ans[k - 1] = minHeap.top();

    for(int i = k; i<n; i++) {
        if(arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        ans.push_back(minHeap.top());
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
