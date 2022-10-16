#include<iostream>
#include<math.h>
using namespace std;

class Solution {
    public:
    int isPrime(int N){
        for(int i = 2; i < sqrt(N); i++){
            if(N % i == 0){
                return 0;
            }
        }

        return 1;
    }
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
}