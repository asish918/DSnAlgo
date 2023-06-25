#include<iostream>
using namespace std;

int main() {
    int n = 5;
    int low = 0;
    int high = n;

    int ans = -1;

    while(low <= high) {
        int mid = (high - low)/2 + low;

        if(mid * mid == n) {
            cout << mid << endl;
            return 0;
        }
        else if(mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans << endl;

    //For Finding precision decimal
    double tempSol = ans;
    double preciseAns = tempSol;
    int precision = 3;

    double factor = 1;
    for(int i = 0; i<precision; i++) {
        factor = factor / 10;

        for(double j = preciseAns; j*j<n; j+=factor)
            preciseAns = j;
    }

    cout << "Precise Ans - " << preciseAns << endl;
    return 0;
}
