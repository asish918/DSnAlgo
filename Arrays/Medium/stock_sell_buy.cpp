#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int arr[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(arr) / sizeof(int);

    int maxPro = 0;
    int minElement = INT_MAX;

    for(int i = 0; i<n; i++){
        minElement = min(minElement, arr[i]);
        maxPro = max(maxPro, arr[i] - minElement);
    }

    cout << maxPro << endl;
    
    return 0;
}