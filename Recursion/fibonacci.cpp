#include<iostream>
using namespace std;

int fibonacci(int N){
    if(N <= 1){
        return N;
    }

    return fibonacci(N - 1) + fibonacci (N - 2);
}

int main(){
    int N = 9;
   cout << fibonacci(N);
    
    return 0;
}