#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num[] = {1, 2, 3};
    int n = sizeof(num)/sizeof(int);
    vector<int> ds;

    for(int i = 0; i < (1<<n); i++){
        ds.clear();

        for(int bits = 0; bits < n; bits++){
            if(i&(1<<bits))
                ds.push_back(num[bits]);
        }

        for(auto el : ds)
            cout << el << " ";
        cout << endl;
    }

    return 0;
}
