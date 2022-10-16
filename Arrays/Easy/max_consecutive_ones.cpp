#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1, 1, 0, 1, 1, 1};
    int count = 0;
    int maxi = 0;

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++){
        if(arr[i] == 1)
            count++;
        else
            count = 0;
        
         maxi = max(count, maxi);
    }

    cout << maxi << endl;
}