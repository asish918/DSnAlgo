#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s = "aaac";
    int n = s.length();
    int ans = 0;


    for(int i = 0; i<n; i++) {
        vector<int> freq(26, 0);

        for(int j = i; j<n; j++) {
            freq[s[j] - 'a']++;

            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;

            for(int k = 0; k < 26; k++) {
                if(freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }

            ans += (maxFreq - minFreq);
        }
    }

    cout << ans << endl;
    return 0;
}

/*
The function beautySum takes a string S as input and returns the sum of the beauty of all substrings.

We initialize the sum as 0.

We iterate through all possible starting positions of substrings in S using the variable i.

For each starting position i, we consider all substrings starting at i by iterating through the string from index i to the end of the string using the variable j.

Within each substring, we maintain an array freq of size 26 to keep track of the frequency of each character. We initialize all elements of freq to 0 for each new substring.

As we iterate through the characters in the substring, we update the frequency of each character in freq by incrementing the corresponding index.

For each substring, we calculate the maximum and minimum frequencies among the characters present in the substring. We initialize maxFreq to 0 and minFreq to INT_MAX.

We iterate through all the elements of freq and update maxFreq with the maximum frequency encountered and minFreq with the minimum frequency encountered.

After calculating the maximum and minimum frequencies, we calculate the difference (maxFreq - minFreq) and add it to the sum.

Finally, after considering all possible substrings, we return the calculated sum.
*/
