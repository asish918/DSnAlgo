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

int main(){
    vector<int> adjList[4] = {
        {1},
        {2},
        {3},
        {3}
    };

    cout << detectCycleBFS(4, adjList) << endl;
    return 0;
}
