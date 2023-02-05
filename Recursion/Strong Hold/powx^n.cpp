#include<iostream>
using namespace std;

double myPowNoob(int x, int n){
    long long nn = n;

    if(n<0) nn*=(-1);

    double ans = 1.0;

    while(nn--){
        ans*=x;
    }

    ans = (n < 0) ? 1/ans : ans;

    return ans;
}

double myPowOptimal(int x, int n){
    long long nn = n;
    if(n < 0) nn*=(-1);

    double ans = 1.0;

    while(nn){
        if(nn % 2 == 1){
            nn-=1;
            ans*=x;
        }
        else {
            nn/=2;
            x*=x;
        }
    }

    ans = (n < 0) ? (double)1/ans : ans;
    return ans;
}

double myPowRecursive(int x, int n){
    double ans = 1.0;

    if(n == 0)
        return 1.0;

    ans = myPowRecursive(x, n/2);
    ans*=ans;
    if(n%2) ans*=x;
    return ans;
}

int main(){
    int x = 2;
    int n = 3;

    //cout << myPowNoob(x, n) << endl;
    cout << myPowRecursive(x, n);
    //cout << myPowOptimal(x, n) << endl;

    return 0;
}
