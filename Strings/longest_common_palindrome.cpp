#include<iostream>
using namespace std;

int main() {
    string s = "aaaabbaa";
    int n = s.length();
    int start = 0;
    int maxLen = 0; 

    for(int i = 0; i<n; i++) {
        //Expanding around the center for odd-length palindrome
        int left = i;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            
            if(currLen > maxLen) {
                maxLen = currLen;
                start = i;
            }
             left--;
             right++;
        }
        
        //Expanding around the center for even-length palindrome
        left = i;
        right = i + 1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;

            if(currLen > maxLen) {
                maxLen = currLen;
                start = left;
            }

            left--;
            right++;
        }
    }

    cout << s.substr(start, maxLen) << endl;
    return 0;
}

/*
We initialize two variables: start and maxLen. start will keep track of the starting index of the longest palindromic substring, and maxLen will store the length of the longest palindromic substring found so far.

We iterate through each character in the string s.

For each character, we consider it as the center of a potential palindrome and expand around it.

We perform two expansions: one for odd-length palindromes and another for even-length palindromes.

For odd-length palindromes, we initialize two pointers left and right to the current character's index. We then expand the window by moving left to the left and right to the right, checking if the characters at these positions are equal. We continue expanding as long as the characters match and the indices are within the string bounds.

Similarly, for even-length palindromes, we initialize left to the current character's index and right to i+1 (the next index). We then expand the window by moving left to the left and right to the right, checking if the characters at these positions are equal.

At each step, we update maxLen and start if we find a longer palindromic substring.

After iterating through all characters, we return the substring of s starting from index start with length maxLen, which represents the longest palindromic substring.
*/
