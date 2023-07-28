#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// Static is used to passed TLE in Leetcode. Weird reason. TODO - Dig Deep
static bool compare(string a, string b) {    
    if(a.length() != b.length() + 1) return false;

    int i = 0;
    int j = 0;

    while((unsigned long)i < a.length()) {
        if((unsigned long)j < b.length() && a[i] == a[j]) {
            i++;
            j++;
        }
        else
            i++;
    }

    return (unsigned long)j == b.length();
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int N = words.size();

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
            }); //Sorting in ascending order of length is necessary since we can find the subset in any order and is it nor necessariliy a subsequence

    int maxLen = 0;

    vector<int> dp(N, 1);
    
    for(int index = 1; index < N; index++) {
        for(int prev_index = 0; prev_index < index; prev_index++) {
            if(compare(words[index], words[prev_index]) && 1 + dp[prev_index] > dp[index])
                dp[index] = 1 + dp[prev_index];
        }

        if(dp[index] > maxLen)
            maxLen = dp[index];
    }

    cout << maxLen << endl;
    return 0;
}
