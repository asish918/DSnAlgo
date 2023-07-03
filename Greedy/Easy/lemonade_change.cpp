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

/*
The Greedy approach works by iteratively processing each customer's bill and providing change using the available $5 and $10 bills.

We keep track of the number of $5 bills (fives) and the number of $10 bills (tens) available. Initially, both are set to 0.

For each customer:

If the bill is $5, we increment the count of fives.
If the bill is $10, we check if we have at least one $5 bill available. If we do, we decrement the count of fives and increment the count of tens. Otherwise, we cannot provide change, so we return false.

If the bill is $20, we try to provide change using a $10 bill and a $5 bill first. If we have both available, we decrement the counts of tens and fives. If not, we check if we have at least three $5 bills available. If we do, we use three $5 bills for change by decrementing the count of fives by 3. If we don't have enough $5 bills, we cannot provide change, so we return false.

If we successfully process all customers' bills without encountering any cases where we cannot provide change, we return true.
*/
