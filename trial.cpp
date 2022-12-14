#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<utility>
using namespace std;

int main(){
    int arr[4][4] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };
    int n = 4;

    for(int i = 0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}