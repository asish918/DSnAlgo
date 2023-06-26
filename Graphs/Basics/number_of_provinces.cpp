#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adjList[], vector<int>& visited){
        visited[node] = 1;
        for(auto it : adjList[node])
            if(!visited[it])
                dfs(it, adjList, visited);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited (V, 0);
        vector<int> adjList[V];
        int count = 0;

        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};
