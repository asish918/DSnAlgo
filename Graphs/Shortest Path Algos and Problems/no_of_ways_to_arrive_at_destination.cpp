#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

int countPaths(int n, vector<vector<int>> roads){
    vector<pair<int, int>> adj[n];

    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> dist(n, 1e9);
    vector<int> ways(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dist[0] = 0;
    ways[0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        auto it = q.top();
        q.pop();

        long long time = it.first;
        long long node = it.second;

        for(auto i : adj[node]){
            long long adjNode = i.first;
            long long edgeWeight = i.second;

            if(time + edgeWeight < dist[adjNode]){
                dist[adjNode] = time + edgeWeight;
                q.push({time + edgeWeight, adjNode});
                ways[adjNode] = ways[node];
            }
            else if(time + edgeWeight == dist[adjNode])
                ways[adjNode] += ways[node];
        }
    }

    return ways[n - 1];
}

int main(){
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };    
    int n = 7;

    cout << countPaths(n, roads);

    return 0;
}
