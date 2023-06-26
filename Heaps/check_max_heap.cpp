#include <iostream>
using namespace std;

bool checkMax(int arr[], int n){
    for(int i = 0; i<n; i++){
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if(l<n && arr[l] > arr[i]) return false;
        if(r<n && arr[r] > arr[i]) return false;
    }

    return true;
}

int main(){
    int arr[] = {90, 15, 10, 7, 12, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << checkMax(arr, n);

    return 0;
}
