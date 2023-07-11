#include <algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> topoSortBFS(vector<int> adjList[], int V) {
    int indegree[V] = {0};
    queue<int> q;
    
    for(int i = 0; i<V; i++)
        for(auto adjNode : adjList[i])
            indegree[adjNode]++;

    for(int i = 0; i<V; i++)
        if(indegree[i] == 0)
            q.push(i);

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto adjNode : adjList[node]) {
            indegree[adjNode]--;

            if(indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }

    return topo;
}

void findOrder(string dict[], int N, int K) {
    vector<int> adjList[K];

    for(int i = 0; i<N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());

        for(int index = 0; index < len; index++) {
            if(s1[index] != s2[index]) {
                adjList[s1[index] - 'a'].push_back(s2[index] - 'a');
                break;
            }
        }
    }

    vector<int> topoSort = topoSortBFS(adjList, K);
    string order = "";

    for(auto i : topoSort)
        order.push_back(char(i + 'a'));

    cout << order << endl;
}

int main() {
    int N = 5;
    int K = 4;
    string dict[N] = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };
    
    findOrder(dict, N, K);
    return 0;
}
