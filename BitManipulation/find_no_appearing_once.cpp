//works for numbers appearing odd time as well

#include <iostream>
using namespace std;

int main(){
    int xor_of_elements = 0;
    int arr[] = {2, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i<n; i++){
        xor_of_elements^=arr[i];
    }

    cout << xor_of_elements << endl;

    return 0;
}
