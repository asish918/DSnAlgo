#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adjList[], int visited[]) {
    visited[node] = 1;
    for(auto it : adjList[node]) {
        if(!visited[it])
            dfs(it, adjList, visited);
    }
}

int findProvinces(vector<vector<int>>& adjMatrix) {
    int V = adjMatrix.size();

    vector<int> adjList[V];
    
    for(int i = 0; i<V; i++) {
        for(int j = 0; j<V; j++) {
            if(adjMatrix[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int visited[V] = {0};
    int count = 0;

    for(int i = 0; i<V; i++) {
        if(!visited[i]) {
            count++;
            dfs(i, adjList, visited);
        }
    }

    return count;
}

int main() {
    vector<vector<int>> adjMatrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << findProvinces(adjMatrix) << endl;
    return 0;
}

