#include<iostream>
#include<set>
#include<vector>
using namespace std;

bool solve (int i, string s, set<string>& dict) {
    if (i == s.length()) {
        return true;
    }

    for(int j = i; j<s.length(); j++) {
        if(dict.find(s.substr(i, j - i + 1)) != dict.end()) {
            if(solve(j + 1, s, dict)) return true;
        }
    }

    return false;
}

int main() {
    string s = "catsanddog";
    int n = s.length();

    set<string> dict = {"cats", "cat", "and", "sand", "dog"};

    cout << solve(0, s, dict) << endl;

    return 0;
}
