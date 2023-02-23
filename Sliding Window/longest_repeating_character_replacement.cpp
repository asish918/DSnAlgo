#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int characterReplacement(string arr, int n, int k){
    vector<int> count (26);
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
