#include<iostream>
#include<queue>
#include<utility>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

string approach1(string s) {
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

    return ans;
}

string heapApproach(string s) {
    string ans = "";
    unordered_map<char, int> charFreq;
    int n = s.length();

    for(int i = 0; i<n; i++)
        charFreq[s[i]]++;

    priority_queue<pair<int, int>> maxHeap;

    for(auto i : charFreq)
        maxHeap.push({i.second, i.first});

    while(!maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();
        
        int freq = top.first;
        while(freq--)
            ans.push_back(top.second);
    }

    return ans;
}

int main() {
    string s = "trreee";

    cout << approach1(s) << endl;
    cout << heapApproach(s) << endl;

    return 0;
}
