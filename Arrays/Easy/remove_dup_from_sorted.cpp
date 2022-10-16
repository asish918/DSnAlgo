#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 1, 2, 3, 3, 4, 5};
    int unique_count = 0;
    int j = 0;

    for(int i = 0; i<(sizeof(arr) / sizeof(int)) - 1; i++){
        if(arr[i] == arr[i+1])
            continue;
        unique_count++;
        arr[j++] = arr[i];
    }

    ++unique_count;

    arr[j] = arr[sizeof(arr) / sizeof(int) - 1];

    cout << "Unique array - ";

    for(int k = 0; k < unique_count; k++){
        cout << arr[k] << " ";
    }

    return 0;
}