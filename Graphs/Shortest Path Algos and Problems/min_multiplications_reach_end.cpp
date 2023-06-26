#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int minMultiplications(vector<int> arr, int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    vector<int> dist (10000, 1e9);
    dist[start] = 0;

    int mod = 10000;

    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it : arr){
            int num = (it * node) % mod;
            
            if(num == end)
                return steps + 1;

            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;

    cout << minMultiplications(arr, start, end) << endl;

    return 0;
}
