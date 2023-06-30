#include <climits>
#include <unordered_map>
#include<iostream>
using namespace std;

string bruteForce(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    string minWindow = "";
    int minLength = INT_MAX;

    for(int i = 0; i<n; i++) {
        for(int j = i + m - 1; j<n; j++) {
            string window = str1.substr(i, j - i + 1);

            int k = 0;
            int l = 0;

            while(k < window.length() && l < m) {
                if(window[k] == str2[l])
                    l++;
                k++;
            }

            if(l == m && window.length() < minLength) {
              minLength = window.length();
              minWindow = window;
            }
        }
    }

    return minWindow;
}

string optimal(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    for(int i = 0; i<m; i++)
        freq2[str2[i]]++;
    
    int startIdx = 0;
    int count = 0;
    int minWindow = INT_MAX;
    int left = 0;
    int right = 0;

    while(right < n) {
        freq1[str1[right]]++;

        if(freq2.find(str1[right]) != freq2.end() && freq1[str1[right]] <= freq2[str1[right]])
            count++;

        while(count == m) {
            int windowSize = right - left + 1;
            if(windowSize < minWindow) {
                minWindow = windowSize;
                startIdx = left;
            }

            freq1[str1[left]]--;
            if(freq2.find(str1[left]) != freq2.end() && freq1[str1[left]] < freq2[str1[left]])
                count--;

            left++;
        }
        right++;
    }

    if(minWindow == INT_MAX)
        return "";

    return str1.substr(startIdx, minWindow);
}

int main() {
    string str1 = "geeksforgeeks";
    string str2 = "eksrg";
    
    cout << bruteForce(str1, str2) << endl;
    cout << optimal(str1, str2) << endl;
    return 0;
}

/*
#### Brute Force Approach
The brute force approach involves considering all possible substrings of str1 and checking if str2 is a subsequence of each substring. The intuition behind this approach is to find the minimum-length substring that contains all the characters of str2 in the correct order.

The algorithm starts by initializing minLength as a large value and minWindow as an empty string. These variables will keep track of the minimum substring found so far.

Then, it uses two nested loops to consider all possible substrings of str1. The outer loop iterates over the starting index of the substring, and the inner loop iterates over the ending index. The inner loop starts at i + len2 - 1 because the substring should have a minimum length of len2 to be considered.

For each substring, it checks if str2 is a subsequence of that substring. This is done using two pointers, k and l, which iterate over the characters of the substring and str2 respectively. The loop continues as long as both pointers are within their respective lengths and the characters at the current positions match.

If str2 is a subsequence of the current substring and the length of the substring is smaller than minLength, it updates minLength and minWindow with the current substring.

Finally, it returns the minWindow, which represents the minimum substring of str1 that contains str2 as a subsequence.

The time complexity of this brute force approach is O(n^3)
*/

/*
##### Optimal
The optimized approach uses a sliding window technique to find the minimum substring in str1 that contains str2 as a subsequence. It reduces the time complexity to O(n), where n is the length of str1.

The algorithm starts by comparing the lengths of str1 and str2. If str1 is shorter than str2, it's impossible to find a substring in str1 containing str2 as a subsequence, so it returns an empty string.

The algorithm utilizes two frequency maps: freq1 and freq2. freq2 is used to store the frequencies of characters in str2. freq1 will be used to track the frequencies of characters in the current sliding window.

The algorithm also initializes count to keep track of the number of characters in str2 that have been matched in the current window. minLength is initialized as a large value, and startIdx represents the starting index of the minimum substring found so far.

The algorithm then iterates over each character in str1. For each character, it increments its frequency in freq1. If the character is present in str2 and its frequency in freq1 is less than or equal to its frequency in freq2, it increments count to indicate a matching character.

If count becomes equal to the length of str2, it means that all the characters of str2 have been found in the current window. At this point, we start the inner while loop.

The while loop slides the window by incrementing windowStart and reducing the frequencies in freq1 until we find the smallest window that still contains all the characters of str2. The loop checks if the frequency of the character at windowStart in freq1 is greater than the frequency of the same character in freq2 or if the character is not present in freq2.

Once we have the smallest window containing all the characters of str2, we calculate its length. If the length is smaller than the current minLength, we update minLength and startIdx with the current window's information.

Finally, if minLength remains as its initial value (INT_MAX), it means no valid window was found, so we return an empty string. Otherwise, we return the substring of str1 starting from startIdx with a length of minLength.

*/
