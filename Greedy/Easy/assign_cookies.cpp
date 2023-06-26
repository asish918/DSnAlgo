#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    int m = sizeof(g) / sizeof(int);
    int n = sizeof(s) / sizeof(int);

    sort(g, g+m);
    sort(s, s+n);

    int i = m - 1;
    int j = n - 1;

    int contentChild = 0;

    while(i >= 0 && j >= 0){
        if(s[j] >= g[i]){
            contentChild++;
            j--;
            i--;
        }
        else
            i--;
    }

    cout << contentChild << endl;

    return 0;
}
