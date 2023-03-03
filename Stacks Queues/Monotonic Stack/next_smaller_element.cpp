#include <iostream>
#include <stack>
using namespace std;

void nextSmallerElement(int arr[], int n){
    stack<int>s;
    s.push(-1);
    for(int i = n-1; i>=0; i--){
        if(arr[i] > s.top()){
            int temp = arr[i];
            arr[i] = s.top();
            s.push(temp);
        }
        else {
            int temp = arr[i];
            arr[i] = -1;
            s.push(temp);
        }
    }

    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
}

int main(){
    int arr[] = {5, 6, 2, 3, 1, 7};
    int n = sizeof(arr) / sizeof(n);

    nextSmallerElement(arr, n);
    return 0;
}
