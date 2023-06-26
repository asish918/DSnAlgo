#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void shortestPath(vector<vector<int>> edges, int N, int src){
    vector<int> adjList[N];
    for(auto it : edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }

    vector<int> dist(N, 1e9);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adjNode : adjList[node]){
            if(dist[node] + 1 < dist[adjNode]){
                dist[adjNode] = dist[node] + 1;
                q.push(adjNode);
            }
        }
    }

    for(int i = 0; i<N; i++)
        if(dist[i] == 1e9) dist[i] = -1;

    for(int i = 0; i<N; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {1, 2},
        {2, 6},
        {6, 7},
        {7, 8},
        {6, 8}
    };

    shortestPath(edges, 9, 0);

    return 0;
}
