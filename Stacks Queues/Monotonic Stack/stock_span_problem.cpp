#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(int);
    vector<int> ans(n, 0);

    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        ans[i] = st.empty() ? i + 1 : i - st.top();

        st.push(i);
    }
    
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}


/*
Create a vector spans of size n to store the span values. Initialize all spans to 1 since every element has a minimum span of 1.

Create an empty stack st to store the indices of the previous days' prices.

Iterate over each day from left to right using the variable i.

While the stack is not empty and the price at the top of the stack (prices[st.top()]) is less than or equal to prices[i], pop elements from the stack since they are not useful for calculating the span of prices[i].

If the stack becomes empty, it means prices[i] is the largest element encountered so far. In this case, the span of prices[i] is i + 1 (1-based index).

If the stack is not empty, the top element's index (st.top()) represents the largest element smaller than prices[i]. The span of prices[i] is i - st.top().

Update the span of prices[i] in the spans vector.

Push the current index i onto the stack.

Repeat steps 3-8 for all days.

Return the spans vector containing the span values for each day.
*/
