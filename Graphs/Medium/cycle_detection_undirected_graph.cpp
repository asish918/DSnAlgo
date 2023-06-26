#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

bool detectBFS(int src, vector<int> adjList[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;

    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode : adjList[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if(parent != adjNode)
                return true;
        }
    }

    return false;
}

bool detectDFS(int node, int parent, int vis[], vector<int> adjList[]){
    vis[node] = 1;

    for(auto adjNode : adjList[node]){
        if(!vis[adjNode])
            if(detectDFS(adjNode, node, vis, adjList))
                return true;
        else if(parent != adjNode) return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adjList[]){
    int vis[V] = {0};

    for(int i = 0; i<V; i++){
        if(!vis[i])
            if(detectDFS(i, -1, vis, adjList))
                return true;
    }

    return false;
}

int main(){
    vector<int> adjList[5] = {
        {1},
        {0, 2, 4},
        {1, 3},
        {2, 4},
        {1, 3}
    };

    cout << isCycle(5, adjList) << endl;;

    return 0;
}
