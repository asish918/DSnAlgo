#include <iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n!=0){
        n = n&(n-1);
        count++;
    }
    return count;
}

int main(){
    int N = 4;

    int count = 0;

    for(int i = 1; i<= N; i++)
        count+=countSetBits(i);
    
    cout << count << endl;
    
    return 0;
}
