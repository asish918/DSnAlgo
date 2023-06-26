#include <climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int networkDelay(vector<vector<int>> times, int n, int k){
    vector<pair<int, int>> adj[n+1];

    for(auto it : times)
        adj[it[0]].push_back({it[1], it[2]});

    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int weight = it.first;
        int node = it.second;

        for(auto i : adj[node]){
            int adjNode = i.first;
            int edgeWeight = i.second;

            if(weight + edgeWeight < dist[adjNode]){
                dist[adjNode] = weight + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    int minElement = INT_MIN;
    for(int i = 1; i<=n; i++){
        if(dist[i] == 1e9)
            return -1;
        else
            minElement = max(dist[i], minElement);
    }

    return minElement;
}

int main(){
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    
    int n = 4;
    int k = 2;

    cout << networkDelay(times, n, k) << endl;

    return 0;
}
