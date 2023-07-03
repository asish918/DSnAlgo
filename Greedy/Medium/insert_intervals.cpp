#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertInterval(vector<vector<int>>& intervals, vector<int> newEvent) {
    int i = 0;
    int n = intervals.size();

    vector<vector<int>> result;

    while(i < n && intervals[i][1] < newEvent[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    while(i < n && newEvent[1] >= intervals[i][0]) {
        newEvent[0] = min(newEvent[0], intervals[i][0]);
        newEvent[1] = max(newEvent[1], intervals[i][1]);
        i++;
    }
    
    result.push_back(newEvent);

    while(i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    for(auto i : result) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {10, 15},
        {20, 30}
    };
    
    vector<int> newEvent = {5, 6};
    insertInterval(intervals, newEvent);
    return 0;
}

/*
The insertInterval function takes two parameters: intervals (the array of non-overlapping intervals) and newEvent (the new event interval to be inserted).

The function initializes an empty vector result to store the updated intervals.

It also initializes variables n with the size of intervals and i with 0 to keep track of the current position while iterating through intervals.

The function iterates through the existing intervals to find the correct position to insert the new event interval. It checks if the end of the current interval is less than the start of the new event interval. If true, it means there is no overlap, and the current interval is added to result. The loop continues until this condition is met.

After finding the correct position to insert the new event interval, the function then iterates through the remaining intervals to merge any overlapping intervals with the new event interval. It compares the start and end values of each interval with the new event interval. If there is an overlap, the start and end values of the new event interval are updated to cover the merged interval.

Once the merging is complete, the updated new event interval is added to result.

Finally, the function adds the remaining intervals after merging to result.

The printIntervals function is a helper function to print the intervals in the format [start, end].

In the main function, an example usage of the insertInterval function is demonstrated. It initializes an array of non-overlapping intervals intervals and a new event interval newEvent. The original intervals are printed, and then the insertInterval function is called to update the intervals. The updated intervals are printed afterward.
*/
