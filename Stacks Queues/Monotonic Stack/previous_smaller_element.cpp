#include<iostream>
#include<stack>
using namespace std;

int main() {
    int arr[] = {1, 5, 0, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    
    int pse[n];

    stack<int> st;
    for(int i = 0; i<n; i++) {
        while(!st.empty() && st.top() > arr[i])
            st.pop();

        if(st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i<n; i++) 
        cout << pse[i] << " ";
    cout << endl;

    return 0;
}
