#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int n = 3;

    int arr2[3][3];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i = 0; i<n; i++){
        reverse(arr[i], arr[i]+n);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}