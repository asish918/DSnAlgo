#include <iostream>
using namespace std;

int main(){
    long long num = 6;
    long long one = 1;

    bool flagPower = num & (num - 1) ? false : true;

    cout << flagPower << endl;

    return 0;
}
