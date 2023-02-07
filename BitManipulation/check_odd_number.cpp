#include <iostream>
using namespace std;

int main(){
    long long num = 3;
    long long one = 1;

    bool flagOdd = (num & 1) ? true : false;

    cout << flagOdd << endl;
    return 0;
}
