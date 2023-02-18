#include <iostream>
#include <algorithm>
using namespace std;

int maxPoints(int arr[], int n, int k){
    int l = 0, r = n - k;
    int total = 0;

    for(int i = r; i<n; i++)
        total+=arr[i];

    int ans = total;

    while(r < n){
        total+= arr[l] - arr[r];
        ans = max(total, ans);
        r++;
        l++;
    }

    return ans;

}

int main(){
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int n = sizeof(cardPoints)/sizeof(int);

    cout << maxPoints(cardPoints, n, k);
    return 0;
}
