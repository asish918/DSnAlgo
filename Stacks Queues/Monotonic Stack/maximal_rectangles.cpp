#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int hist_area(vector<int> currRow, int m) {
    stack<int> st;
    int ans = -1;

    for(int i = 0; i<=m; i++) {
        while(!st.empty() && (i == m || currRow[st.top()] >= currRow[i])) {
            int height = currRow[st.top()];
            st.pop();

            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int M[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    int n = 4;
    int m = 4;

    vector<int> currRow(m, 0);
    int area = 0;


    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(M[i][j] == 1)
                currRow[j]++;
            else 
                currRow[j] = 0;
        }

        area = max(area, hist_area(currRow, m));
    }

    cout << area << endl;
    return 0;
}
