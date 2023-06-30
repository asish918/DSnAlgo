#include <iostream>
#include <queue>
using namespace std;

int kthLargestElement(int arr[], int n, int k){
    //Max-Heap
    //priority_queue<int, vector<int>> q;
    //for(int i = 0; i<n; i++)
    //    q.push(arr[i]);

    //for(int i = 0; i < k - 1; i++)
    //    q.pop();


    //Min-Heap
    priority_queue <int, vector<int>, greater<int> > q;
    for(int i = 0; i < n; i++) {
        q.push(arr[i]);

        if(q.size() > k) {
            q.pop();
        }
    }
    
    return q.top();
}

int main(){
    int arr[] = {12, 5, 787, 1, 23};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    cout << kthLargestElement(arr, n, k) << endl;

    return 0;
}

/*

*/
