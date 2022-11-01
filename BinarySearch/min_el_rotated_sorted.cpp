#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50, 5, 7};
    int n = sizeof(arr) / sizeof(int);

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while(low<high){
        if(arr[mid] <= arr[0])
            high = mid;
        else
            low = mid + 1;

        mid = low + (high - low) / 2;
    }

    cout << arr[low] << endl;
    
    return 0;
}