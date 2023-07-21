/*
#### Exactly similar to regular LCS
Reverse the given string and find the LCS of original and reversed.
That will give us the Longest Palindromic Subsequence
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int space_optimisation(string s1, string s2) {
    int N = s1.length();

    int prev[N + 1];
    int curr[N + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= N; index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                curr[index2] = 1 + prev[index2 - 1];
            else
                curr[index2] = max(curr[index2 - 1], prev[index2]);
        }

        memcpy(prev, curr, sizeof(curr));
    }

    return prev[N];
}

int main() {
    string s1 = "bbabcbcab";
    string s2 = s1;

    reverse(s2.begin(), s2.end());

    cout << space_optimisation(s1, s2) << endl;

    return 0;
}
