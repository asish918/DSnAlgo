#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp(Item a, Item b){
    double r1  = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, int W){
    sort(arr, arr + n, cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for(int i = 0; i<n; i++){
        if(currWeight + arr[i].weight <= W){
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }

        else {
            int remain = W - currWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return finalValue;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, W;
        cin >> n >> W;

        Item arr[n];

        for(int i = 0; i<n; i++)
            cin >> arr[i].value >> arr[i].weight;

        
    cout << fractionalKnapsack(arr, n, W);
    }
    return 0;
}
