#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

// O(n*n)
int sumOfSubarrNoob(int arr[], int n) {
    int ans = 0;

    for(int i = 0; i<n; i++){
        int minVal = arr[i];
        ans += minVal;

        for(int j = i + 1; j<n; j++) {
            minVal = min(minVal, arr[j]);
            ans += minVal;
        }
    }

    return ans;
}

//O(n)
int sumOfSubarrMin(int arr[], int n){
    vector<int> left(n);
    vector<int> right(n);

    vector<int> st; //just because this thing has a clear() function

    //Previous Smaller Elements
    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.back()] >= arr[i])
            st.pop_back();
        
        if(st.empty())
            left[i] = -1;
        else
            left[i] = st.back();

        st.push_back(i);
    }

    st.clear();

    //Next Smaller elements
    for(int i = n - 1; i>=0; i--) {
        while(!st.empty() && arr[st.back()] > arr[i])
            st.pop_back();
        
        if(st.empty())
            right[i] = n;
        else
            right[i] = st.back();
        
        st.push_back(i);
    }

    int result = 0;
    const int MOD = 1e9 + 7;

    for(int i = 0; i<n; i++) {
        long long count = ((i - left[i]) * (right[i] - i)) % MOD;
        result = (result + arr[i] * count) % MOD;
    }

    return result;
}

int main(){
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(n);

    cout << sumOfSubarrMin(arr, n) << endl;
    cout << sumOfSubarrNoob(arr, n) << endl;
    return 0;
}


/* 
We start with the array arr of size N.

We calculate two auxiliary arrays, left and right, which store the indices of the previous smaller elements and the next smaller elements for each element in arr.

For each element arr[i], we want to calculate the count of subarrays in which arr[i] is the minimum element.
j
To calculate the count, we need to find the range of indices where arr[i] is the minimum element.

The range of indices is determined by left[i] and right[i].

left[i] represents the index of the previous smaller element than arr[i] to the left of it. If no such element exists, we set left[i] to -1.

right[i] represents the index of the next smaller element than arr[i] to the right of it. If no such element exists, we set right[i] to N.

The count of subarrays in which arr[i] is the minimum element is given by (i - left[i]) * (right[i] - i).

(i - left[i]) represents the number of subarrays that start from left[i] + 1 and end at i, inclusive.

(right[i] - i) represents the number of subarrays that start from i and end at right[i] - 1, inclusive.

Multiplying these two values gives us the count of subarrays where arr[i] is the minimum element.

Finally, we sum up the minimum element arr[i] multiplied by the count of subarrays for all elements arr[i] in the array. Taking care of modular arithmetic, the formula becomes:
sum = (sum + arr[i] * (i - left[i]) * (right[i] - i)) % MOD
*/

/*
    The use of >= for the previous smaller element and > for the next smaller element is based on the requirements of the problem.

In this problem, we need to find the sum of the minimum elements of all subarrays. For any element in the array, the subarray that contains it as the minimum element will extend from the previous smaller element (or the start of the array if there is no previous smaller element) to the next smaller element (or the end of the array if there is no next smaller element).

If we use > for the previous smaller element, it means that the current element is greater than the element at the top of the stack, and hence the element at the top of the stack cannot be the previous smaller element for the current element. Using >= ensures that the top of the stack could be the previous smaller element for the current element if they are equal.

On the other hand, if we use >= for the next smaller element, it means that the current element is greater than or equal to the element at the top of the stack, and hence the element at the top of the stack cannot be the next smaller element for the current element. Using > ensures that the top of the stack could be the next smaller element for the current element if they are equal.

By using >= for the previous smaller element and > for the next smaller element, we ensure that the correct indices are calculated for the previous and next smaller elements, as required by the problem statement.
 */
