#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int recursion(vector<vector<int>>& points, int day, int prevActivity) {
    if(day < 0)
        return 0;

    int maxPoints = 0;
    for(int activity = 0; activity < 3; activity++){
        if(activity != prevActivity) {
            int currentPoints = points[day][activity] + recursion(points, day - 1, activity);
            maxPoints = max(currentPoints, maxPoints);
        }
    }

    return maxPoints;
}

int memoization(vector<vector<int>>& points, int day, int prevActivity, vector<vector<int>>& dp) {
    if(day < 0)
        return 0;

    if(prevActivity != -1 && dp[day][prevActivity] != -1)
        return dp[day][prevActivity];

    int maxPoints = 0;
    for(int activity = 0; activity < 3; activity++) {
        if(activity != prevActivity) {
            int currentPoints = points[day][activity] + memoization(points, day - 1, activity, dp);
            maxPoints = max(maxPoints, currentPoints);
        }
    }

    return dp[day][prevActivity] = maxPoints;
}

int tabulation(vector<vector<int>>& points, int n, vector<vector<int>>& dp) {
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);

    int maxPoints = 0;
    for(int day = 1; day<n; day++) {
        for(int prevActivity = 0; prevActivity < 3; prevActivity++) {
            maxPoints = 0;
            for(int activity = 0; activity < 3; activity++) {
                if(activity != prevActivity) {
                    int currentPoints = points[day][activity] + dp[day - 1][activity];
                    maxPoints = max(currentPoints, maxPoints);
                }
            }
            dp[day][prevActivity] = maxPoints;
        }
    }

    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

int space_optimization(vector<vector<int>>& points, int n) {
    int dp[3];
    memset(dp, 0, sizeof(dp));

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);

    int curr[3];
    int maxPoints = 0;
    for(int day = 1; day < n; day++) {
        memset(curr, 0, sizeof(curr));
        for(int prevActivity = 0; prevActivity < 3; prevActivity++) {
            maxPoints = 0;

            for(int activity = 0; activity < 3; activity++) {
                if(activity != prevActivity) {
                    int currentPoints = points[day][activity] + dp[activity];
                    maxPoints = max(currentPoints, maxPoints);
                }
            }
            curr[prevActivity] = maxPoints;
        }
        memcpy(dp, curr, sizeof(curr));
    }

    return max(dp[0], max(dp[1], dp[2]));
}

int main() {
    int n = 3;
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    vector<vector<int>> dp(n, vector<int>(3, -1));
    
    cout << recursion(points, n - 1, -1) << endl;
    //cout << memoization(points, n - 1, -1, dp) << endl;
    cout << tabulation(points, n, dp) << endl;
    cout << space_optimization(points, n) << endl;
    return 0;
}
