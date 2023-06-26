#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int V, vector<vector<int>> prerequisites){
    vector<int> adjList[V];

    for(auto i : prerequisites)
        adjList[i[0]].push_back(i[1]);
    
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

        for(auto adjNode : adjList[node]){
            indegree[adjNode]--;

            if(!indegree[adjNode])
                q.push(adjNode);
        }
    }

    return count == V;
}

int main(){
    vector<vector<int>> prerequisites;

    prerequisites.push_back({1, 0});
    //prerequisites.push_back({0, 1});

    cout << canFinish(2, prerequisites) << endl;

    return 0;
}
