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
            letters.erase(s[j]);
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
        if(mpp[s[right]] != -1) left = max(mpp[s[right]] + 1, left);

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
