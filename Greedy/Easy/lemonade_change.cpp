#include <iostream>
using namespace std;

bool lemonadeChange(int bills[], int n){
    int fives = 0;
    int tens = 0;

    for(int i = 0; i<n; i++){
        if(bills[i] == 5)
            fives++;
        else if(bills[i] == 10){
            tens++;
            fives--;
        }
        else if(tens > 0){
            tens--;
            fives--;
        }
        else 
            fives-=3;

        if(fives < 0) return false;
    }

    return true;
}

int main() {
    int bills[] = {5, 5, 10, 10, 20};
    int n = sizeof(bills) / sizeof(int);

    cout << lemonadeChange(bills, n);

    return 0;
}
