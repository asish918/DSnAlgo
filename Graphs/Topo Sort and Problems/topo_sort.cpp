#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//Kahn's Algo
void topo_travel_bfs(int V, vector<int> adjList[]){
    int indegree[V] = {0};

    for(int i = 0; i<V; i++)
        for(auto adjNode : adjList[i])
            indegree[adjNode]++;

    queue<int> q;

    for(int i = 0; i<V; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();

        for(auto adjNode : adjList[node]){
            indegree[adjNode]--;

            if(indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
}

void topo_travel_dfs(int node, vector<int> adjList[], stack<int> &st, int vis[]){
    vis[node] = 1;

    for(auto adjNode : adjList[node]){
        if(!vis[adjNode])
            topo_travel_dfs(adjNode, adjList, st, vis);
    }

    st.push(node);
}

int main(){
    vector<int> adjList[4] = {
        {},
        {0},
        {0},
        {0}
    };

    topo_travel_bfs(4, adjList);
    //    stack<int> st;
    //   int vis[4] = {0};
    //
    //   for(int i = 0; i<4; i++)
    //      if(!vis[i])
    //         topo_travel_dfs(i, adjList, st, vis);
    //
    //   while(!st.empty()){
    //      cout << st.top() << endl;
    //     st.pop();
    //}

    return 0;
}
