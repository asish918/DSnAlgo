#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(arr) / sizeof(int);
    int queries[] = {0, 5};
    int m = sizeof(queries) / sizeof(int);

    vector<int> ans;

    for(int i = 0; i<m; i++) {
        int count = 0;
        for(int j = queries[i]; j<n; j++)
            if(arr[queries[i]]< arr[j])
                count++;

        ans.push_back(count);
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
