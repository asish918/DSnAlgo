#include<iostream>
using namespace std;

int main(){
    int N = 1534236469;
    long long rev_number = 0; //to check int overflow

    while(N){
        int digit = N % 10;
        if(digit != 0) {
            rev_number = rev_number*10 + digit;
            if(rev_number >= INT_MAX || rev_number<=INT_MIN) //to check int overflow
                return 0;
        }

        N = N / 10;
    }

    int ans = rev_number;
    cout << ans << endl;
    
    return 0;
}