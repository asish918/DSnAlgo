#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void eventualSafeNodes(vector<vector<int>> graph){
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

    eventualSafeNodes(graph);
    cout << endl;

    return 0;
}
