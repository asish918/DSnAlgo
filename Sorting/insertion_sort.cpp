#include<iostream>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];

        int j = i - 1;
        while(j>=0){
            if(arr[j] > temp) {
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
            --j;
        }
        arr[j + 1] = temp;
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    insertionSort(arr, n);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    return  0;
}