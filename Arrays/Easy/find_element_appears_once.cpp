#include<iostream>
using namespace std;

int main(){
    int arr[] = {2, 2, 5, 5, 20, 30, 30};
    int N = sizeof(arr) / sizeof(int);
    int element = 0;

    int i = 0;

    if(N == 1 || arr[0]!=arr[1]) {
        element = arr[0];
    }

    else {
        for(i = 1; i<N-1; i++){
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
                element = arr[i];
                break;
            }
        }
    }

    cout << element << endl;
    
    return 0;
}