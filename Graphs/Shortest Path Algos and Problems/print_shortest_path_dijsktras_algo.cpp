#include <algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

void printShortestPath(vector<vector<int>>& edges, int V) {
    vector<pair<int, int>> adjList[V + 1];
    int m = edges.size();

    for(int i = 0; i < m; i++) {
        adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<int> dist(V + 1, 1e9);
    vector<int> parent(V + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    dist[1] = 0;
    parent[1] = 1;
    minHeap.push({0, 1});

    while(!minHeap.empty()) {
        auto it = minHeap.top();
        minHeap.pop();

        int dis = it.first;
        int node = it.second;

        for(auto adjNode : adjList[node]) {
            int wt = adjNode.second;
            int aNode = adjNode.first;

            if(wt + dis < dist[aNode]){
                dist[aNode] = wt + dis;
                minHeap.push({dist[aNode], aNode});
                parent[aNode] = node;
            }
        }
    }

    vector<int> path;
    int node = V;
    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());

    for(auto i : path)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    int V = 5; //no of Nodes or Vertices

    printShortestPath(edges, V);
    return 0;
}
