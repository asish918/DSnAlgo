#include<iostream>
using namespace std;
#define mod 1000000007

long long pow(long long x, long long n){
    if(n == 0)
        return 1;
    
    long long ans = 1;
    ans = pow(x, n / 2);
    ans*=ans;
    if(n%2) ans*=x;

    return ans%=mod;
}

int countGood(long long n){
    long long odd = n / 2;
    long long even = n/2 + n%2;

    return (pow(4, odd) * pow(5, even))%mod;
}

int main(){
    long long n = 50;

    int ans = countGood(n);

    cout << ans << endl;

    return 0;
}
