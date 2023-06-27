#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int n = sizeof(arr) / sizeof(int);
    vector<int> ans;

    deque<int> dq;

    for(int i = 0; i<n; i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();

        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    
    for(auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}

/*
vector<int> ans;: This line declares an empty vector called ans to store the maximum elements of each subarray.

deque<int> dq;: This line declares an empty deque called dq to store the indices of elements from the array.

The for loop iterates over each index i in the range from 0 to n-1:

a. if(!dq.empty() && dq.front() == i - k) dq.pop_front();: This condition checks if the deque dq is not empty and the front element of the deque is equal to the index i - k. If this condition is true, it means the front element is no longer within the current subarray window of size k, so it is removed from the front of the deque using dq.pop_front().

b. while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();: This while loop executes as long as the following conditions are met:

The deque dq is not empty.
The element at the index dq.back() in the array arr is smaller than the current element at index i.
Inside the loop, the back element of the deque is removed using dq.pop_back() since it is no longer a candidate for being the maximum element within the subarray.
c. dq.push_back(i);: After the previous operations, the current index i is pushed onto the back of the deque dq.

d. if(i >= k - 1) ans.push_back(arr[dq.front()]);: This condition checks if the current index i is greater than or equal to k - 1. It ensures that we have processed at least k elements to form the first subarray of size k. If this condition is true, the element at the front of the deque, which represents the maximum element within the current subarray, is added to the ans vector.

Finally, the function returns the ans vector containing the maximum elements of each subarray.

 */
