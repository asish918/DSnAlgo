#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;

pair<int, int> countMinMaxFreq(vector<int> arr) {
    map<int, int> m;

    for(int i = 0; i<arr.size(); i++){
        m[arr[i]]++;
    }

    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;

    map<int, int> ::iterator it;

    for(it = m.begin(); it != m.end(); ++it){
        if(it->second > maxFreq)
            maxFreq = it->first;
        else if(it->second < minFreq)
            minFreq = it->first;
    }

    return pair<int, int> (maxFreq, minFreq);
}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(5);

    pair<int, int> ans = countMinMaxFreq(arr);
    cout << ans.first << " " << ans.second << endl;
    
    return 0;
}