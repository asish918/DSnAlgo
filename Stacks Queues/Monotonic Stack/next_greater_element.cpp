#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void nextGreaterNoob(int arr[], int n){
    for(int i = 0; i<n; i++){
        int og = arr[i];
        for(int j = i + 1; j<n; j++){
            if(arr[j] > arr[i]){
                arr[i] = arr[j];
                break;
            }
        }
    }
}

void nextGreaterOptimal(int arr[], int n){
    stack<int> st;
    int nge[n];

    st.push(arr[n-1]);
    nge[n-1] = -1;

    for(int i = n - 2; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i])
            st.pop();

        if(st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i<n; i++)
        cout << nge[i] << " ";
}

void nextGreaterILeetcode(int arr1[], int arr2[], int m, int n){

        unordered_map<int,int> mp;
        vector<int> res(m,-1);

        stack<int> st;

        for(int i=0;i<n;i++){

            int ele = arr2[i];

            while(!st.empty() && ele > st.top()){
                mp[st.top()] = ele;
                st.pop();
            }
            st.push(ele);
        }

        for(int i=0;i<m;i++){

            int ele = arr1[i];

            if(mp.find(ele) != mp.end()){
                res[i] = mp[ele];
            }
        }

    for(auto i : res)
        cout << i << " ";
}

int main(){
    int arr[] = {2, 4};
    int arr1[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    int m = sizeof(arr1)/sizeof(int);

    //nextGreaterNoob(arr, n);
    //nextGreaterOptimal(arr, n);
    
    nextGreaterILeetcode(arr, arr1, n, m);

    return 0;
}
