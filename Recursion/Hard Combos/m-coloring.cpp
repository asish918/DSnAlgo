#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int rang, int node, vector<vector<int>>& edges, int color[], int n) {
    for(int adj = 0; adj<n; adj++){
        if(adj != node && edges[node][adj] && color[adj] == rang)
            return false;
    }

    return true;
}

bool solve (int node, vector<vector<int>>& edges, int m, int color[], int n) {
    if(node == n)
        return true;

    for(int i = 1; i<=m; i++){
        if(isPossible(i, node, edges, color, n)) {
            color[node] = i;

            if(solve(node + 1, edges, m, color, n))
                return true;

            color[node] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {0, 2}
    };

    int n = 4;
    int m = 3;

    int *color{ new int[n]{} };
        
    cout << solve(0, edges, m, color, n);

    return 0;
}
