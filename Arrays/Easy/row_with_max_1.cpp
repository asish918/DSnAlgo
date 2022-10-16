#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[4][4] = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int count = 0;
    int maxi = 0;
    int maxr = 0;

    for(int i = 0; i<4; i++){
        count = 0;
        for(int j = 0; j<4; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }
        if(count > maxi) {
            maxi = count;
            maxr = i;
        }
    }

    cout << maxr << endl;
    
    return 0;
}