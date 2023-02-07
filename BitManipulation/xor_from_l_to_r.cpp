#include <iostream>
using namespace std;

int findXOR(int n){
    int mod = n % 4;

    if(mod == 0)
        return n;
    else if(mod == 1)
        return 1;
    else if(mod == 2)
        return n + 1;
    else if(mod == 3)
        return 0;
}

int main(){
    int l = 4;
    int r = 8;

    cout << (findXOR(l - 1)^findXOR(r));

    return 0;
}
