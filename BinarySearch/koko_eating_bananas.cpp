#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPossible(int piles[], int n, int speed, int h){
    int time = 0;
    for(int i = 0; i<n; i++){
        time += (int)ceil(piles[i]*1.0 / speed);
    }

    if(time <= h)
        return true;
    else
        return false;
}

int main(){
    int piles[] = {3, 6, 7, 11};
    int n  = sizeof(piles) / sizeof(int);
    int h = 8;

    int low = 0;
    int high = INT_MIN;
    int min_speed = -1;

    for(int i = 0; i<n; i++){
        high = max(high, piles[i]);
    }

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(isPossible(piles, n, mid, h)){
            min_speed = mid;
            high  = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << min_speed << endl;
    
    return 0;
}