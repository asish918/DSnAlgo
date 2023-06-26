#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<int> adjList[], int V){
    int visited[V] = {0};
    queue<int> q;
    visited[0] = 1;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it : adjList[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

int main(){
    int V = 5;
    vector<int> adjList[V];

    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);

    adjList[1].push_back(0);
    
    adjList[2].push_back(0);
    adjList[2].push_back(4);

    adjList[3].push_back(0);

    adjList[4].push_back(2);

    bfs(adjList, V);

    return 0;
}
