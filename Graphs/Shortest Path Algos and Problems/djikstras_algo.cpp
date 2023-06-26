#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

void djikstras_algo(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dis (V, 1e9);
    dis[S] = 0;
    pq.push({0, S});

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto adjNode : adj[node]){
            int weighted = adjNode[1];
            int aNode = adjNode[0];

            if(dist + weighted < dis[aNode]){
                dis[aNode] = dist + weighted;
                pq.push({dis[aNode, aNode]});
            }
        }
    }
}

//Expected output - 430
//S = 2
//V = 3
int main(){
    vector<vector<int>> adj = {{

        {1, 1},
        {2, 6},
        {2, 3},
        {0, 1},
        {1, 3},
        {0, 6}
        
    }};

    int V = 3;
    int S = 2;
    
    djikstras_algo(V, adj, S);
    return 0;
}
