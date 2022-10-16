#include<iostream>
#include<math.h>
using namespace std;

long long sumOfN(int n){
    if(n == 1){
        return 1;
    }

    // return n + sumOfN(n - 1);
    
    return pow(n, 3) + sumOfN(n - 1);  //For sum of cubes
}

int main(){
    cout << sumOfN(7) << endl;
    
    return 0;
}