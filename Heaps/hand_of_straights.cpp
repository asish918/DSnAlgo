#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

bool isNStraightHand(int hand[], int n, int groupSize){
    if(n % groupSize != 0)
        return false;

    unordered_map<int, int> m;
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i = 0; i<n; i++)
        m[hand[i]]++;

    for(auto i : m)
        q.push(i.first);

    while(!q.empty()){
        int top = q.top();
        
        for(int i = top; i<top+groupSize; i++){
            if(m.find(i) == m.end())
                return false;

            m[i]--;
            if(m[i] == 0){
                if(i != q.top())
                    return false;
                q.pop();
            }
        }
    }

    return true;
}

int main(){
    int hand[] = {1, 2, 3, 4, 5};
    int n = sizeof(hand) / sizeof(int);
    int groupSize = 4;

    cout << isNStraightHand(hand, n, groupSize);

    return 0;
}
