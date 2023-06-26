#include <iostream>
#include <algorithm>
using namespace std;

int minPlatforms(int arr[], int dep[], int n){
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platformCount = 1;
    int ans = platformCount;
    int i = 1, j = 0;

    while(j < n && i < n){
        if(arr[i] <= dep[j]){
            platformCount++;
            i++;
        }
        else if(arr[i] > dep[j]){
            platformCount--;
            j++;
        }

        ans = max(platformCount, ans);
    }

    return ans;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(arr) / sizeof(int);

    cout << minPlatforms(arr, dep, n) << endl;

    return 0;
}
