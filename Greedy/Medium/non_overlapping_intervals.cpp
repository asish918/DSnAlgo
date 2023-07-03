#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if(n <= 1)
        return 0;

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

    int lastEnd = intervals[0][1];
    int minRemovals = 0;

    for(int i = 1; i<n; i++) {
        if(intervals[i][0] < lastEnd)
            minRemovals++;
        else
            lastEnd = intervals[i][1];
    }

    return minRemovals;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    cout << eraseOverlapIntervals(intervals);

    return 0;
}

/*
The eraseOverlapIntervals function takes a reference to a vector of intervals as a parameter.

The function first checks if the number of intervals n is less than or equal to 1. If true, it means there are no intervals or only one interval, so no removal is required. In such cases, it returns 0.

The intervals are sorted based on their end values using the sort function from the C++ standard library. The custom comparator lambda function is used to compare intervals based on their end values.

The variables minRemovals and lastEnd are initialized to 0 and the end value of the first interval, respectively.

The function iterates through the remaining intervals starting from the second interval.

If the start value of the current interval is less than the lastEnd value, it indicates an overlap with the previous interval. In this case, the removal count minRemovals is incremented.

If there is no overlap, the lastEnd value is updated to the end value of the current interval.

After iterating through all the intervals, the function returns the minRemovals count, which represents the minimum number of intervals to remove to make the rest of the intervals non-overlapping.

In the main function, an example usage of the eraseOverlapIntervals function is demonstrated. An array of intervals is initialized, and the minimum number of intervals to remove is printed to the console.
*/
