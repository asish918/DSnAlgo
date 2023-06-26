#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 1, m;
    cin >> n >> m;

    //Adjacency Matrix
    //int adjMatrix[n + 1][n + 1] = {0};

    //for(int i = 0; i<m; i++){
        //int u, v;
        //cin >> u >> v;
        //adjMatrix[u][v] = 1;
        //adjMatrix[v][u] = 1;
    //}

    //Adjacency List
    vector<int> adjList[n + 1];
    for(int i = 0; i<m; i++){
        int u, v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Adjacency Matrix - " << endl;
    for(int i = 0; i<m; i++){
       int rowSize = adjList[i].size();
       for(int j = 0; j<rowSize; j++)
           cout << adjList[i][j] << " ";
       cout << endl;
    }

    return 0;;
}
