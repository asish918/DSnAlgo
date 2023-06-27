#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int characterReplacement(string arr, int n, int k){
    vector<int> count (26, 0);
    int maxCount = 0;

    int i = 0;
    int j = 0;

    int ans = 0;

    while(j < n){
        count[arr[j] - 'A']++;
        maxCount = max(maxCount, count[arr[j] - 'A']);

        if(j - i + 1 - maxCount > k) {
            count[arr[j] - 'A']--;
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main(){
    string s = "ABAB";
    int k = 2;
    int n = s.length();

    cout << characterReplacement(s, n, k);
    return 0;
}

/*

We start by initializing variables: n to store the length of the string S, count to keep track of character counts (initialized with zeros for each character), maxLen to store the maximum length of substring with the same character, maxCount to store the maximum count of any character in the current window, and start to mark the start index of the current window.
We iterate over the string S using the end variable as the end index of the current window.
For each character at the end index, we increment its count in the count array.
We update maxCount with the maximum count of any character in the current window.
We calculate the length of the current window by subtracting the start index from the end index and adding 1.
If the number of operations needed to make all characters in the current window the same (which is windowLen - maxCount) is greater than K, we move the start pointer to shrink the window. To do this, we decrement the count of the character at the start index in the count array and increment the start index by 1.
We update maxLen with the maximum length of substring with the same character encountered so far.
Finally, we return maxLen, which represents the length of the longest substring containing the same letter that can be obtained after performing at most K operations.
*/
