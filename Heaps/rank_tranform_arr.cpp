#include <iostream>
#include <utility>
#include <queue>
using namespace std;

void rankTransform(int arr[], int n){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    for(int i = 0; i<n; i++)
        q.push(make_pair(arr[i], i));

    int curr = 1, prev = -1;
    
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        arr[top.second] = curr;

        if(prev == top.first)
            arr[top.second] = curr - 1;
        else
            curr++;

        prev = top.first;
    }
}

int main(){
    int arr[] = {20, 15, 26, 2, 98, 6};
    int n = sizeof(arr)/sizeof(int);

    rankTransform(arr, n);

    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
