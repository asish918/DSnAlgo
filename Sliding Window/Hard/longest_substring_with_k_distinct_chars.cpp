#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

int bruteForce(string s, int K) {
    int longest_substr = -1;
    
    for(int i = 0; i<s.length(); i++) {
        unordered_set<char> uniqueChars;

        for(int j = i; j<s.length(); j++) {
            uniqueChars.insert(s[j]);

            if(uniqueChars.size() == K) {
                longest_substr = max(longest_substr, j - i + 1);
            }
            else if(uniqueChars.size() > K)
                break;
        }
    }

    return longest_substr;
}

int optimal(string s, int K) {
    int longest_substr = -1;
    int left = 0;
    int right = 0;
    int n = s.length();

    unordered_map<char, int> charFrequency;

    while(right < n) {
        charFrequency[s[right]]++;

        while(charFrequency.size() > K) {
            charFrequency[s[left]]--;

            if(charFrequency[s[left]] == 0)
                charFrequency.erase(s[left]);

            left++;
        }

        if(charFrequency.size() == K) 
            longest_substr = max(longest_substr, right - left + 1);

        right++;
    }

    return longest_substr;
}

int main() {
    string s = "aabacbebebe";
    int K = 3;

    cout << bruteForce(s, K) << endl;
    cout << optimal(s, K) << endl;

    return 0;
}

/*
####Optimal
We initialize left and right pointers to keep track of the current window boundaries. Initially, both are set to 0.

We use an unordered_map called charFrequency to keep track of the frequency of each character within the window.

We traverse the string from left to right using the right pointer and apply the sliding window technique.

For each character at index right, we increment its frequency in charFrequency.

If the number of unique characters in the window exceeds k, we shrink the window by moving the left pointer.

We decrement the frequency of the character at index left in charFrequency.
If the frequency becomes 0, we remove the character from charFrequency.
We increment the left pointer to shrink the window from the left side.
After shrinking the window, we check if the current window has exactly k unique characters. If so, we update the longestSize with the maximum size encountered so far.

We continue this process until we reach the end of the string.

Finally, we return the longestSize which represents the size of the longest substring with exactly k unique characters.
*/
