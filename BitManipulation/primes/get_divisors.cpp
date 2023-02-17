#include <iostream>
using namespace std;

int main(){
    int N = 6;

    for(int i = 1; i*i <= N; i++)
        if(N % i == 0){
            cout << i << " ";
            if(N/i != i)
               cout << N / i << " ";
        }

    return 0;
}
