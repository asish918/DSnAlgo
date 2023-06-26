#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<vector<int>> adjList){
    color[node] = col;

    for(auto adjNode : adjList[node]){
        if(color[adjNode] == -1){
            if(dfs(adjNode, !col, color, adjList) == false)
                return false;
        }
        else if(color[adjNode] == col){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> adjList){
    int V = adjList.size();
    vector<int> color(V, -1);

    for(int i = 0; i<V; i++){
        if(color[i] == -1)
            if(!dfs(i, 0, color, adjList))
                return false;
    }

    return true;
}

int main(){
    vector<vector<int>> adjList = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    cout << isBipartite(adjList);

    return 0;
}
