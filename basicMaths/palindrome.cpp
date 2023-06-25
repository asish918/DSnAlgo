#include<iostream>
using namespace std;

int main(){
    int x = 121;

    int sum = 0;
    
    while(x > sum) {
        int digit = x % 10;
        sum = sum * 10 + digit;
        x/=10;
    }

    cout << (sum == x || sum / 10 == x);

    return 0; 
}

// 1234321
// 123432 10
// 12343 12
// 1234 123
// 123 1234
