#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findCity(int n, vector<vector<int>> edges, int distThreshold){
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    for(auto it :  edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i = 0; i<n; i++) dist[i][i] = 0;

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9)
                    continue;
                dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
            }
        }
    }

    int cityMax = n;
    int cityNo = -1;
    
    for(int city = 0; city<n; city++){
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++){
            if(dist[city][adjCity] <= distThreshold)
                cnt++;
        }

        if(cnt <= cityMax){
            cityMax = cnt;
            cityNo = city;
        }
    }

    return cityCnt;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    
    int distThreshold = 4;
    int n = 4;
    
    cout << findCity(n, edges, distThreshold) << endl;
    return 0;
}
