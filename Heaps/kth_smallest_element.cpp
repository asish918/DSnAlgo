#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[], int n, int k){
    priority_queue<int> q;
    for(int i = 0; i < k; i++)
        q.push(arr[i]);
    

    for(int i = k; i<n; i++){
        if(q.top() > arr[i]){
            q.pop();
            q.push(arr[i]);
        }
    }

    return q.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;

    cout << kthSmallestElement(arr, n, k) << endl;
    
    return 0;
}
