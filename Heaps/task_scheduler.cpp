#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

int leastInterval(char tasks[], int n, int k){
    unordered_map<char, int> m;
    priority_queue<int> maxHeap;
    queue<pair<int, int> > q;

    for(int i = 0; i<n; i++)
        m[tasks[i]]++;

    for(auto i : m)
        maxHeap.push(i.second);

    int time = 0;
    
    while(!q.empty() || !maxHeap.empty()){
        time += 1;

        if(!maxHeap.empty()){
            int count = maxHeap.top() - 1;
            maxHeap.pop();
            
            if(count)
                q.push(make_pair(count, time + k));
        }

        if(!q.empty() && q.front().second == time){
            maxHeap.push(q.front().first);
            q.pop();
        }
    }

    return time;
}

int main(){
    char tasks[] = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int k = 2;
    int n = sizeof(tasks) / sizeof(char);

    cout << leastInterval(tasks, n, k);
    return 0;
}
