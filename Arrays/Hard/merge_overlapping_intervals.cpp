#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// TC - O(nlogn) + O(2n)
void bruteForce(vector<vector<int>> intervals){
    vector<vector<int>> ans;

    int n = intervals.size();

    sort(intervals.begin(), intervals.end());
    
    for(int i = 0; i<n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j = i + 1; j<n; j++){
            if(intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
            }
            else
                break;
        }

        ans.push_back({start, end});
    }

    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

//TC - O(nlogn) + O(n)
void optimal(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    int n = intervals.size();

    for(int i = 0; i<n; i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1])
            ans.push_back(intervals[i]);
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 3},
        {2, 6},
        {8, 9},
        {9, 11},
        {8, 10},
        {2, 4},
        {15, 18},
        {16, 17}
    };

    //bruteForce(arr);
    optimal(arr);
}
