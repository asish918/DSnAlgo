#include <iostream>
using namespace std;

int main(){
    int N = 8;

    for(int i = 2; i<=N; i++){
        if(N % i == 0){
            cout << i << " ";
            while(N % i == 0)
                N/=i;
        }
    }

    return 0;
}
