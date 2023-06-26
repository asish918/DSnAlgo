#include<iostream>
#include<vector>
using namespace std;

void bellman_ford(vector<vector<int>> edges, int S){
    int V = edges.size() - 1;
    vector<int> dist (V, 1e9);
    dist[S] = 0;
    
    for(int i = 0; i<V-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            cout << -1 << endl;
            return;
        }
    }

    for(auto i : dist)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 0, 3},
        {1, 2, -1},
        {2, 0, 1}
    };
    
    int S = 2;

    bellman_ford(edges, S);
    return 0;
}
