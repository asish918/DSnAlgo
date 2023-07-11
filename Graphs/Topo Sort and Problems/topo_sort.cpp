#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adjList[], int vis[], stack<int>& st) {
    vis[node] = 1;

    for(auto adjNode : adjList[node]) {
        if(!vis[adjNode])
            dfs(adjNode, adjList, vis, st);
    }

    st.push(node);
}

//Kahn's Algo
void topoSortBFS(vector<int> adjList[], int V) {
    int indegree[V] = {0};

    for(int i = 0; i < V; i++) 
        for(auto adjNode : adjList[i])
            indegree[adjNode]++;

    queue<int> q;

    for(int i = 0; i < V; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(auto adjNode : adjList[node]) {
            indegree[adjNode]--;

            if(indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    cout << endl;
}

void topoSort(vector<int> adjList[], int V) {
    stack<int> st;
    int vis[V] = {0};

    for(int i = 0; i<V; i++) {
        if(!vis[i])
            dfs(i, adjList, vis, st);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<int> adjList[V];

    adjList[2].push_back(3);

    adjList[3].push_back(1);

    adjList[4].push_back(0);
    adjList[4].push_back(1);

    adjList[5].push_back(0);
    adjList[5].push_back(2);

    topoSort(adjList, V);
    topoSortBFS(adjList, V);
    return 0;
}
