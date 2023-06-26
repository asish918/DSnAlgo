#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int cheapestFlight(vector<vector<int>> flights, int n, int src, int dst, int k){
    vector<pair<int, int>> adj[n];
    
    for(auto it : flights)
        adj[it[0]].push_back({it[1], it[2]});

    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k)
            continue;
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            int edgeWeight = i.second;

            if(cost + edgeWeight < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + edgeWeight;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    return dist[dst];
}

int main() {
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;
    
    cout << cheapestFlight(flights, n, src, dst, k) << endl;
    return 0;
}
