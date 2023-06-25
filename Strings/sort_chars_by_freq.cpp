#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

int main() {
    string s = "trreee";

    unordered_map<char, int> mpp;
    for(int i = 0; i<s.length(); i++)
        mpp[s[i]]++;

    vector<pair<char, int>> res;
    
    for(auto it : mpp) res.push_back(it);
    sort(res.begin(), res.end(), cmp);

    string ans = "";
    for(auto i : res) {
        int count = i.second;
        while(count--)
            ans+=i.first;
    }

    cout << ans << endl;
    return 0;
}
