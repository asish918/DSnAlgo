#include <iostream>
#include <unordered_map>
using namespace std;

int countSubstringsWithKDistinctChars(string s, int k) {
    int n = s.length();
    int count = 0;
    unordered_map<char, int> freq;
    int left = 0;
    int distinctCount = 0;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        if (freq[s[right]] == 1) {
            distinctCount++;
        }

        while (distinctCount > k) {
            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                distinctCount--;
            }

            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

int main() {
    string s = "aba";
    int k = 2;
    // Reason for k - 1 is that the function calculates no.of substrings with distinctCount
    // characters less than or equal to k
    //
    // so to obtain no.of substrings with exactly k distinct characters we subtract the count of k - 1 as well
    cout << countSubstringsWithKDistinctChars(s, k) - countSubstringsWithKDistinctChars(s, k - 1) << endl;  

    return 0;
}


/*
We define a sliding window using two pointers: left and right.

The freq map is initialized outside the loop to track the frequency of characters in the current window.

We initialize left, distinctCount, and count variables to keep track of the left index of the current window, the count of distinct characters, and the total count of substrings, respectively.

We iterate through the string with the right pointer and expand the window by adding the character s[right] to the frequency map.

If s[right] is a new character in the window (i.e., its frequency becomes 1), we increment distinctCount by 1.

If the number of distinct characters (distinctCount) exceeds k, we contract the window from the left side by moving the left pointer and adjusting the frequency map accordingly.

We continue contracting the window until distinctCount becomes less than or equal to k.

At each step, we add the count of substrings that can be formed with the current window to the count. The count is calculated as (right - left + 1), where right - left + 1 represents the length of the current window.

Finally, we return the count as the result.
*/
