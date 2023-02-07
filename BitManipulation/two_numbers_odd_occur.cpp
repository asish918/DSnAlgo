#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 7, 5, 7, 5, 4, 7, 4};
    int n = sizeof(arr) / sizeof(int);

    int og_xor = 0;
    for(int i = 0; i<n; i++)
        og_xor^=arr[i];

    int count = 0;
    while(og_xor!=0){
        og_xor = og_xor&(og_xor-1);
        count++;
    }

    int xor1 = 0, xor2 = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]&(1<<count))
            xor1^=arr[i];
        else
            xor2^=arr[i];
    }

    cout << xor1 << " " << xor2 << endl;

    return 0;
}
