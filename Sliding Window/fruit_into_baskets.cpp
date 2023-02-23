#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxFruitsInBasket(int tree[], int n){
    int  i = 0, j = 0, ans = INT_MIN;
    unordered_map<int, int> mpp;

    while(j < n){
        if(mpp.size() <= 2)
            mpp[tree[j]] = j;
        else {
            int min_el = n - 1;
            for(auto v : mpp){
                min_el = min(min_el, v.second);
            }

            i = min_el + 1;
            mpp.erase(tree[min_el]);
        }
    
        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main(){
    int tree[] = {1, 2, 3, 2, 2};
    int n = sizeof(tree)/sizeof(int);

    cout << maxFruitsInBasket(tree, n);
    return 0;
}
