#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(struct Job a, Job b){
    return a.profit > b.profit;
}

void jobScheduling(Job arr[], int n){
    sort(arr, arr + n, cmp);
    int maxi = arr[0].deadline;

    for(int i = 0; i<n; i++)
        maxi = max(maxi, arr[i].deadline);

    int slot[maxi];

    for(int i = 0; i<maxi; i++)
        slot[i] = -1;

    int maxProfit = 0, jobCount = 0;

    for(int i = 0; i<n; i++){
        for(int j = arr[i].deadline-1; j>=0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                jobCount++;
                maxProfit+=arr[i].profit;
                break;
            }
        }
    }

    cout << maxProfit << " " << jobCount << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        Job arr[n];

        for(int i = 0; i<n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }

        jobScheduling(arr, n);
    }

    return 0;
}
