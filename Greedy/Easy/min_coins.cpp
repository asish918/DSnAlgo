#include <iostream>
#include <vector>
using namespace std;

void findMin(int V){
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(deno) / sizeof(int);

    vector<int> ans;

    for(int i = n - 1; i>=0; i--){
        while(deno[i] <= V){
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    for(auto i : ans)
        cout << i << " ";
}

int main(){
    int V = 43;

    findMin(V);

    return 0;
}
