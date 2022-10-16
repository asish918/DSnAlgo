#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1, 2, 1, 2, 1};
    int k = 3;
    int maxLen = 0;

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++){
        int sum = 0;
        for(int j = i; j<sizeof(arr)/sizeof(int); j++){
            sum+=arr[j];
            if(sum == k)
                maxLen = max(maxLen, (j - i + 1));
        }
    }

    cout << maxLen << endl;

    return 0;
}