#include <iostream>
#include <queue>
using namespace std;

void kthLargestElement(int arr[], int n, int k){
    priority_queue <int, vector<int>, greater<int> > q;

    for(int i = 0; i < k; i++)
        q.push(arr[i]);

    for(int i = k; i < n; i++){
        if(arr[i] > q.top()){
            q.pop();
            q.push(arr[i]);
        }
    }

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }

}

int main(){
    int arr[] = {12, 5, 787, 1, 23};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    kthLargestElement(arr, n, k);

    return 0;
}
