#include <iostream>
#include <queue>
using namespace std;

void mergeKSortedArr(int arr[3][3], int m, int n){
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++)
            q.push(arr[i][j]);
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

int main(){
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int m = 3, n = 3;

    mergeKSortedArr(arr, m, n);

    return 0;
}
