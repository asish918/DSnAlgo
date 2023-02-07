#include <iostream>
using namespace std;

int main(){
    int num = 6;
    int unset = num;

    for(int i = 0; (1<<i)<num; i++){
        if((num&(1<<i)) == 0){
            unset = num|(1<<i);
            break;
        }
    }

    cout << unset << endl;
    return 0;
}
