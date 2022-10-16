#include<iostream>
using namespace std;

void print1_N(int n){
    if(n == 0){
        return;
    }
    print1_N(n - 1);
    cout << n << endl;
}

int main(){
    print1_N(4);
    return 0;
}