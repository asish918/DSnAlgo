#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

bool dfs(int node, int rang, vector<vector<int>>& graph, vector<int>& color) {
    color[node] = rang;

    for(auto adjNode : graph[node]) {
        if(color[adjNode] == -1) {
            if(dfs(adjNode, !rang, graph, color) == false)
                return false;
        }
        else if(color[adjNode] == color[node])
            return false;
    }

    return true;
}

bool bfs(int node, vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;
    q.push(0);
    color[0] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
    
        for(auto adjNode : graph[node]) {
            if(color[adjNode] == -1) {
                q.push(adjNode);
                color[adjNode] = !color[node];
            }
            else if(color[adjNode] == color[node])
                return false;
        }
    }

    return true;
}

bool bipartiteDFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    int rang = 0;

    for(int i = 0; i<n; i++) {
        if(color[i] == -1) {
            if(dfs(i, rang, graph, color) == false)
                return false;
        }
    }

    return true;
}

bool bipartiteBFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++) {
        if(color[i] == -1)
            if(bfs(i, graph, color) == false)
                return false;
    }

    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    cout << bipartiteDFS(graph) << endl;
    cout << bipartiteBFS(graph) << endl;

    return 0;
}
