#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

void dfs(int node, vector<int>& vis, vector<pair<int, int>> adjList[], stack<int>& st){
    vis[node] = 1;

    for(auto adjNode : adjList[node]){
        int v = adjNode.first;

        if(!vis[v])
            dfs(v, vis, adjList, st);
    }

    st.push(node);
}

void shortestPath(int N, int M, vector<vector<int>> edges){
    vector<pair<int, int>> adjList[N];

    for(int i = 0; i<M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
    }

    stack<int> st;
    vector<int> vis(N, 0);
    for(int i = 0; i<N; i++)
        if(!vis[i])
            dfs(i, vis, adjList, st);

    vector<int> dis(N, 1e9);
    dis[0] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto adjNode : adjList[node]){
            int v = adjNode.first;
            int wt = adjNode.second;

            if(dis[node] + wt < dis[v])
                dis[v] = dis[node] + wt;
        }
    }

    for(int i = 0; i<N; i++)
        cout << dis[i] << " ";
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };

    shortestPath(6, 7, edges);
    return 0;
}
