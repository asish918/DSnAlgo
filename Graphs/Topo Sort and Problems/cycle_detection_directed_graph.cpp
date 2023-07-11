#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool detectCycleBFS(int V, vector<int> adjList[]){
    int indegree[V] = {0};

    for(int i = 0; i<V; i++)
        for(auto adjNode : adjList[i])
            indegree[adjNode]++;

    queue<int> q;

    for(int i = 0; i<V; i++)
        if(!indegree[i])
            q.push(i);

    int count = 0;
    while(!q.empty()){
        int node = q.front();
        count++;
        q.pop();
        
        for(auto adjNode :  adjList[node]){
            indegree[adjNode]--;

            if(!indegree[adjNode])
                q.push(adjNode);
        }
    }

    return !(count == V);
}

bool dfs(int node, vector<int> adjList[], int visited[], int pathVisited[]) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto adjNode : adjList[node]) {
        if(!visited[adjNode]) {
            if(dfs(adjNode, adjList, visited, pathVisited) == true)
                return true;
        }
        else if(pathVisited[adjNode])
            return true;
    }

    pathVisited[node] = 0;
    return false;
}

bool cycleDetectionDFS(vector<int> adjList[], int V) {
    int visited[V] = {0};
    int pathVisited[V] = {0};

    for(int i = 0; i<V ; i++) {
        if(!visited[i]) {
            if(dfs(i, adjList, visited, pathVisited) == true)
                return true;
        }
    }

    return false;
}

int main(){
    vector<int> adjList[4] = {
        {1},
        {2},
        {3},
        {3}
    };

    cout << detectCycleBFS(4, adjList) << endl;
    cout << cycleDetectionDFS(adjList, 4) << endl;
    return 0;
}


/*
Can be also solved using just one visited array.
Mark visited[node] = 1 (for normal visit)
Mark visited[node] = 2 (for path visit)
Mark visit[node] = 1 (while returning back)
*/
