#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int approach2(int arr[], int n) {
    stack<int> st;
    int area = -1;

    for(int i = 0; i<=n; i++) {
        while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            int height = arr[st.top()];
            st.pop();
            
            int width = 0;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;

            area = max(area, height * width);
        }

        st.push(i);
    }

    return area;
}

//Multiple Iterations
int approach1(int arr[], int n) {
    vector<int> prevSmaller(n, 0); //stores the boundary index
    vector<int> nextSmaller(n, n - 1); //stores the boundary index

    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if(!st.empty()) prevSmaller[i] = st.top() + 1;
        
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if(!st.empty()) nextSmaller[i] = st.top() - 1;

        st.push(i);
    }

    int ans = 0;

    for(int i = 0; i<n; i++) {
        int area = (nextSmaller[i] - prevSmaller[i] + 1) * arr[i];

        ans = max(ans, area);
    }

    return ans;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(int);

    cout << approach1(arr, n) << endl;
    cout << approach2(arr, n) << endl;
    return 0;
}
