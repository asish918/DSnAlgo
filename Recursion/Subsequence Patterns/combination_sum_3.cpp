#include <iostream>
#include <vector>
using namespace std;

void combo_sum_3(int current, int k, int size, int n, int sum, vector<int>& ds){
    if(k == 0 || current > 9){
        if(sum == n && ds.size() == size){
            for(auto i : ds)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(current);
    combo_sum_3(current + 1, k - 1, size, n, sum + current, ds);
    ds.pop_back();
    combo_sum_3(current + 1, k, size, n, sum, ds);
}

int main(){
    vector<int> ds;

    int k = 3, n = 7;

    combo_sum_3(1, k, k, n, 0, ds);

    return 0;
}
