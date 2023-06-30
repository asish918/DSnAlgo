#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[], int n, int k){
    //Max-Heap
    priority_queue<int> q;
    for(int i = 0; i<n; i++) {
        q.push(arr[i]);

        if(q.size() > k)
            q.pop();
    }

    //Min-Heap
    //priority_queue<int, vector<int>, greater<int>> q;
    //for(int i = 0; i < n; i++)
    //    q.push(arr[i]);
    //

    //for(int i = 0; i<k-1; i++)
    //    q.pop();

    return q.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;

    cout << kthSmallestElement(arr, n, k) << endl;
    
    return 0;
}
