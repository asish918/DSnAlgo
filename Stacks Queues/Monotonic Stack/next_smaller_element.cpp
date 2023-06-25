#include <iostream>
#include <stack>
using namespace std;

//Look up GFG practice for question
void immediateSmaller(int arr[], int n) {
    //Using stack
//    stack<int> st;
//    for(int i = n - 1; i>=0; i--) {
//        if(st.empty() || st.top() >= arr[i]) {
//            st.push(arr[i]);
//            arr[i] = -1;
//        }
//        else {
//            int temp = arr[i];
//            arr[i] = st.top();
//            st.push(temp);
//        }
//    }
    
    //Constant Space
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i + 1])
            arr[i] = arr[i + 1];
        else
            arr[i] = -1;
    }
    arr[n - 1] = -1;

    for(int i = 0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void nextSmallerElement(int arr[], int n){
    stack<int>st;
    int nse[n];

    for(int i = n - 1; i>=0; i--) {
        while(!st.empty() && st.top() > arr[i])
            st.pop();

        if(st.empty())
            nse[i] = -1;
        else 
            nse[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i<n; i++)
        cout << nse[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {5, 6, 2, 3, 1, 7};
    int n = sizeof(arr) / sizeof(int);

    //nextSmallerElement(arr, n);
    immediateSmaller(arr, n);
    return 0;
}
