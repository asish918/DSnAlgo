#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adjList[], int vis[]){
    vis[node] = 1;
    cout << node << " ";

    for(auto it : adjList[node])
        if(!vis[it])
            dfs(it, adjList, vis);
}

int main(){
    int V = 5;
    int visited[V] = {0};
    vector<int> adjList[V];

    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);

    adjList[1].push_back(0);
    
    adjList[2].push_back(0);
    adjList[2].push_back(4);

    adjList[3].push_back(0);

    adjList[4].push_back(2);

    dfs(0, adjList, visited);

    return 0;
}
