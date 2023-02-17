#include <iostream>
#include <vector>
using namespace std;

vector<bool> countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2)
            return {};

        vector<bool> blackbox(n, true);
        int ans = 0;

        blackbox[0] = false;
        blackbox[1] = false;
        
        for(int i = 2; i*i<=n; i++)
            if(blackbox[i] == true){
                for(int j = i*i; j<=n; j+=i)
                    blackbox[j] = false;
            }
        
        for(int i = 2; i<n; i++)
            if(blackbox[i])
                ans++;
                
        return blackbox;
    }

int main(){
    int N = 10;

    vector<bool> ans = countPrimes(N);

    for(auto i : ans)
        cout << i << " ";

    return 0;
}
