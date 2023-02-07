#include <iostream>
using namespace std;

int main(){
    long long num = 70;
    long long i = 3;
    long long one = 1;

    i--;
    
    long long get = num & (one << i) ? 0 : 1;
    long long set = num | (one << i);
    long long clearBit = num & (~(one << i));
    
    cout << get << " " << set << " " << clearBit << endl;

    return 0;
}
