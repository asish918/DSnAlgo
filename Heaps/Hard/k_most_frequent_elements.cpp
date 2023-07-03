#include<iostream>
#include<unordered_map>
#include<queue>
#include <utility>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    int n = nums.size();

    unordered_map<int, int> countFreq;

    for(int i = 0; i<n; i++) 
        countFreq[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for(auto i : countFreq) {
        minHeap.push({i.second, i.first});

        while(minHeap.size() > k)
            minHeap.pop();
    }

    while(!minHeap.empty()) {
        cout << minHeap.top().second << ' ';
        minHeap.pop();
    }

    return 0;
}
