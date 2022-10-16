#include<iostream>
using namespace std;

int main(){
    int arr[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;
    
    int max = arr[0];

    for(int i = 0; i<sizeof(arr) / sizeof(int); i++){
        if(arr[i] > max)
            max = arr[i];
    }

    cout << max << endl;
    
    return 0;
}