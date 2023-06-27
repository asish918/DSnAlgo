#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_set<char> letters;

    int i = 0;
    int j = 0;

    int result = 0;

    while(j < s.size()){
        if(letters.find(s[j]) == letters.end()) {
            letters.insert(s[j]);
            result = max(result, j - i + 1);
            j++;
        }
        else {
            letters.erase(s[i]);
            i++;
        }
    }

    return result;
}

int lengthOfLongestSubstringOptimal(string s){
    vector<int> mpp(256, -1);

    int left = 0;
    int right = 0;
    int n = s.size();
    int len = 0;
    while(right < n){
        if(mpp[s[right]] != -1) 
            left = max(mpp[s[right]] + 1, left); //makes sure that last seen S[right] is greater than the current left

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }

    return len;
}

int main(){
    string s = "pwwkew";

    //cout << lengthOfLongestSubstring(s);
    cout << lengthOfLongestSubstringOptimal(s);

    return 0;
}

/*
####Approach 1
We use two pointers, i and j, to represent the start and end of the current substring, initially both pointing to the beginning of the string.

We also maintain an unordered set uniqueChars to store the unique characters in the current substring.

We iterate through the string with the pointer j and check if the character s[j] is already present in the uniqueChars set.

If s[j] is not present, it means we have found a new unique character. We add it to the set, update the maxLength if necessary, and move the j pointer forward.

If s[j] is already present, it means we have encountered a repeating character. In this case, we remove the character at s[i] from the uniqueChars set, move the i pointer forward, and continue the process.

We repeat steps 4 and 5 until we reach the end of the string.

Finally, we return the maxLength, which represents the length of the longest substring without repeating characters.
 */

/*
#####  Most Optimal Apporach
Initialize a vector mpp of size 256 with -1 to serve as a map to store the last occurrence index of each character in the given string.

Set left and right pointers to 0, representing the boundaries of the current substring being considered. n is the length of the string s, and len stores the length of the longest substring encountered so far.

While the right pointer is within the range of the string:

Check if the current character s[right] has been encountered before (i.e., mpp[s[right]] != -1).
If it has, update the left pointer to the next position after the last occurrence of s[right] using max(mpp[s[right]] + 1, left).
Update the mpp map with the current index of s[right].
Update the len if a longer non-repeating substring is found.
Move the right pointer forward.
Return the len as the length of the longest substring without repeating characters.

*/
