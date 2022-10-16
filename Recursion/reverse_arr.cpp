#include<iostream>
using namespace std;

void revArr(int* arr, int start, int end){
    if(start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
    revArr(arr, start+1, end-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    revArr(arr, 0, 4);

    for(int i = 0; i<5; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}