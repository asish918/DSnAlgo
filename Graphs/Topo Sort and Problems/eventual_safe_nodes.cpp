#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph, int visited[], int pathVisited[]) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto adjNode : graph[node]) {
        if(!visited[adjNode]) {
            if(dfs(adjNode, graph, visited, pathVisited) == true)
                return true;
        }
        else if(pathVisited[adjNode])
            return true;
    }

    pathVisited[node] = 0;
    return false;
}

void eventualSafeNodesDFS(vector<vector<int>>& graph) {
    int V = graph.size();
    int visited[V] = {0};
    int pathVisited[V] = {0};

    for(int i = 0; i<V; i++) {
        if(!visited[i]) {
            dfs(i, graph, visited, pathVisited);
        }
    }

    for(int i = 0; i < V; i++)
        if(pathVisited[i] == 0)
            cout << i << " ";
    cout << endl;
}

void eventualSafeNodesBFS(vector<vector<int>> graph){
    int V = graph.size();

    vector<int> adjRev[V];
    int indegree[V] = {0};

    for(int i = 0; i<V; i++){
        for(auto it : graph[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for(auto it : adjRev[node]){
            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    for(auto i : safeNodes)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    eventualSafeNodesBFS(graph);
    eventualSafeNodesDFS(graph);
    cout << endl;

    return 0;
}
