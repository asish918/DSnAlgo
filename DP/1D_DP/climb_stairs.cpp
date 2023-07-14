#include<iostream>
#include<vector>
using namespace std;

//Exactly same as fibonacci
int recursion(int n) {
    if(n == 0 || n == 1) return 1;

    return recursion(n - 1) + recursion(n - 2);
}

int space_optmised(int n) {
    int prev2 = 1, prev = 1;
    for(int i = 2; i <= n; i++) {
        int curri = prev + prev2;
        prev2 =  prev;
        prev = curri;
    }

    return prev;
}

int main() {
    int n = 10;

    cout << space_optmised(n) << endl;
    return 0;
}
