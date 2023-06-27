#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

string bruteForce(string S, string P) {
    int n = S.length();
    int m = P.length();
    unordered_map<char, int> charCountP;

    for(int i = 0; i < m; i++)
        charCountP[P[i]]++;

    int minWindowSize = 1000; //INT_MAX
    string minWindow = "";

    for(int i = 0; i < n; i++) {
        unordered_map<char, int> charCountS;
        int count = 0;

        for(int j = i; j<n; j++) {
            char c = S[j];
            charCountS[c]++;

            if(charCountP.find(c) != charCountP.end() && charCountS[c] <= charCountP[c])
                count++;

            if(count == m) {
                int windowSize = j - i + 1;
                if(windowSize < minWindowSize) {
                    minWindowSize = windowSize;
                    minWindow = S.substr(i, windowSize);
                }
                break;
            }
        }
    }

    return minWindow;
}

string optimal(string S, string P) {
    int n = S.length();
    int m = P.length();
    unordered_map<char, int> charCountP;

    for(int i = 0; i < m; i++)
        charCountP[P[i]]++;

    int minWindowSize = 1000; //INT_MAX
    int windowStart = 0;

    unordered_map<char, int> charCountS;
    int count = 0;
    int left = 0;
    int right = 0;

    while(right < n) {
        char c = S[right];
        charCountS[c]++;

        if(charCountP.find(c) != charCountP.end() && charCountS[c] <= charCountP[c])
            count++;

        while(count == m) {
            int windowSize = right - left + 1;
            if(windowSize < minWindowSize) {
                minWindowSize = windowSize;
                windowStart = left;
            }

            charCountS[S[left]]--;
            if(charCountP.find(S[left]) != charCountP.end() && charCountS[S[left]] < charCountP[S[left]])
                count--;

            left++;
        }

        right++;
    }


    return S.substr(windowStart, minWindowSize);
}

int main(){
    string S = "timetopractice";
    string P = "toc";

    cout << bruteForce(S, P) << endl; 
    cout << optimal(S, P) << endl; 
    return 0;
}

/*
##### Brute Force
We start by counting the frequency of each character in string P using the charCountP unordered map.

We initialize variables minWindowSize to store the minimum window size found so far (initialized with INT_MAX) and minWindow to store the smallest window substring.

We iterate through all possible substrings of string S using two nested loops.

The outer loop iterates through the starting indices of the substrings, and the inner loop iterates through the ending indices.

For each substring, we maintain a separate charCountS unordered map to count the frequency of characters within that substring.

We also maintain a count variable to keep track of the number of characters in string P that have been found in the substring so far.

Within the inner loop, we check if the current character c at index j is present in string P and if its count in substring S is less than or equal to its count in P. If so, we increment the count.

If the count is equal to the length of string P, it means we have found a substring that contains all the characters of string P.

We calculate the window size (windowSize) as the difference between the current ending index j and the starting index i. If this window size is smaller than the minWindowSize found so far, we update minWindowSize and store the substring using S.substr(i, windowSize) in the minWindow variable.

After the nested loops complete, if minWindow is still an empty string, it means no window containing all characters of P was found. In this case, we return "-1".

Otherwise, we return the minWindow, which represents the smallest window substring containing all the characters of P.
*/
