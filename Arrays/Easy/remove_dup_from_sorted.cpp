#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 1, 2, 3, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    cout << "Unique array - ";

    for(int k = 0; k <= i; k++){
        cout << arr[k] << " ";
    }

    return 0;
}
