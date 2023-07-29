#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& bloomDay, int M, int K, int day) {
    int count = 0, minBouqets = 0;
    int N = bloomDay.size();

    for(int i = 0; i < N; i++) {
        if(bloomDay[i] <= day)
            count++;
        else {
            minBouqets += (count / K);
            count = 0;
        }
    }

    minBouqets += (count / K);

    return minBouqets >= M;
}

int bruteForce(vector<int>& bloomDay, int M, int K) {
    int minEl = 1e9;
    int maxEl = 0;

    int n = bloomDay.size();
    if(M * K > n) return -1;

    //M * K Total slots needed
    for(int i = 0; i < n; i++) {
        minEl = min(minEl, bloomDay[i]);
        maxEl = max(maxEl, bloomDay[i]);
    }

    for(int i = minEl; i <= maxEl; i++) {
        if(isPossible(bloomDay, M, K, i))
            return i;
    }

    return -1;
}

//Binary Search
int optimal(vector<int>& bloomDay, int M, int K) {
    int minEl = 1e9;
    int maxEl = -1e9;

    int N = bloomDay.size();

    for(int i = 0; i < N; i++) {
        minEl = min(minEl, bloomDay[i]);
        maxEl = max(maxEl, bloomDay[i]);
    }

    //M * K Total slots needed
    if(M * K > N) return -1;

    int low = minEl;
    int high = maxEl;

    while(low <= high) {
        int mid = (high - low)/2 + low;

        if(isPossible(bloomDay, M, K, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    //Low moves towards possible area and High moves towards not possible area
    //Opposite polarity hence Low will point to the first possible value and High will point to the last not possible value
    return low;
}

int main() {
    vector<int> bloomDay = {5, 5, 5, 5, 10, 5, 5};
    int M = 2;
    int K = 3;

    cout << bruteForce(bloomDay, M, K) << endl;
    cout << optimal(bloomDay, M, K) << endl;

    return 0;
}
