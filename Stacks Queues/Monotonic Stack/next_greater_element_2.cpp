#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreaterElement2(int arr[], int n){
    stack<int> st;
    int nge[n];

    for(int i = 2*n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i % n])
            st.pop();

        if(i < n){
            if(!st.empty()){
                nge[i % n] = st.top();
            }
            else {
                nge[i % n] = -1;
            }
        }
        st.push(arr[i % n]);
    }

    for(int i = 0; i<n; i++)
        cout << nge[i] << " ";
}

int main(){
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(int);
    
    nextGreaterElement2(arr, n);

    return 0;
}
