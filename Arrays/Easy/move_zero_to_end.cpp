#include<iostream>
using namespace std;

int main(){
    int arr[] = {3, 5, 0, 0, 4};
    int zero_iterator = 0;

    for(int i = 0; i<sizeof(arr) /sizeof(int); i++){
        if(arr[i]!=0){
            int temp = arr[i];
            arr[i] = arr[zero_iterator];
            arr[zero_iterator] = temp;
            zero_iterator++;
        }
    }

    for(int j = 0; j<sizeof(arr) /sizeof(int); j++)
        cout << arr[j] << " ";

    return 0;
}